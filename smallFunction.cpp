// smallFunction.cpp
// Chứa các hàm con, phục vụ cho các hàm khác

#include <iostream>
#include <cstdio>
#include "main.h"
#include "smallFunction.h"

using namespace std;


// Hàm lấy input từ console và lưu vào mảng
void getInputConsole() {
	// Cấp phát bộ nhớ cho input mới
	input_text = initArray();

	// Lấy dữ liệu từ console đến khi gặp Ctrl + Z
	int ch = getchar();
	int curr = 0;
	while (ch != EOF) {
		input_text[curr] = (char)ch;
		curr++;
		ch = getchar();
	}
	return;
}


// Hàm lấy input từ file và lưu vào mảng
void getInputFile() {
	// Cấp phát bộ nhớ cho input mới
	input_text = initArray();

	// Mở file
	FILE* input = NULL;
	input = fopen("input.txt", "r+");
	if (input == NULL) {
		cout << "    Khong the mo file! " << endl;
		return;
	}

	// Đọc dữ liệu từ bàn phím vào file cho đến khi hết file
	int ch = fgetc(input);
	int curr = 0;
	while (ch != EOF) {
		input_text[curr] = (char)ch;
		curr++;
		ch = fgetc(input);
	}

	fclose(input);
	return;
}


// Hàm cấp phát bộ nhớ cho mảng tùy vào chỉ số max_input_len
char* initArray() {
	char* new_array = new char[max_input_len];
	return new_array;
}


// Hàm căn chỉnh theo lề trái
void alignLeft() {
	// Cấp phát bộ nhớ cho mảng output
	output_text = initArray();

	int curr = 0;
	while (input_text[curr] != NULL) {
		readWord(curr);
	}
	return;
}

void readWord(int& curr) {
	// Bỏ qua khoảng trắng
	while (isspace(input_text[curr]))
		curr++;

	// Nếu đến hết mảng thì return
	if (input_text[curr] == NULL)
		return;

	// Gán độ dài từ hiện tại là 1
	int word_len = 1;
	char* word = new char[max_word_len];
	// Đọc từ đó vào biến word
	while (!isspace(input_text[curr]) && word_len <= max_word_len) {
		word[word_len-1] = input_text[curr];
		word_len++;
		curr++;
	}
	return;
}


void alignRight() {
	cout << endl
		 << " Not yet" << endl;
	
	return;
}

void alignMiddle() {
	cout << endl
		 << " Not yet" << endl;
	
	return;
}

void alignJustify() {
	cout << endl
		 << " Not yet" << endl;
	
	return;
}

void optionInputLen() {
	do {
        cin.clear();
        cout << "---Nhap so ki tu toi da cua van ban nhap vao:";
        cin >> max_input_len;
        fflush(stdin);
    } while (max_input_len <= 0);

	return;
}

void optionWordLen() {
	do {
        cin.clear();
        cout << "---Nhap so ki tu toi da cua tu:";
        cin >> max_word_len;
        fflush(stdin);
    } while (max_word_len <= 0 || max_word_len > max_input_len);

	return;
}

void optionLineLen() {
	do {
        cin.clear();
        cout << "---Nhap so ki tu cua dong:";
        cin >> max_line_len;
        fflush(stdin);
    } while (max_line_len <= 0 || max_line_len < max_word_len);

	return;
}

void outputConsole() {
	cout << endl
		 << " Not yet" << endl;
	
	return;
}

void outputFile() {
	cout << endl
		 << " Not yet" << endl;
	
	return;
}

void success() {

}


