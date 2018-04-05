// smallFunction.cpp
// Chứa các hàm con, phục vụ cho các hàm khác

#include <iostream>
#include <cstdio>
#include <conio.h>
#include "main.h"
#include "smallFunction.h"

using namespace std;


// Hàm lấy input từ console và lưu vào file text.txt
void getInputConsole() {
    cout << "    Nhap van ban tu ban phim, ket thuc boi Enter + Ctrl Z: " << endl;
	int ch;
	text = fopen("text.txt", "w+");
	while ((ch=getchar()) != EOF) {
		fputc(ch, text);
	}

	// Kiểm tra văn bản có rỗng hay không
	fseek(text, 0, SEEK_SET);
	if ((ch=fgetc(text)) == EOF) 
		cout << "    Van ban trong, nhap that bai!" << endl;
    else 
		cout << endl
			 << "    Nhap van ban thanh cong! " << endl;

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
	text = fopen("text.txt", "w+");
	while ((ch=fgetc(fin)) != EOF) {
		fputc((char)ch, text);
	}

	// Kiểm tra file có rỗng hay không
	fseek(text, 0, SEEK_SET);
	if ((ch=fgetc(text)) == EOF) 
		cout << endl
			 << "    File rong, nhap that bai! " << endl;
    else 
		cout << endl
			 << "    Nhap van ban thanh cong! " << endl;

    fclose(fin);
	fclose(text);

	return;
}



// Hàm phụ thiết lập độ dài từ tối đa
void optionWordLen() {
	do {
        cin.clear();
        cout << "        Nhap so ki tu toi da cua tu: ";
        cin >> max_word_len;
        fflush(stdin);
    } while (max_word_len <= 0);

	return;
}


// Hàm phụ thiết lập độ dài dòng
void optionLineLen() {
	do {
        cin.clear();
        cout << "        Nhap so ki tu cua dong: ";
        cin >> max_line_len;
        fflush(stdin);
    } while (max_line_len <= 0 || max_line_len < max_word_len);

	return;
}



// Hàm in output ra màn hình
void outputConsole() {
	cout << "----Van ban sau khi duoc can le:" << endl;
	fout = fopen("output.txt","r");
	int ch;
	while ((ch = fgetc(fout)) != EOF) 
		putchar(ch);
	fclose(fout);

	cout << endl
		 << endl
		 << "    Press any key to continue... " << endl;
	getch();
}



// Hàm in output ra file (thông báo)
void outputFile() {
	cout << "----Ghi thanh cong ra file output.txt" << endl
		 << "----Noi dung file: " << endl;
	fout = fopen("output.txt", "r");
	int ch;
	while ((ch = fgetc(fout)) != EOF) 
		putchar(ch);
	fclose(fout);
	cout << endl
		 << endl 
		 << "    Press any key to continue... " << endl;
	getch();
}




