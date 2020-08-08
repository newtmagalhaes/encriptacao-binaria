#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char size[100];

void xorOperation(char char1[], char char2[], char *charArray[], int tam)
{
    char array[100];
    for (int i = 0; i < tam; i++)
    {
        char aux = (char)((char)(char1[i]) ^ (char)(char2[i]));
        array[i] = aux;
    }

    strcpy(charArray, array);
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

// Operação Bitwise:
// @param char[] Senha 
// @param char[] Chave
// @returns char[] bitwiseChar
char *operation(char senha[], char chave[])
{
    int passSize = tamStr(senha);

    int keySize = tamStr(chave);

    char newKey[100];

    printf("Tamanho da Senha: %d", passSize);

    if (keySize < passSize)
    {
        printf("\nCriando nova chave...");
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
    }
    else if (keySize > passSize)
    {
        printf("\nCriando nova chave...");
        for (int i = 0; i < passSize; i++)
        {
            newKey[i] = chave[i];
        }
    }
    else if (keySize == passSize)
    {
        strcpy(newKey, chave);
    }

    printf("\nChave: %s", chave);
    printf("\nNova Chave: %s, Tamanho: %d\n", newKey, tamStr(newKey));

    char newPass[100];

    xorOperation(newKey, senha, newPass, tamStr(newKey));

    strcpy(senha, newPass);
    strcpy(size, newPass);

    return senha;
}

int returnSize()
{
    return tamStr(size);
}