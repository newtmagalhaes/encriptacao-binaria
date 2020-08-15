#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/bitwise.h"

int main()
{
    printf("\nSaída: %d\n", alphabetTest());
    return 0;
}

int alphabetTest()
{
    srand(time(NULL));

    int retorno = 0;

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 1; i++)
    {

        char senha[101];
        char chave[101];
        char *saida;

        int senhaValue = rand() % 100;
        int chaveValue = rand() % 100;

        for (int j = 0; j < senhaValue; j++)
        {
            int senhaR = rand() % 53;
            printf("%d\n", senhaR);
            senha[j] = alphabet[senhaR];
        }
        for (int j = 0; j < chaveValue; j++)
        {
            int chaveR = rand() % 51;
            chave[j] = alphabet[chaveR];
        }

        int tamSenha = strlen(senha);
        int tamChave = strlen(chave);

        if (tamSenha > 0 && tamChave > 0)
        {
            saida = operation(senha, chave);
            int tamSaida = strlen(saida);

            //printf("\n%d -> %d || %d", tamSaida, tamSenha, tamChave);

            if (tamSenha != tamSaida)
            {
                //printf("\nSenha: %s\nChave: %s\nSaida: %s", senha, chave, saida);
                retorno = 1;
            }
        }
    }

    return retorno;
}