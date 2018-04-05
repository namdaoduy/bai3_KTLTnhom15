#include"Process.h"
#include "main.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
extern int outputMode;
extern FILE* fin;
extern FILE* fout;
extern FILE* text;
// Nhap 1 ky tu, phu thuoc dau vao la ban phim hay file
int GetChar() {
    return fgetc(text);
}

// Nhap 1 tu, den max_word_len thi dung
int ReadWord(char *word) {
    int ch, pos = 0;

    // Loc bo khoang trang truoc tu
    do ch = GetChar();
    while (isspace(ch));

    // Nhap tu
    while (!isspace(ch) && (ch != EOF)) {
        word[pos++] = (char)ch;
        if (pos == max_word_len)
            break;
        ch = GetChar();
    }
    word[pos] = '\0';

    return pos;
}


// Them tu vao dong
void AddWord(char *word, char *line, int &lineLen) {
    // Them khoang trang truoc tu (neu can)
    if (lineLen > 0) {
        line[lineLen++] = ' ';
        line[lineLen] = '\0';
    }

    // Them tu
    strcat(line, word);
    lineLen += strlen(word);
}
// Tao 1 dong moi
void ClearLine(char *line, int &lineLen, int &numWords) {
    line[0] = '\0';
    lineLen = 0;
    numWords = 0;
}

// Can le va in dong ra file "output.txt"
void WriteLine(char *line, int lineLen, int numWords) {
    switch (outputMode) {
        case 1: fprintf(fout, "%s\n", line); break;     // Can le trai
        case 2: Center(line, lineLen); break;           // Can le phai
        case 3: Right(line, lineLen); break;            // Can le giua
        case 4: Justify(line, lineLen, numWords); break;// Can le 2 ben
    }
}

// Can le giua
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

// Can le 2 ben
void Justify(char *line, int lineLen, int numWords) {
    if (numWords == 1) {                // Neu chi co 1 tu
        fprintf(fout, "%s\n", line);
        return;
    }

    // So khoang trang con lai
    int extraSpaces = max_line_len- lineLen;
    // So khoang trang can thiet giua hai tu
    int spacestoInsert = extraSpaces / (numWords - 1);
    // So khoang trang bu vao cho du do dai dong
    int plusSpaces = extraSpaces % (numWords - 1);

    for (int i=0; i<lineLen; i++) {
        if (line[i] != ' ') {           // in ky tu
            fputc (line[i], fout);
            continue;
        }

        PrintSpaces(spacestoInsert + 1);// in khoang trang
        if (plusSpaces > 0) {
            fputc (' ', fout);
            plusSpaces--;
        }
    }
    fputc ('\n', fout);
}

// In nhieu khoang trang
void PrintSpaces(int numSpaces) {
    while (numSpaces--)
        fputc (' ', fout);
}
