#include "utils.h"

void printToken(TokenType token, const char* tokenString) {
    switch (token) {
        case NUM:
            printf("val = %s\n", tokenString);
            break;
        case ERROR:
            printf("Token não reconhecido");
            break;
        default:
            break;
    }
}