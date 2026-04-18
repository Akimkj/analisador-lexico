#include "globals.h"
#include "scan.h"
#include "utils.h"

FILE *source;

int main() {
    source = fopen("input.txt", "r");
    if (source == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    TokenType t = getToken();
    int findNum = 0;

    while (t != ENDFILE && t != ERROR) {
        if (t == NUM) {
            findNum = 1;
        }
        printToken(t, tokenString);
        t = getToken();
    }
    
    if (!findNum) {
        printf("Nenhum texto casou com o padrao.");
    }

    fclose(source);
    return 0;
}