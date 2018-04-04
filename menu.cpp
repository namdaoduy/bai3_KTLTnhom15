// menu.cpp
// Các hàm có chức năng hiện thị
// và lựa chọn menu chức năng chính

#include <iostream>
#include <cstdio>
#include "startFunction.h"
#include "smallFunction.h"
#include "menu.h"
#include "main.h"

using namespace std;


// Hàm hiển thị các chức năng cho người dùng chọn
void displayMenu() {
    cout << "-------------------------------------------------------------------------" << endl
         << "                       CHUONG TRINH CAN LE VAN BAN                       " << endl
         << "--------MENU CHUC NANG: " << endl
         << "        1. Nhap van ban moi " << endl
         << "        2. Thiet lap thong so " << endl
         << "        3. Can le van ban va in ket qua " << endl;
        selectMenu();
}



// Hàm cho người dùng chọn các chức năng chính
void selectMenu() {
    int selection = 0;

    // Cho người dùng lựa chọn chức năng
    do {
        cin.clear();
        cout << endl
             << "    Chon chuc nang (1-3): ";
        cin >> selection;
        fflush(stdin);
    }
    while (selection!=1 && selection!=2 && selection!=3);

    // Nếu văn bản chưa được nhập mà người dùng yêu câu căn lề
    if (selection==2 && input_text == NULL) {
        cout << "    Chua nhap van ban, hay nhap van ban truoc! " << endl;
        selectMenu();
        return;
    }

    //Thực hiện chức năng theo lựa chọn người dùng
    switch (selection) {
      case 1:
        startGetInput();
        break;
      case 2:
        startOptional();
        break;
      case 3:
        startAlign();
        break;
    }

    return;
}

