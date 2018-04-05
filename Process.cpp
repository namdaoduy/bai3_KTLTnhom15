// process.cpp
// Chứa các hàm phục vụ việc xử lí,tính toán căn lề
#include "process.h"
#include "main.h"
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>


// Nhập kí tự
int getChar() {
    return fgetc(text);
}


// Hàm lấy 1 từ vào tham số word, nếu đủ số kí tự thì cắt ra
int readWord(char *word) {
    // Biến lưu ký tự hiện tại và vị trí
    int ch, pos = 0;

    // Bỏ qua các khoảng trắng phía trước
    do {
        ch = getChar();
    } while (isspace(ch));

    // Nhập từ
    while (!isspace(ch) && (ch != EOF)) {
        word[pos++] = (char)ch;
        if (pos == max_word_len)
            break;
        ch = getChar();
    }
    word[pos] = '\0';
    return pos;
}



// Hàm nối từ vào dòng
void addWord(char *word, char *line, int &lineLen) {
    // Thêm khoảng trắng vào trước từ
    if (lineLen > 0) {
        line[lineLen++] = ' ';
        line[lineLen] = '\0';
    }

    // Thêm từ
    strcat(line, word);
    lineLen += strlen(word);
}



// Tao 1 dong moi
void clearLine(char *line, int &lineLen, int &numWords) {
    line[0] = '\0';
    lineLen = 0;
    numWords = 0;
}



// Căn lề theo các mode, ghi output ra file "output.txt"
void writeLine(char *line, int lineLen, int numWords) {
    switch (outputMode) {
      case 1: 
        fprintf(fout, "%s\n", line); 
        break;
      case 2: 
        right(line, lineLen); 
        break;
      case 3: 
        center(line, lineLen); 
        break;
      case 4: 
        justify(line, lineLen, numWords); 
        break;
    }
}



// Hàm căn giữa
void center(char *line, int lineLen) {
    int extraSpaces = max_line_len - lineLen;
    printSpaces(extraSpaces / 2);
    fprintf(fout, "%s\n", line);
}



// Hàm căn phải
void right(char *line, int lineLen) {
    int extraSpaces = max_line_len - lineLen;
    printSpaces(extraSpaces);
    fprintf(fout, "%s\n", line);
}



// Hàm căn lề trái phải
void justify(char *line, int lineLen, int numWords) {
    // Nếu có 1 từ duy nhất
    if (numWords == 1) {
        fprintf(fout, "%s\n", line);
        return;
    }

    // Tính số khoảng trắng còn lại
    int extraSpaces = max_line_len - lineLen;
    // Số khoảng trắng cần thiết giữa 2 từ
    int spacestoInsert = extraSpaces / (numWords - 1);
    // Số khoảng trắng bù
    int plusSpaces = extraSpaces % (numWords - 1);

    // In ký tự
    for (int i=0; i<lineLen; i++) {
        if (line[i] != ' ') {
            fputc (line[i], fout);
            continue;
        }
        
        // in khoảng trắng
        printSpaces(spacestoInsert + 1);
        if (plusSpaces > 0) {
            fputc (' ', fout);
            plusSpaces--;
        }
    }
    fputc ('\n', fout);
}



// Hàm in 1 số cho trước các khoảng trắng
void printSpaces(int numSpaces) {
    while (numSpaces--)
        fputc (' ', fout);
}
