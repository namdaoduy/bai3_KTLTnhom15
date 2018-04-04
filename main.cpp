// main.cpp
// Chứa hàm main()
// và khởi tạo các biến toàn cục

#include "menu.h"
#include <iostream>

char* input_text = NULL;
char* output_text = NULL;
int max_input_len = 2000;
int max_word_len = 20;
int max_line_len = 50;

int main() {
	while (1) {
		// Hàm hiển thị menu chọn chức năng
		displayMenu();
	}
	return 0;
}
