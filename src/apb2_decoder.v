`resetall

module Gowin_APB2_Decoder #(parameter ADDR_WIDTH=8) //ADDR Width of the IP
(
  input  wire         psel_i,
  input  wire [31:0]  paddr_i,
  input  wire         penable_i,
  input  wire         pprot_i,
  input  wire         secure_i,
  input  wire         pready_i,

  output wire         psel_valid_o,     // Decoded psel to slave
  output wire         penable_valid_o,  // Decoded penable to slave
  output wire         pready_o);

wire psel_secure_decoded;
wire [11:0] paddr_decoded;
wire psel_addr_decoded;
wire psel_valid_w;
wire penable_valid_w;
wire pready_w;
wire unused = (|paddr_i[31:8]);

// Secure match -> psel_i, 0 else 1
assign psel_secure_decoded  = (!secure_i || pprot_i)? psel_i : 1'b0;

assign paddr_decoded[11:8] = 8'b0000;
assign paddr_decoded[7:0]  = paddr_i[7:0];

assign psel_addr_decoded    = (paddr_decoded[11:ADDR_WIDTH] == {12-ADDR_WIDTH{1'b0}})?
       psel_i : 1'b0;

// Secure Match and Addr covered
assign psel_valid_w         = psel_secure_decoded && psel_addr_decoded;
// Valid access to covered ADDR
assign penable_valid_w      = (psel_valid_w)? penable_i : 1'b0;
// Valid acces -> from IP, default 1 else 0
assign pready_w             = (psel_valid_w)? pready_i : 1'b1;

assign psel_valid_o         = psel_valid_w;
assign penable_valid_o      = penable_valid_w;
assign pready_o             = pready_w;

endmodule