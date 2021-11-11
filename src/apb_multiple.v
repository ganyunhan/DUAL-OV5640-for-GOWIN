`resetall

module Gowin_APB2_Multiple
(
    //---------------------The Port declartion--------
    input          pclk,       // master clock input
    input          presetn,    //synchronous active low reset    
    input          psel,       //slave sel
    input          penable,    //enable
    input          pwrite,     //transmit direction
    input   [11:2] paddr,      //lower address bits
    input   [31:0] pwdata,     //write data
    output  [31:0] prdata      //read data
);

wire write_enable = psel    & pwrite    & (!penable);
wire read_enable  = psel    & (!pwrite) &   penable;

//The register of apb bus
reg [7:0 ] Multiplier;
reg [7:0 ] Multiplicand;
reg [15:0] The_result;
reg [1:0 ] Cmd_reg; //The Bit0 -> Start 
                    //The Bit1 -> The State of Multiple

//write Block
always @(posedge pclk or negedge presetn)
begin
    if(~presetn)
    begin
        Multiplier      <=  8'b0;
        Multiplicand    <=  8'b0;
    end
    else
    begin
        if(write_enable)
        begin
            case (paddr[11:2])
            10'h00: Multiplier      <= pwdata;
            10'h01: Multiplicand    <= pwdata;
            endcase
        end
    end
end

reg [31:0] prdata_out;
//Read Block
always @(*)
begin
    if (read_enable)
    begin
        case (paddr[11:2])
        10'h00:  prdata_out = Multiplier;
        10'h01:  prdata_out = Multiplicand;
        10'h02:  prdata_out = Cmd_reg;
        10'h03:  prdata_out = The_result;
        default: prdata_out = 32'hFFFFFFFF;//Indicate the unvalid state
        endcase
    end
    else
    begin
        prdata_out  = 32'hFFFFFFFF;
    end
end

assign prdata = prdata_out;

//get the status and result
wire [15:0] wire_multiple_result;
wire        cmd_finished_status;

always @(posedge pclk or negedge presetn)
begin
    if(~presetn)
    begin
        Cmd_reg       <=    2'b0;
     end
    else if(cmd_finished_status)
    begin
       Cmd_reg       <=     2'b10;
    end
    else if(write_enable & (paddr[11:2] == 10'h02))
    begin
       Cmd_reg        <=    pwdata[1:0];
    end
end

always @(posedge pclk or negedge presetn)
begin
    if(~presetn)
    begin
        The_result     <=    16'b0; 
    end
    else if(cmd_finished_status)
    begin
       The_result      <=     wire_multiple_result;
    end
end

Gowin_Multiplier multiplier_inst
(
    .CLK            (pclk        ),
    .RSTn           (presetn     ),

    .Statr_Sig      (Cmd_reg[0] & (!Cmd_reg[1]) ),
    .Multiplicand   (Multiplicand),
    .Multiplier     (Multiplier  ),

    .Done_Sig       (cmd_finished_status),
    .Product        (wire_multiple_result)
);

endmodule

module Gowin_Multiplier
(
	input	wire			CLK,
	input	wire			RSTn,
	
	input	wire			Statr_Sig,
	input	wire	[7:0]	Multiplicand,
	input	wire	[7:0]	Multiplier,
	
	output	wire			Done_Sig,
	output	wire	[15:0]	Product
);

reg [1:0] i;
reg [7:0] Mcand;
reg [7:0] Mer;
reg [15:0] Temp;
reg isNeg;
reg isDone;
	
always @(posedge CLK or negedge RSTn)
begin
	if(~RSTn)
		begin
			i <= 2'd0;
			Mcand <= 8'd0;
			Mer <= 8'd0;
			Temp <= 16'd0;
			isDone <= 1'b0;
			isNeg <= 1'b0;
		end
	else if(Statr_Sig)
		case (i)
			2'd0:
			begin
				isNeg <= Multiplicand[7] ^ Multiplier[7];//Get neg or int
				Mcand <= Multiplicand[7] ?(~Multiplicand + 1'b1):Multiplicand;
				Mer   <= Multiplier[7] ?(~Multiplier + 1'b1):Multiplier;
				Temp  <= 16'd0;
				i	  <= i + 1'b1;
			end
			2'd1:
			begin
				if(Mer == 0) 
                    i<= i + 1'b1;
				else 
					begin
                        Temp <= Temp + Mcand;
						Mer	 <= Mer  - 1'b1;
					end
			end
			2'd2:
			begin
				isDone <= 1'b1;
				i <= i + 1'b1;
			end
			2'd3:
			begin
				isDone <= 1'b0;
				i 	   <= 2'd0;
			end
		endcase
end
	
assign Done_Sig = isDone;
assign Product  = isNeg?(~Temp + 1'b1):Temp;
	
endmodule