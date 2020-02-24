#include "4x8_typeface.h"

void 4x8_text::set_offset_x(int x){
	offset_x = x;
}
void 4x8_text::set_offset_y(int x){
	offset_y = x;
}
// void 4x8_text::find_char();

void 4x8_text::init_display(){
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(A0, OUTPUT);
	pinMode(A1, OUTPUT);
	pinMode(A2, OUTPUT);
	pinMode(A3, OUTPUT);
}
void 4x8_text::led_set(uint8_t x, uint8_t y){
	
}

void 4x8_text::print_char(uint8_t char8){
	bool 4x8_char[4][8] = {0};
	switch(char8){
		case 0x20:	// Space
			for(int x=0; x<4; x++){
				for(int y=0; y<8; y++){
					4x8_char[x][y] = 0;
				}
			}
			break;
		case 0x21	// !
			break;
		case 0x22	// "
			break;
		case 0x23	// #
			break;
		case 0x24	// $
			break;
		case 0x25	// %
			break;
		case 0x26	// &
			break;
		case 0x27	// '
			break;
		case 0x28	// (
			break;
		case 0x29	// )
			break;
		case 0x2A	// *
			break;
		case 0x2B	// +
			break;
		case 0x2C	// ,
			break;
		case 0x2D	// -
			break;
		case 0x2E	// .
			break;
		case 0x2F	// /
			break;
		case 0x30	// 0
			for(int i=0; i<3; i++){
				4x8_char[i][0] = 1;
				4x8_char[i][1] = 1;
				4x8_char[i][5] = 1;
				4x8_char[i][6] = 1;
			}
			4x8_char[0][2] = 1;
			4x8_char[0][3] = 1;
			4x8_char[0][4] = 1;
			4x8_char[2][2] = 1;
			4x8_char[2][3] = 1;
			4x8_char[2][4] = 1;
			break;
		case 0x31	// 1
			4x8_char[0][1] = 1;
			4x8_char[0][6] = 1;
			4x8_char[1][6] = 1;
			4x8_char[2][6] = 1;
			for(int i=0; i<7; i++){
				4x8_char[1][i] = 1;
			}
			break;
		case 0x32	// 2
			break;
		case 0x33	// 3
			break;
		case 0x34	// 4
			break;
		case 0x35	// 5
			break;
		case 0x36	// 6
			break;
		case 0x37	// 7
			break;
		case 0x38	// 8
			break;
		case 0x39	// 9
			break;
		case 0x3A	// :
			break;
		case 0x3B	// ;
			break;
		case 0x3C	// <
			break;
		case 0x3D	// =
			break;
		case 0x3E	// >
			break;
		case 0x3F	// ?
			break;
		case 0x40	// @
			break;
		case 0x41	// A
			break;
		case 0x42	// B
			break;
		case 0x43	// C
			break;
		case 0x44	// D
			break;
		case 0x45	// E
			break;
		case 0x46	// F
			break;
		case 0x47	// G
			break;
		case 0x48	// H
			break;
		case 0x49	// I
			break;
		case 0x4A	// J
			break;
		case 0x4B	// K
			break;
		case 0x4C	// L
			break;
		case 0x4D	// M
			break;
		case 0x4E	// N
			break;
		case 0x4F	// O
			break;
		case 0x50	// P
			break;
		case 0x51	// Q
			break;
		case 0x52	// R
			break;
		case 0x53	// S
			break;
		case 0x54	// T
			break;
		case 0x55	// U
			break;
		case 0x56	// V
			break;
		case 0x57	// W
			break;
		case 0x58	// X
			break;
		case 0x59	// Y
			break;
		case 0x5A	// Z
			break;
		case 0x5B	// [
			break;
		case 0x5C	// \
			break;
		case 0x5D	// ]
			break;
		case 0x5E	// ^
			break;
		case 0x5F	// _
			break;
		case 0x60	// `
			break;
		case 0x61	// a
			break;
		case 0x62	// b
			break;
		case 0x63	// c
			break;
		case 0x64	// d
			break;
		case 0x65	// e
			break;
		case 0x66	// f
			break;
		case 0x67	// g
			break;
		case 0x68	// h
			break;
		case 0x69	// i
			break;
		case 0x6A	// j
			break;
		case 0x6B	// k
			break;
		case 0x6C	// l
			break;
		case 0x6D	// m
			break;
		case 0x6E	// n
			break;
		case 0x6F	// o
			break;
		case 0x70	// p
			break;
		case 0x71	// q
			break;
		case 0x72	// r
			break;
		case 0x73	// s
			break;
		case 0x74	// t
			break;
		case 0x75	// u
			break;
		case 0x76	// v
			break;
		case 0x77	// w
			break;
		case 0x78	// x
			break;
		case 0x79	// y
			break;
		case 0x7A	// z
			break;
		case 0x7B	// {
			break;
		case 0x7C	// |
			break;
		case 0x7D	// }
			break;
		case 0x7E	// ~
			break;
		default:
			break;
	}
}


4x8_text::4x8_text(){
	offset_y = 0;
	offset_x = 0;
}