#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/bitwise.h"
#include "headers/cli.h"
#include "headers/tree.h"

int main()
{
    char senha[_PASSWORD_LIMIT] = "123654879";
    char chave[_PASSWORD_LIMIT] = "654321";
    char *xorPass;
    char *treePass;

    // Inicia o cliente de Terminal para pedir a senha e a chave
    // atualizando seus respectivos valores.
    cli(senha, chave);

    // Função que tranfere o valor alterado para o [xorPass]
    xorPass = operation(senha, chave);

    /// Printa o Valor da operação XOR
    printf("\n\nRetorno do Bitwise: %s\n", xorPass);

    // A operação da árvore
    treePass = treeOperation(xorPass);
    printf("Retorno da árvore:  %s\n", treePass);

    return 0;
}