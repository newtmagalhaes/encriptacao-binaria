#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/bitwise.h"

int main()
{
    // CLI:
    // @returns char[] Senha, char[] Chave

    // Operação Bitwise:
    // @param char[] Senha, char[] Chave
    // @returns char[] bitwiseChar
    char senha[100] = "12345678901234567890123456";
    char chave[100] = "123456";
    char a[100];
    strcpy(a, operation(senha, chave));
    printf("\n\nRetorno da função: %s\n", a);

    // Arvore:
    // @param char[] char
    // @returns char[] encriptedChar

    return 0;
}