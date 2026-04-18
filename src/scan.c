#include "scan.h"

static char lastChar;
char tokenString[MAXTOKENLEN + 1];


int getNextChar() {
    lastChar = fgetc(source);
    return lastChar;
}

void ungetNextChar() {
    ungetc(lastChar, source);
}

TokenType getToken() {
    int tokenStringIndex = 0;
    int c;
    int current_state = 0;

    while (current_state != 5) {
        c = getNextChar();

        switch (current_state) {
            case 0:
                if (isdigit(c)) {
                    tokenString[tokenStringIndex++] = (char)c;
                    current_state = 2;
                } else if (c == '-') {
                    tokenString[tokenStringIndex++] = (char)c;
                    current_state = 1;
                } else if (c == EOF) {
                    return ENDFILE;
                } else {
                    tokenStringIndex = 0;
                }
                break;
            case 1:
                if (isdigit(c)) {
                    tokenString[tokenStringIndex++] = (char)c;
                    current_state = 2;
                } else {
                    return ERROR;
                }
                break;
            case 2:
                if (isdigit(c)) {
                    if (tokenStringIndex < MAXTOKENLEN) {
                        tokenString[tokenStringIndex++] = (char)c;
                    } else {
                        return ERROR;
                    }
                } else if (c == ',') {
                    if (tokenStringIndex < MAXTOKENLEN) {
                        tokenString[tokenStringIndex++] = (char)c;
                        current_state = 3;
                    } else {
                        return ERROR;
                    }
                } else {
                    ungetNextChar();
                    current_state = 5;
                }
                break;
            case 3:
                if (isdigit(c)) {
                    if (tokenStringIndex < MAXTOKENLEN) {
                        tokenString[tokenStringIndex++] = (char)c;
                        current_state = 4;
                    } else {
                        return ERROR;
                    }
                } else {
                    return ERROR;
                }
                break;
            case 4:
                if (isdigit(c)) {
                    if (tokenStringIndex < MAXTOKENLEN) {
                        tokenString[tokenStringIndex++] = (char)c;
                    } else {
                        return ERROR;
                    }
                } else {
                    ungetNextChar();
                    current_state = 5;
                }
                break;
        }
    }

    tokenString[tokenStringIndex] = '\0';
    return NUM;
}

