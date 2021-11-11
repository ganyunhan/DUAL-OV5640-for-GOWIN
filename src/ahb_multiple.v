`resetall

module Gowin_AHB_Multiple
(
	output	wire	[31:0]	AHB_HRDATA,
	output	wire			AHB_HREADY,
	output	wire	[ 1:0]	AHB_HRESP,
	input	wire	[ 1:0]  AHB_HTRANS,
	input	wire	[ 2:0]  AHB_HBURST,
	input	wire	[ 3:0]  AHB_HPROT,
	input	wire	[ 2:0]	AHB_HSIZE,
	input	wire			AHB_HWRITE,
	input	wire			AHB_HMASTLOCK,
	input	wire	[ 3:0]	AHB_HMASTER,
	input	wire	[31:0]	AHB_HADDR,
	input	wire	[31:0]  AHB_HWDATA,
	input	wire			AHB_HSEL,
	input	wire			AHB_HCLK,
	input	wire			AHB_HRESETn
);

//The AHB BUS is always ready
assign AHB_HREADY = 1'b1; //ready signal, slave to MCU master
//Response OKAY
assign AHB_HRESP  = 2'b0;//response signal, slave to MCU master

//Define Reg for AHB BUS
reg [31:0]  ahb_address;
reg 		ahb_control;
reg         ahb_sel;
reg         ahb_htrans;

always @(posedge AHB_HCLK or negedge AHB_HRESETn)
begin
	if(~AHB_HRESETn)
	begin
		ahb_address  <= 32'b0;
		ahb_control  <= 1'b0;
        ahb_sel      <= 1'b0;
        ahb_htrans   <= 1'b0;
	end
	else              //Select The AHB Device 
	begin			  //Get the Address of reg
		ahb_address  <= AHB_HADDR;
		ahb_control  <= AHB_HWRITE;
        ahb_sel      <= AHB_HSEL;
        ahb_htrans   <= AHB_HTRANS[1];
	end
end

wire write_enable = ahb_htrans & ahb_control    & ahb_sel;
wire read_enable  = ahb_htrans & (!ahb_control) & ahb_sel;

//The register of Multiple AHB bus
reg [7:0 ] Multiplier;
reg [7:0 ] Multiplicand;
reg [15:0] The_result;
reg [1:0 ] Cmd_reg; //The Bit0 -> Start 
                    //The Bit1 -> The State of Multiple

wire        cmd_finished_status ;
wire [15:0] wire_multiple_result;

//write data to AHB bus
always @(posedge AHB_HCLK or negedge AHB_HRESETn)
begin
	if(~AHB_HRESETn)
	begin
		 Multiplier   <= 8'b0;
		 Multiplicand <= 8'b0;
	end
	else if(write_enable)
	begin
		case (ahb_address[15:0])
		16'h0000: Multiplier 	<= AHB_HWDATA[7:0];
		16'h0004: Multiplicand  <= AHB_HWDATA[7:0];
		endcase
	end
end

//Status
always @(posedge AHB_HCLK or negedge AHB_HRESETn)
begin
	if(~AHB_HRESETn)
	begin
		Cmd_reg  <=  2'b0;
	end
	else if(write_enable &(ahb_address[15:0] == 16'h0008))
	begin
		Cmd_reg  <= AHB_HWDATA[1:0];
	end
	else if(cmd_finished_status)
	begin
		Cmd_reg  <=  2'b10;
	end
end

//read data to AHB bus
always @(posedge AHB_HCLK or negedge AHB_HRESETn)
begin
    if(~AHB_HRESETn)
    begin
        The_result     <=    16'b0; 
    end
    else if(cmd_finished_status)
    begin
       The_result      <=     wire_multiple_result;
    end
end

//register address
reg [31:0] ahb_rdata;

always @(*)
begin
	if(read_enable)  //read cmd
	begin
		case (ahb_address[15:0])
		32'h0000:  ahb_rdata = Multiplier;
		32'h0004:  ahb_rdata = Multiplicand;
		32'h0008:  ahb_rdata = Cmd_reg;
		32'h000C:  ahb_rdata = The_result;
		default:ahb_rdata = 32'hFFFFFFFF;
		endcase
	end
    else
    begin
        ahb_rdata = 32'hFFFFFFFF;
    end
end

assign AHB_HRDATA = ahb_rdata;

Gowin_Multiple u_multiple
(
	.CLK			(AHB_HCLK	),
	.RSTn			(AHB_HRESETn),
	
	.Statr_Sig		(Cmd_reg[0]	&(!Cmd_reg[1])),
	.Multiplicand	(Multiplicand),
	.Multiplier		(Multiplier	),
	
	.Done_Sig		(cmd_finished_status),
	.Product		(wire_multiple_result)
);

endmodule

module Gowin_Multiple
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
				if(Mer == 0) i<= i + 1'b1;
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