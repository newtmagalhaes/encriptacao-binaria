#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/bitwise.h"
#include "headers/cli.h"

int main()
{
    char senha[100] = "1234";
    char chave[100] = "4321";
    char *xorPass;

    //cli(senha, chave);
    // Função que tranfere o valor alterado para o [xorPass]
    xorPass = operation(senha, chave);

    /// Printa o Valor
    printf("\n\nRetorno da função: %s\n", xorPass);

    // Arvore:
    // @param char[] char
    // @returns char[] encriptedChar

    return 0;
}