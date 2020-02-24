#ifndef __4X8_TYPEFACE_H__
#define __4X8_TYPEFACE_H__

class 4x8_text{
	private:
		int offset_x;
		int offset_y:
	public:
		void set_offset_x(int);
		void set_offset_y(int);
		
		// void find_char(uint8_t);
		void init_display();
		void led_set_on(uint8_t x, uint8_t y);
		void led_set_off(uint8_t x, uint8_t y);
		void print_char(uint8_t char8);
		
		4x8_text();
};

#endif