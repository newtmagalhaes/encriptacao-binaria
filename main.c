#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/bitwise.h"
#include "headers/cli.h"

int main()
{
    char senha[100] = "1234";
    char chave[100] = "4321";
    char xorPass[100];

    //cli(senha, chave);
    // Função que tranfere o valor alterado para o [xorPass]
    strcpy(xorPass, operation(senha, chave));

    /// Printa o Valor
    printf("\n\nRetorno da função: ");
    for (int i = 0; i < returnSize(); i++)
    {
        printf("%c - ", xorPass[i]);
    }

    // Arvore:
    // @param char[] char
    // @returns char[] encriptedChar

    return 0;
}