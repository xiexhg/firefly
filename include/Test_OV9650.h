#ifndef _SMDK2440_OV7620_H_
#define _SMDK2440_OV7620_H_

#define CHIP_DELAY 0xFF

#define BUSHI_DEF 0

static struct ov7620_t {
	int subaddr;
	int value;
} ov7620_reg[] = {
	{0x12, 0x80},	// Camera Soft reset. Self cleared after reset.
	{CHIP_DELAY, 10},
	{0x00, 0x00},	// 
	{0x01, 0x80},	// set blue gain
	{0x02, 0x80},	// set red gain
#ifdef BUSHI_DEF
	{0x03, 0x80},	// saturation control
#else
	{0x03, 0xb0},	// saturation control
#endif
//	{0x06, 0x60},	// set brightness - CJH
	{0x06, 0x80},	// set brightness - SW.LEE
//	{0x0c, 0x24},	// set white balance blue background
	{0x0c, 0x20},	// set white balance blue background - SW.LEE
//	{0x0d, 0x24},	// set white balance red background
	{0x0d, 0x20},	// set white balance red background  - SW.LEE
	{0x10, 0xff},	// set auto exposure time, brightness control - CJH
	{0x11, (1<<7)+(0<<6)+(0x0)}, // HSYNC positive, CHSYNC negative, VSYNC posigive, 16 Bit : PCLK = CLK_in/((1+x)*2), 8 Bit : PCLK = CLK_in/(1+x)
	{0x12, 0x34},	// mirror image, enable AGC/AWB, precise A/D black level compensation
	{0x13, (0x1<<5)+(0x0<<4)+(0x1)},  // 8bit Data, CCIR601 Format
	{0x15, 0x01},	// Use PCLK rising edge to latch data, UV data output: 16 Bit - UVUV..., 8 Bit - UYVY...
	{0x16, 0x03},	// Field mode : 00-OFF mode, 01-ODD mode, 10-EVEN mode, 11-FRAME mode 
	{0x17, 0x2f}, //47
	{0x18, 0xcf}, // (207-47)*4=640	
	{0x19, 0x06}, // 6
	{0x1a, 0xf5}, // (245-6+1)*2=480
	{0x1b, 0x00},	// Pixel Shift
	{0x20, 0x00},	// limit vertical size to 480, second stage aperture correction enable
	{0x21, 0x80},	// Y Channel Offset Adjustment - 0 , direction - Subtract
	{0x22, 0x80},	// U Channel Offset Adjustment - 0
	{0x23, 0x00},	// Crystal Current control : maximum current
#ifdef BUSHI_DEF
	{0x24, 0x10},	// white pixel ratio,
	{0x25, 0x8a},	// black pixel ratio,
#endif
	{0x26, 0xa2},	// Digital sharpness threshold, magnitude.
#ifndef BUSHI_DEF
	{0x27, 0xea},	// Disable CCIR rang clip
#else
	{0x27, 0xe2},	// Disable CCIR rang clip
#endif
	{0x29, 0x00},	// 
	{0x2a, 0x00},	// frame rate high, 60Hz, 50Hz:0x80, UV delay 2 pixel. - CJH
	{0x2b, 0x00},	// frame rate low, 60Hz, 50Hz:0xac
	{0x2c, 0x88},	// 
#ifdef BUSHI_DEF
	{0x2d, 0x91},	// 
#endif
	{0x2e, 0x80},	// 
#ifndef BUSHI_DEF
	{0x2f, 0x44},	// 
#endif
	{0x60, 0x27},	// 
	{0x61, 0x82},	// 02?x.........................................
#ifndef BUSHI_DEF
	{0x62, 0x5f},	// 
#else
	{0x62, 0x5e},	// 
#endif
#ifndef BUSHI_DEF
	{0x63, 0xd5},	// 
#endif
	{0x64, 0x57},	// Enable Y Gamma
#ifndef BUSHI_DEF
	{0x65, 0x83},	// 
#else
	{0x65, 0x43},	// 
#endif
	{0x66, 0x55},	// 
#ifdef BUSHI_DEF
	{0x67, 0x9a},	// 
#endif
#ifndef BUSHI_DEF
	{0x68, 0xcf},	// 
#else
	{0x68, 0xcc},	// 
#endif
	{0x69, 0x76},	// 
	{0x6a, 0x22},	// 
#ifndef BUSHI_DEF
	{0x6b, 0x00},	// 
	{0x6c, 0x08},	// 
	{0x6d, 0x48},	// 
	{0x6e, 0x80},	// 
#endif
#ifndef BUSHI_DEF
	{0x6f, 0x0c},	// -CJH
#else
	{0x6f, 0x3c},	// -CJH
#endif
	{0x70, 0x89},	// -CJH
	{0x71, 0x00},	//  freerun PCLK
	{0x72, 0x14},	// 
	{0x73, 0x54},	// 
	{0x75, 0x0e},	// -CJH
	{0x76, 0x00},	// 
#ifndef BUSHI_DEF
	{0x77, 0xff},	// 
	{0x78, 0x80},	// 
	{0x79, 0x80},	// 
	{0x7a, 0x80},	// 
	{0x7b, 0xe6},	// -CJH
#endif
	{0x7c, 0x00},	// 
#ifndef BUSHI_DEF
	{0x14, 0x94},	// turn off GAMMA - CJH
#else
	{0x14, 0x14},	// turn off GAMMA - CJH
#endif
	{0x24, 0x10},	// -CJH
	{0x25, 0x8a},	// -CJH
	{0x28, 0x20},	// Progressive mode.
	{0x2d, 0x95},	//
	{0x67, 0x92},	// 
	{0x74, 0x00},	// -CJH
};

