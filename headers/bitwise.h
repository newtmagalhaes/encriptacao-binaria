#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *operation(char senha[], char chave[])
{
    int passSize = tamStr(senha);

    int keySize = tamStr(chave);

    char newKey[100];

    printf("Tamanho da Senha: %d", passSize);

    if (keySize < passSize)
    {
        // Adiciona a chave à nova chave
        strcpy(newKey, chave);

        int diff = passSize - keySize;
        int rounds = diff / keySize;
        int rest = diff % keySize;

        printf("\nRounds: %d, Rest: %d", rounds, rest);

        for (int i = 0; i < rounds; i++)
        {
            strcat(newKey, chave);
        }

        int tempKeySize = keySize + (keySize * rounds);
        for (int i = 0; i < rest; i++)
        {
            newKey[tempKeySize] = chave[i];
            tempKeySize++;
        }
        printf("\nChave: %s", chave);
        printf("\nNova Chave: %s, Tamanho: %d", newKey, tamStr(newKey));
    }
    else if (keySize > passSize)
    {
        for (int i = 0; i < passSize; i++)
        {
            newKey[i] = chave[i];
        }
    }
    return senha;
}

int tamStr(char str[])
{
    int size = 0;
    while (str[size] != '\0')
    {
        size++;
    }
    return size;
}