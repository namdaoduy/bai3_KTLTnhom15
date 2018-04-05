// main.cpp
// Chứa hàm main()
// và khởi tạo các biến toàn cục

#include "menu.h"
#include <iostream>
#include <cstdio>


// Khởi tạo các biến toàn cục
int outputMode = 1;
FILE* fin = NULL; // Con trỏ tới file đầu vào
FILE* fout = NULL; // Con trỏ tới file đầu ra
FILE* text = NULL; // Con trỏ tới file đệm văn bản
int max_word_len = 20;
int max_line_len = 50;


int main() {
    // Xóa dữ liệu trên file text.txt
    text = fopen("text.txt", "w");
    fputc(26, text);
    fclose(text);

    // Hàm hiển thị menu chọn chức năng
	while (1) {
		displayMenu();
	}

    // Kết thúc chương trình
	return 0;
}