#define OV7620_REGS (sizeof(ov7620_reg)/sizeof(ov7620_reg[0]))

static struct ov7620_t ov9650_reg[] = 
{
	{0x12, 0x80},	// Camera Soft reset. Self cleared after reset.
	{CHIP_DELAY, 10},
/*	{0x00, 0x00},	// 
	{0x01, 0x80},	// set blue gain
	{0x02, 0x80},	// set red gain
	{0x03, 0x00},	// saturation control	???
	//--- hzh
	//{0x04, 0x43},	// CCIR656 format, AEC low 2 LSB = 3
	{0x04, 0x03},	// CCIR601 format, AEC low 2 LSB = 3
//	{0x09, 0x03},	// output drive = 4x, default is 2x
	{0x10, 0xff},	// AEC[9:2] = 0xff
	{0x11, 0x40},	// PCLK use input clock directly
	//{0x11, 0x00},	// PCLK = input clock/2
	{0x12, 0x40},	// VGA
	{0x17, 0x10},	// hstart, 128, 128>>3 = 16
	{0x18, 0x60},	// hstop, 768, 768>>3 = 96
	{0x19, 0x20},	// vstart, 256, 256/8 = 32
	{0x1a, 0x5c},	// vstop, , 736/8 = 92
	//{0x1a, 0x3e},	// vstop, , 736/8 = 92
	{0x32, 0x00},
//	{0x0c, 0x40},
//	{0x3a, 0x18},
//	{0x67, 0x00},
//	{0x68, 0xff},
//	{0x40, 0xd0},
	{0x15, 0x10},	// PCLK reverse
	//---
*/
#if 0
		//{0x12, 0x80}, 
		{0x39, 0x43}, {0x38, 0x12}, {0x37, 0x00}, {0x0e, 0x20},
		{0x1e, 0x0c}, {0x01, 0x80}, {0x02, 0x80}, {0x00, 0x00}, {0x10, 0xf0},
		{0x04, 0x00}, {0x0c, 0x00}, {0x0d, 0x00}, {0x11, 0x80}, {0x12, 0x00},
		{0x14, 0x2e}, {0x15, 0x00}, {0x18, 0x60}, {0x17, 0x10}, {0x32, 0xbf}, 
		{0x03, 0x12}, {0x1a, 0x5c}, {0x19, 0x20}, {0x3f, 0xa6}, {0x41, 0x02},
		{0x42, 0x08}, {0x1b, 0x00}, {0x16, 0x06}, {0x33, 0xc0}, {0x34, 0xbf},
//{0xa8, 0x80}, //???
{0x96, 0x04}, 
{0x3a, 0x00}, 
{0x8e, 0x00}, 
{0x3c, 0x77}, 
		{0x8b, 0x06}, {0x35, 0x91}, {0x94, 0x88}, {0x95, 0x88}, {0x40, 0xc1}, 
		{0x29, 0x3f}, {0x0f, 0x42}, {0x13, 0xe5}, {0x3d, 0x92}, {0x69, 0x80}, 
		{0x5c, 0x96}, {0x5d, 0x96}, {0x5e, 0x10}, {0x59, 0xeb}, {0x5a, 0x9c},
		{0x5b, 0x55}, {0x43, 0xf0}, {0x44, 0x10}, {0x45, 0x55}, {0x46, 0x86},
		{0x47, 0x64}, {0x48, 0x86}, {0x5f, 0xe0}, {0x60, 0x8c}, {0x61, 0x20},
		{0xa5, 0xd9}, {0xa4, 0x74}, {0x8d, 0x02}, {0x13, 0xe7}, {0x4f, 0x3a}, 
		{0x50, 0x3d}, {0x51, 0x03}, {0x52, 0x12}, {0x53, 0x26}, {0x54, 0x38},
		{0x55, 0x40}, {0x56, 0x40}, {0x57, 0x40}, {0x58, 0x0d}, {0x8c, 0x23},
		{0x3e, 0x02}, {0xa9, 0xb8}, {0xaa, 0x92}, {0xab, 0x0a}, {0x8f, 0xdf},
		{0x90, 0x00}, {0x91, 0x00}, {0x9f, 0x00}, {0x3a, 0x0c}, {0x24, 0x70},
		{0x25, 0x64}, {0x26, 0xc3}, {0x2a, 0x12}, {0x2b, 0x46}, {0x3b, 0x19},
		{0x6c, 0x40}, {0x6d, 0x30}, {0x6e, 0x4b}, {0x6f, 0x60},  
		{0x70, 0x70}, {0x71, 0x70}, {0x72, 0x70}, {0x73, 0x70},
		{0x74, 0x60}, {0x75, 0x60}, {0x76, 0x50}, {0x77, 0x48},
		{0x78, 0x3a}, {0x79, 0x2e}, {0x7a, 0x28}, {0x7b, 0x22},
		{0x7c, 0x04}, {0x7d, 0x07}, {0x7e, 0x10}, {0x7f, 0x28},
		{0x80, 0x36}, {0x81, 0x44}, {0x82, 0x52}, {0x83, 0x60},
		{0x84, 0x6c}, {0x85, 0x78}, {0x86, 0x8c}, {0x87, 0x9e},
		{0x88, 0xbb}, {0x89, 0xd2}, {0x8a, 0xe6},
		{0x6a, 0x41}, {0x66, 0x00},
		{0x3e, 0x00}, {0x3f, 0xa4},
		
