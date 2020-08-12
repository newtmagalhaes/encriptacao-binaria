#include <stdio.h>
#include <stdlib.h>

// CLI
// @param char[] Senha
// @param char[] Chave
// retorna esses valores aos seus respectivos ponteiros.
void cli(char *senha, char *chave)
{

    printf("Encriptação de senhas usando Árvore Binária!\n");
    printf("Por favor escreva os dados abaixo:\n");

    printf("Senha:");
    scanf("%s", senha);
    fflush(stdin);

    printf("Chave:");
    scanf("%s", chave);
    fflush(stdin);
    
}
