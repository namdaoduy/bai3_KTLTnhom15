//Chứa các hàm phục vụ việc xử lí,tính toán căn lề
#include"Process.h"
#include "main.h"
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include<string.h>
#include<iostream>

extern int outputMode;
extern FILE* fin;
extern FILE* fout;
extern FILE* text;



//Nhập kí tự
int GetChar() {
    return fgetc(text);
}



// Hàm lấy 1 từ,nếu đủ số kí tự thì cắt ra
int ReadWord(char *word) {
    int ch, pos = 0;

    //bỏ qua các khoảng trắng phía trước
    do {ch = GetChar();}
    while (isspace(ch));

    // Nhập từ
    while (!isspace(ch) && (ch != EOF)) {
        word[pos++] = (char)ch;
        if (pos == max_word_len)
            break;
        ch = GetChar();
    }
    word[pos] = '\0';
    return pos;
}



// Hàm nối từ vào dòng
void AddWord(char *word, char *line, int &lineLen) {
    // Them khoang trang truoc tu (neu can)
    if (lineLen > 0) {
        line[lineLen++] = ' ';
        line[lineLen] = '\0';
    }

    // Thêm từ
    strcat(line, word);
    lineLen += strlen(word);
}



// Tao 1 dong moi
void ClearLine(char *line, int &lineLen, int &numWords) {
    line[0] = '\0';
    lineLen = 0;
    numWords = 0;
}



// Căn lề theo các mode,ghi output ra file "output.txt"
void WriteLine(char *line, int lineLen, int numWords) {
    switch (outputMode) {
        case 1: fprintf(fout, "%s\n", line); break;     // Can le trai
        case 2: Right(line, lineLen); break;            // Can le phai
        case 3: Center(line, lineLen); break;            // Can le giua
        case 4: Justify(line, lineLen, numWords); break;// Can le 2 ben
    }
}



// Hàm căn giữa
void Center(char *line, int lineLen) {
    int extraSpaces = max_line_len - lineLen;
    PrintSpaces(extraSpaces / 2);
    fprintf(fout, "%s\n", line);
}



// Can le phai
void Right(char *line, int lineLen) {
    int extraSpaces = max_line_len - lineLen;
    PrintSpaces(extraSpaces);
    fprintf(fout, "%s\n", line);
}



// Hàm căn lề trái phải
void Justify(char *line, int lineLen, int numWords) {
    if (numWords == 1) {                // Neu chi co 1 tu
        fprintf(fout, "%s\n", line);
        return;
    }

    // Tính số khoảng trắng còn lại
    int extraSpaces = max_line_len- lineLen;
    // Số khoảng trắng cần thiết giữa 2 từ
    int spacestoInsert = extraSpaces / (numWords - 1);
    // Số khoảng trắng bù
    int plusSpaces = extraSpaces % (numWords - 1);

    for (int i=0; i<lineLen; i++) {
        if (line[i] != ' ') {           // in kí tự
            fputc (line[i], fout);
            continue;
        }

        PrintSpaces(spacestoInsert + 1);// in khoảng trắng
        if (plusSpaces > 0) {
            fputc (' ', fout);
            plusSpaces--;
        }
    }
    fputc ('\n', fout);
}



// Hàm in 1 số cho trước các khoảng trắng
void PrintSpaces(int numSpaces) {
    while (numSpaces--)
        fputc (' ', fout);
}
