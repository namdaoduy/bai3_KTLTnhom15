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
    cout<<"---THONG SO HIEN TAI:"<<endl
        <<"-So ki tu nhieu nhat/tu:"<<max_word_len<<endl
        <<"-So ki tu nhieu nhat/dong:"<<max_line_len<<endl;
    cout << "--------THIET LAP THONG SO: " << endl;

    optionWordLen();
    optionLineLen();

    cout << endl
         << "    Thiet lap thanh cong! " << endl
         << "    Press any key to continue... " << endl;
    getch();

    return;
}



//Hàm thực hiên các thao tác căn lề
void startAlign() {
    cout << "    Chon kieu can le: " << endl
      	 << "		 1. Can le trai " << endl
       	 << "		 2. Can le phai " << endl
       	 << "		 3. Can le giua " << endl
         << "                 4. Can le 2 ben " << endl;
         //Chọn chế độ căn lề 1-4
    do {
        cin.clear();
        cout << endl
             << "    Chon chuc nang (1-4): ";
        cin >> outputMode;
        fflush(stdin);
    } while (outputMode < 1 || outputMode > 4);

    fout = fopen("output.txt", "w");
    text=fopen("text.txt","r");
    char word[max_word_len + 1];
    int wordLen;
    char line[max_line_len + 1];
    int lineLen = 0;
    int numWords = 0;


//Hàm xóa line
ClearLine(line, lineLen, numWords);
    for(;;) {
        wordLen = ReadWord(word);

        //Nếu hết từ
        if (wordLen == 0) {
            if (outputMode != 4)
                WriteLine(line, lineLen, numWords);
            else
                fputs (line, fout);
            break;
        }

        // Nếu từ không vừa dòng,tạo dòng mới
        if ((lineLen > 0) && (lineLen + 1 + wordLen > max_line_len)) {
            WriteLine(line, lineLen, numWords);
            ClearLine(line, lineLen, numWords);
        }

        //Nối thêm từ vào dòng
        AddWord(word, line, lineLen);
        numWords++;

    }
fclose(fout);
fclose(text);

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
