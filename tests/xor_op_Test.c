#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/bitwise.h"
// Chave de teste para saveFile/LoadFile
#define TEST_KEY "Chavedeteste"
// Valor máximo para testes em saveFile/LoadFile
#define MAX_SAVED_VALUES 350

// Struct para salvar os valores da senha + outputs
struct PasswordOutput
{
    char password[_PASSWORD_LIMIT];
    char output[_PASSWORD_LIMIT];
};
typedef struct PasswordOutput PassOutput;

/// Declara as funções a serem usadas.
int xorOutputSizeTest();
int time();
void saveOutputFile();
void readOutputFiles();

int main()
{
    /// Testa se os valores vem de tamanhos iguais.
    // printf("\nErrors: %d\n", xorOutputSizeTest());

    /// Salva os valores e tenta novamente com as mesmas
    /// senhas e mesma chave para ver se vem o mesmo valor
    saveOutputFile();
    readOutputFiles();
    return 0;
}

// Faz o teste de tamanho dos outputs em relação a entrada (senha)
int xorOutputSizeTest()
{
    srand(time(NULL));

    int retorno = 0;

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char numbers[] = "123456";

    for (int i = 0; i < 1000; i++)
    {

        char senha[101];
        char chave[101];
        char *saida;

        int senhaValue = rand() % 100;
        int chaveValue = rand() % 100;

        for (int j = 0; j < senhaValue; j++)
        {
            /// Alfabeto:
            int senhaR = rand() % 53;
            senha[j] = alphabet[senhaR];

            /// Números:
            // int r = rand() % 7;
            // senha[j] = numbers[r];
        }

        for (int k = 0; k < chaveValue; k++)
        {
            /// Alfabeto:
            int chaveR = rand() % 53;
            chave[k] = alphabet[chaveR];

            /// Números:
            // int r = rand() % 7;
            // chave[k] = numbers[r];
        }

        int tamSenha = strlen(senha);
        int tamChave = strlen(chave);

        if (tamSenha > 0 && tamChave > 0)
        {
            saida = operation(senha, chave);
            int tamSaida = strlen(saida);

            printf("\nSenha: %s\nChave: %s\nSaida: %s", senha, chave, saida);

            if (tamSenha != tamSaida)
            {
                // Adiciona um erro caso o valor da saída seja menor que o valor da entrada.
                retorno++;
            }
        }
    }

    return retorno;
}

// Salva os arquivos gerados aleatoriamente.
void saveOutputFile()
{
    srand(time(NULL));

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    PassOutput outputsToSave[MAX_SAVED_VALUES];

    int counter = 0;

    for (int i = 0; i < MAX_SAVED_VALUES; i++)
    {
        char senha[101];

        char *saida;

        int senhaValue = rand() % 100;

        for (int j = 0; j < senhaValue; j++)
        {
            /// Alfabeto:
            int senhaR = rand() % 53;
            senha[j] = alphabet[senhaR];
        }

        int tamSenha = strlen(senha);

        if (tamSenha <= 0)
        {
            senha[0] = 'a';
        }

        saida = operation(senha, TEST_KEY);
        strcpy(outputsToSave[counter].password, senha);
        strcpy(outputsToSave[counter].output, saida);
        counter++;
    }

    FILE *fileptr = fopen("savedOutputs.bin", "wb");
    fwrite(outputsToSave, sizeof(PassOutput), MAX_SAVED_VALUES, fileptr);
    fclose(fileptr);
}

// Carrega os arquivos salvos.
void readOutputFiles()
{
    FILE *fileptr = fopen("savedOutputs.bin", "rb");

    PassOutput passOutput[MAX_SAVED_VALUES];
    fread(passOutput, sizeof(PassOutput), MAX_SAVED_VALUES, fileptr);
    fclose(fileptr);

    int errors = 0;

    for (int i = 0; i < MAX_SAVED_VALUES; i++)
    {

        char *saida = operation(passOutput[i].password, TEST_KEY);

        for (int j = 0; j < strlen(saida); j++)
        {
            if (saida[j] != passOutput[i].output[j])
            {
                printf("\nSenha: %s\nSaída2: %s\nOutput: %s\n",
                       passOutput[i].password,
                       saida,
                       passOutput[i].output);

                errors++;
                break;
            }
        }
    }
    printf("Errors: %d", errors);
}