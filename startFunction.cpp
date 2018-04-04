// startFunction.cpp
// Chứa các hàm bắt đầu việc thực hiện các chức năng chính

#include "startFunction.h"
#include "smallFunction.h"
#include "main.h"
#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;


void startGetInput() {
    cout << "--------NHAP VAN BAN " << endl
         << "    Chon phuong thuc nhap van ban: " << endl
         << "        1. Nhap tu ban phim " << endl
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

    optionInputLen();
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
         << "        4. Can le 2 ben " << endl;

    int selection = 0;
    do {
        cin.clear();
        cout << endl
             << "    Chon chuc nang (1-4): ";
        cin >> selection;
        fflush(stdin);
    } while (selection < 1 || selection > 4);

    switch (selection) {
      case 1:
		alignLeft(); // căn lề trái
	    output(); // in kết quả
		break;
	  case 2:
		alignRight(); // căn lề phải
	    output(); // in kết quả
		break;
      case 3:
    	alignMiddle(); // căn lề giữa
        output(); // in kết quả
		break;
      case 4:
        alignJustify(); // căn lề đều
        output(); // in kết quả
        break;
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
