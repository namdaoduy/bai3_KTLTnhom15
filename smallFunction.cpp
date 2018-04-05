// smallFunction.cpp
// Chứa các hàm con, phục vụ cho các hàm khác

#include <iostream>
#include <cstdio>
#include "main.h"
#include "smallFunction.h"
extern FILE* fin;
extern FILE* fout;
extern FILE* text;
using namespace std;


// Hàm lấy input từ console và lưu vào file text.txt
void getInputConsole() {
	int ch;
	text = fopen("text.txt", "w");
	while ((ch=getchar()) != EOF) {
		fputc(ch,text);
	}
	fclose(text);
	return;
}


// Hàm lấy input từ file và lưu vào file text.txt
void getInputFile() {
	// Mở file
	fin = fopen("input.txt", "r");
	if (fin == NULL) {
		cout << "    Khong the mo file! " << endl;
		return;
	}

	// Đọc dữ liệu từ file vào input cho đến khi hết file
	int ch;
	text=fopen("text.txt","w");
	while ((ch=fgetc(fin)) != EOF) {
		fputc((char)ch,text);
	}

	fclose(fin);
	fclose(text);
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
void outputConsole()
{
    cout<<"hi!";
}
void outputFile()
{

cout<<"hello!";
}




