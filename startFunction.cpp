#include"startFunction.h"
#include"smallFunction.h"
#include"main.h"
#include<iostream>
#include<cstdio>
#include<conio.h>
using namespace std;
//hàm thay đổi thông số cài đặt
void startOptional(int &maxLen,int &lineLen,int &wordLen)
{
    cout<<"-----------THIET LAP THONG SO:"<<endl;
    do{
        cin.clear();
        cout<<"---Nhap so ki tu toi da cua van ban nhap vao:";
        cin>>maxLen;
        fflush(stdin);
        }while(maxLen<=0);
    do{
        cin.clear();
        cout<<"---Nhap so ki tu toi da cua tu:";
        cin>>wordLen;
        fflush(stdin);
        }while(wordLen<=0||wordLen>maxLen);
    do{
        cin.clear();
        cout<<"---Nhap so ki tu cua dong:";
        cin>>lineLen;
        fflush(stdin);
        }while(lineLen<=0||lineLen<wordLen);
    cout<<"Thiet lap thanh cong!"<<endl;
    cout<<"..........Press any key to continute.........."<<endl;
    getch();
}


//chưa hoàn thành!
//hàm lấy dữ liệu từ keyboard
void startGetInputKB()
{
    cout<<"This function is used to get input from keyboard"<<endl;
}


//chưa hoàn thành!
//hàm lấy dữ liệu từ file
void startGetInputFile()
{
    cout<<"This function is used to extract input from file!"<<endl;
}


//chưa hoàn thành!
//hàm xử lí căn lề trái văn bản
void startLeft()
{
	cout<<"This function is used to handle & making outputText"<<endl;
}


//chưa hoàn thành!
//hàm xử lí căn lề trái phải văn bản
void startLeftRight()
{
	cout<<"This function is used to handle & making outputText"<<endl;
}


//chưa hoàn thành!
//hàm xử lí căn giữa văn bản
void startMiddle()
{
	cout<<"This function is used to handle & making outputText"<<endl;
}


//hàm in kết quả ra màn hình hoặc file
void printOutput()
{
	cout<<"Chon phuong thuc xuat Output Text:"<<endl
		<<"		1.Xuat van ban ra man hinh"<<endl
		<<"		2.Xuat van ban ra file"<<endl;
	do{
        cin.clear();
        cout<<"->Chon chuc nang(1-2):";
        cin>>selection;
        fflush(stdin);
                }while(selection!=1&&selection!=2);
                if(selection==1) printToScreen();
                else writeToFile();
}
