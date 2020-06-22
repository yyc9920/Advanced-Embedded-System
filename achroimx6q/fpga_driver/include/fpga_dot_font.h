#ifndef __FPGA_DOT_FONT__
#define __FPGA_DOT_FONT__

unsigned char fpga_number[10][10] = {
	{0x3e,0x7f,0x63,0x73,0x73,0x6f,0x67,0x63,0x7f,0x3e}, // 0	
	{0x0c,0x1c,0x1c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x1e}, // 1	
	{0x7e,0x7f,0x03,0x03,0x3f,0x7e,0x60,0x60,0x7f,0x7f}, // 2	
	{0xfe,0x7f,0x03,0x03,0x7f,0x7f,0x03,0x03,0x7f,0x7e}, // 3	
	{0x66,0x66,0x66,0x66,0x66,0x66,0x7f,0x7f,0x06,0x06}, // 4	
	{0x7f,0x7f,0x60,0x60,0x7e,0x7f,0x03,0x03,0x7f,0x7e}, // 5	
	{0x60,0x60,0x60,0x60,0x7e,0x7f,0x63,0x63,0x7f,0x3e}, // 6	
	{0x7f,0x7f,0x63,0x63,0x03,0x03,0x03,0x03,0x03,0x03}, // 7	
	{0x3e,0x7f,0x63,0x63,0x7f,0x7f,0x63,0x63,0x7f,0x3e}, // 8	
	{0x3e,0x7f,0x63,0x63,0x7f,0x3f,0x03,0x03,0x03,0x03}  // 9
};
/*
unsigned char fpga_number[10][10] = {
	{0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 00
	{0x00000000,
	 0x00000001,
	 0x01111111,
	 0x00100001,
	 0x00000000,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 01	
	{0x00111001,
	 0x01000101,
	 0x01000101,
	 0x00100011,
	 0x00000000,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 02	
	{0x00110110,
	 0x01001101,
	 0x01001001,
	 0x01001001,
	 0x00000000,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 03	
	{0x00001000,
	 0x01111111,
	 0x00101000,
	 0x00011000,
	 0x00000000,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 04	
	{0x01001111,
	 0x01001001,
	 0x01001001,
	 0x01111001,
	 0x00000000,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 05	
	{0x01001111,
	 0x01001001,
	 0x01001001,
	 0x01111111,
	 0x00000000,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 06	
	{0x01100000,
	 0x01010000,
	 0x01001111,
	 0x01000000,
	 0x00000000,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 07	
	{0x00110110,
	 0x01101011,
	 0x01001001,
	 0x01101011,
	 0x00110110,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}, // 08	
	{0x01111111,
	 0x01010001,
	 0x01010001,
	 0x01110001,
	 0x00000000,/////////////
	 0x00111110,
	 0x01100011,
	 0x01000001,
	 0x01100011,
	 0x00111110}  // 09
};
*/
unsigned char fpga_set_full[10] = { 	// memset(array,0x7e,sizeof(array));	
	0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f
};
unsigned char fpga_set_blank[10] = {	// memset(array,0x00,sizeof(array));	
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
#endif

