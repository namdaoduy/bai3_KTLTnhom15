#include<iostream>
#include<cstdio>
#include"startFunction.h"
#include"menu.h"
#include"typedef.h"
#include"main.h"
using namespace std;



//hàm hiển thị các chức năng cho người dùng chọn
void displayMenu()
{
    cout<<"----------------------------------------------CHUONG TRINH CAN LE VAN BAN-----------------------------------------------"<<endl
        <<"------MENU CHUC NANG:"<<endl
        <<"                1.Nhap van ban moi"<<endl
        <<"                2.Can le van ban"<<endl
        <<"                3.Thiet lap thong so"<<endl;
        selectMenu();
}



//hàm cho người dùng chọn các chức năng chính
void selectMenu()
{
do{
        cin.clear();
        cout<<"->Chon chuc nang(1-3):";
        cin>>selection;
        fflush(stdin);
    }while(selection!=1&&selection!=2&&selection!=3);
    char inputText[20];
    inputText[0]='\0';
if(selection==2&&inputText[0]=='\0')    //Nếu văn bản chưa được nhập mà người dùng yêu câu căn lề
{
    cout<<"Chua nhap van ban,hay nhap van ban truoc!"<<endl;
    selectMenu();
    return;
}
//Thực hiện chức năng theo lựa chọn người dùng
switch (selection) {
        case 1:
            cout<<"Chon phuong thuc nhap van ban:"<<endl
            	<<"     1.Nhap tu ban phim"<<endl
            	<<"     2.Trich xuat tu file"<<endl;
            do{
        cin.clear();
        cout<<"->Chon chuc nang(1-2):";
        cin>>selection;
        fflush(stdin);
                }while(selection!=1&&selection!=2);
if(selection==1) startGetInputKB(); //hàm lấy input từ keyboard
else startGetInputFile();//hàm lấy input từ file
            break;
        case 2:
        	cout<<"Chon kieu can le:"<<endl
        		<<"		1.Can le trai:"<<endl
        		<<"		2.Can le trai phai:"<<endl
        		<<"		3.Can le giua:"<<endl;
        	do{
        cin.clear();
        cout<<"->Chon chuc nang(1-3):";
        cin>>selection;
        fflush(stdin);
    }while(selection!=1&&selection!=2&&selection!=3);
    		switch(selection){
    			case 1:
				startLeft();//hàm thực hiện chức năng căn lề trái và lưu kết quả
				printOutput();//hàm in kết quả
				break;
    			case 2:
				startLeftRight();//hàm thực hiện chức năng căn lề trái phải
				printOutput();//hàm in kết quả
				break;
    			case 3:
    			startMiddle();//hàm thực hiện chức năng căn lề giữa
    			printOutput();//hàm in kết quả
				break;
			}
            break;
        case 3:
        startOptional(maxLen,lineLen,wordLen);//hàm thay đổi thông số cài đặt
        break;}
}