		{0x3a, 0x00},	//UYVY is suitable!
		{0x67, 0x55}, 	//0x67->U(RGB 1st lower),
		{0x68, 0xaa},	//0x68->V(RGB 2nd lower),
		//{0x0c, 0x40},	//MSB and LSB swap
		//{0x12, 0x40},	//VGA
        {0x12, 0x44},	//VGA and RGB format
		{0x40, 0xd1},	//RGB565
		{0x11, 0x80},	//set PCLK as high as input clock
		//{0x11, 0x00},	//set PCLK as high as half of input clock
		{0x15, 0x10},	//PCLK reverse
		//{0x8d, 0x12},
#else
//change 0x11[0x81->0x80], 0x15[0x02->0x10], hzh
//{0x12,0x80},
{0x11,0x80},{0x6a,0x3e},{0x3b,0x09},{0x13,0xe0},{0x01,0x80},{0x02,0x80},{0x00,0x00},{0x10,0x00},
{0x13,0xe5},{0x39,0x43},{0x38,0x12},{0x37,0x00},{0x35,0x91},{0x0e,0xa0},{0x1e,0x04},{0xA8,0x80},
{0x12,0x40},{0x04,0x00},{0x0c,0x04},{0x0d,0x80},{0x18,0xc6},{0x17,0x26},{0x32,0xad},{0x03,0x00},
{0x1a,0x3d},{0x19,0x01},{0x3f,0xa6},{0x14,0x2e},{0x15,0x10},{0x41,0x02},{0x42,0x08},{0x1b,0x00},
{0x16,0x06},{0x33,0xe2},{0x34,0xbf},{0x96,0x04},{0x3a,0x00},{0x8e,0x00},{0x3c,0x77},{0x8B,0x06},
{0x94,0x88},{0x95,0x88},{0x40,0xc1},{0x29,0x3f},{0x0f,0x42},{0x3d,0x92},{0x69,0x40},{0x5C,0xb9},
{0x5D,0x96},{0x5E,0x10},{0x59,0xc0},{0x5A,0xaf},{0x5B,0x55},{0x43,0xf0},{0x44,0x10},{0x45,0x68},
{0x46,0x96},{0x47,0x60},{0x48,0x80},{0x5F,0xe0},{0x60,0x8c},{0x61,0x20},{0xa5,0xd9},{0xa4,0x74},
{0x8d,0x02},{0x13,0xe7},{0x4f,0x3a},{0x50,0x3d},{0x51,0x03},{0x52,0x12},{0x53,0x26},{0x54,0x38},
{0x55,0x40},{0x56,0x40},{0x57,0x40},{0x58,0x0d},{0x8C,0x23},{0x3E,0x02},{0xa9,0xb8},{0xaa,0x92},
{0xab,0x0a},{0x8f,0xdf},{0x90,0x00},{0x91,0x00},{0x9f,0x00},{0xa0,0x00},{0x3A,0x01},{0x24,0x70},
{0x25,0x64},{0x26,0xc3},{0x2a,0x00},{0x2b,0x00},{0x6c,0x40},{0x6d,0x30},{0x6e,0x4b},{0x6f,0x60},
{0x70,0x70},{0x71,0x70},{0x72,0x70},{0x73,0x70},{0x74,0x60},{0x75,0x60},{0x76,0x50},{0x77,0x48},
{0x78,0x3a},{0x79,0x2e},{0x7a,0x28},{0x7b,0x22},{0x7c,0x04},{0x7d,0x07},{0x7e,0x10},{0x7f,0x28},
{0x80,0x36},{0x81,0x44},{0x82,0x52},{0x83,0x60},{0x84,0x6c},{0x85,0x78},{0x86,0x8c},{0x87,0x9e},
{0x88,0xbb},{0x89,0xd2},{0x8a,0xe6},
	//{0x15, 0x12},	// PCLK reverse
#endif
};

#define OV9650_REGS (sizeof(ov9650_reg)/sizeof(ov9650_reg[0]))


#endif /* _SMDK2440_OV7620_H_ */
