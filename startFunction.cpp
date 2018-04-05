// startFunction.cpp
// Chứa các hàm bắt đầu việc thực hiện các chức năng chính

#include "startFunction.h"
#include "smallFunction.h"
#include "Process.h"
#include "main.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
extern FILE* fin;
extern FILE* fout;
extern FILE* text;



using namespace std;


void startGetInput() {
    cout << "--------NHAP VAN BAN " << endl
         << "    Chon phuong thuc nhap van ban: " << endl
         << "        1. Nhap tu ban phim" << endl
       	 << "        2. Trich xuat tu file " << endl;

    int selection = 0;
    do {
        cin.clear();
        cout << "    Chon chuc nang (1-2): ";
        cin >> selection;
        fflush(stdin);
    }
    while (selection!=1 && selection!=2);

    if (selection == 1)
        getInputConsole(); // Hàm lấy input từ console
    else
        getInputFile(); // Hàm lấy input từ file

    return;
}


// Hàm thay đổi thông số cài đặt
void startOptional() {
    cout << "--------THIET LAP THONG SO: " << endl;

    optionWordLen();
    optionLineLen();

    cout << endl
         << "    Thiet lap thanh cong! " << endl
         << "    Press any key to continue... " << endl;
    getch();

    return;
}


void startAlign() {
    cout << "    Chon kieu can le: " << endl
      	 << "		 1. Can le trai " << endl
       	 << "		 2. Can le phai " << endl
       	 << "		 3. Can le giua " << endl
       	 << "                 4. Can le 2 ben " << endl;
    do {
        cin.clear();
        cout << endl
             << "    Chon chuc nang (1-4): ";
        cin >> outputMode;
        fflush(stdin);
    } while (outputMode < 1 || outputMode > 4);

    char word[max_word_len + 1];
    int wordLen;
    char line[max_line_len + 1];
    int lineLen = 0;
    int numWords = 0;



ClearLine(line, lineLen, numWords);
    for(;;) {
        wordLen = ReadWord(word);

        // Da nhap het tu
        if (wordLen == 0) {
            if (outputMode != 4)
                WriteLine(line, lineLen, numWords);
            else
                fputs (line, fout);
            break;
        }

        // Tu khong vua dong hien tai, tao dong moi
        if ((lineLen > 0) && (lineLen + 1 + wordLen > max_line_len)) {
            WriteLine(line, lineLen, numWords);
            ClearLine(line, lineLen, numWords);
        }

        // Them tu vao dong
        AddWord(word, line, lineLen);
        numWords++;
    }


    return;
}


// Hàm in kết quả ra màn hình hoặc file
void output() {
	cout << "   Chon phuong thuc xuat output Text:" << endl
		 << "		1. Xuat van ban ra man hinh" << endl
		 << "		2. Xuat van ban ra file" << endl;

    int selection = 0;
	do {
        cin.clear();
        cout << " -> Chon chuc nang(1-2):";
        cin >> selection;
        fflush(stdin);
    } while (selection!=1 && selection!=2);

    if(selection == 1)
        outputConsole();
    else
        outputFile();

    return;
}
