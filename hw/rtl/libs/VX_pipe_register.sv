// Copyright © 2019-2023
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

`include "VX_platform.vh"

`TRACING_OFF
module VX_pipe_register #(
    parameter DATAW  = 1,
    parameter RESETW = 0,
    parameter [`UP(RESETW)-1:0] INIT_VALUE = {`UP(RESETW){1'b0}},
    parameter DEPTH  = 1
) (
    input wire              clk,
    input wire              reset,
    input wire              enable,
    input wire [DATAW-1:0]  data_in,
    output wire [DATAW-1:0] data_out
);
    if (DEPTH == 0) begin : g_passthru
        `UNUSED_VAR (clk)
        `UNUSED_VAR (reset)
        `UNUSED_VAR (enable)
        assign data_out = data_in;
    end else if (DEPTH == 1) begin : g_depth1
        if (RESETW == 0) begin : g_no_reset
            `UNUSED_VAR (reset)
            reg [DATAW-1:0] value;

            always @(posedge clk) begin
                if (enable) begin
                    value <= data_in;
                end
            end
            assign data_out = value;
        end else if (RESETW < DATAW) begin : g_partial_reset
            reg [DATAW-RESETW-1:0] value_d;
            reg [RESETW-1:0]       value_r;

            always @(posedge clk) begin
                if (reset) begin
                    value_r <= INIT_VALUE;
                end else if (enable) begin
                    value_r <= data_in[DATAW-1:DATAW-RESETW];
                end
            end

            always @(posedge clk) begin
                if (enable) begin
                    value_d <= data_in[DATAW-RESETW-1:0];
                end
            end
            assign data_out = {value_r, value_d};
        end else begin : g_full_reset
            reg [DATAW-1:0] value;

            always @(posedge clk) begin
                if (reset) begin
                    value <= INIT_VALUE;
                end else if (enable) begin
                    value <= data_in;
                end
            end
            assign data_out = value;
        end
    end else begin : g_recursive
        wire [DEPTH:0][DATAW-1:0] data_delayed;
        assign data_delayed[0] = data_in;

        for (genvar i = 1; i <= DEPTH; ++i) begin : g_pipe_reg
            VX_pipe_register #(
                .DATAW  (DATAW),
                .RESETW (RESETW),
                .INIT_VALUE (INIT_VALUE)
            ) pipe_reg (
                .clk      (clk),
                .reset    (reset),
                .enable   (enable),
                .data_in  (data_delayed[i-1]),
                .data_out (data_delayed[i])
            );
        end
        assign data_out = data_delayed[DEPTH];
    end

endmodule
`TRACING_ON
