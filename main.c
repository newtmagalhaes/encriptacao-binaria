#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/bitwise.h"

int main()
{
    char senha[100] = "abra";
    char chave[100] = "baui";
    char a[100];

    // CLI:
    // @returns char[] Senha, char[] Chave
    
    strcpy(a, operation(senha, chave));
    printf("\n\nRetorno da função: ");
    for (int i = 0; i < returnSize(); i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    // Arvore:
    // @param char[] char
    // @returns char[] encriptedChar

    return 0;
}