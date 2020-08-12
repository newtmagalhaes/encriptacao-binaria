#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// Tamanho base para todas as operações incluidas da chave.
/// Tamanho da nova Senha.
int baseSize;

/// Faz a operação bitwise XOR.
/// @returns char* novaSenha
char *xorOperation(char char1[], char char2[], int tam)
{
    char *arr = malloc(100 * sizeof(char));
    // Faz a conta XOR dos dois valores
    // e adiciona 32 para serem itens visíveis na tabela ASCII
    for (int i = 0; i < tam; i++)
    {
        arr[i] = (char)((char1[i] ^ char2[i]));
        if (arr[i] <= 32)
        {
            arr[i] += 32;
        }
    }
    return arr;
}

// Tamanho da String
// @param char str[]
// @returns int strSize
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

    char newKey[passSize];

    // Essas iterações a seguir forçam a newKey ser do tamanho da senha
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

    /// Nova chave com o valor da operação
    char *newPass = xorOperation(newKey, senha, tamStr(newKey));

    // Adiciona o valor da nova senha à size, para se ter o tamanho em opções futuras.
    baseSize = tamStr(newPass);

    return newPass;
}