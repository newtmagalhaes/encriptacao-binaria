#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char size[100];

void xorOperation(char char1[], char char2[], char toArray[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        toArray[i] = (char)((char1[i] ^ char2[i]) + 32);
    }
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

    if (keySize < passSize)
    {
        // Adiciona a chave à nova chave
        strcpy(newKey, chave);

        int diff = passSize - keySize;
        int rounds = diff / keySize;
        int rest = diff % keySize;

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
        for (int i = 0; i < passSize; i++)
        {
            newKey[i] = chave[i];
        }
    }
    else if (keySize == passSize)
    {
        strcpy(newKey, chave);
    }

    char *newPass;

    xorOperation(newKey, senha, newPass, tamStr(newKey));

    strcpy(size, newPass);
    return newPass;
}

int returnSize()
{
    return tamStr(size);
}