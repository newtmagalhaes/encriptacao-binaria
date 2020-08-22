#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/bitwise.h"
#include "../headers/tree.h"

// Chave de teste para saveFile/LoadFile
#define TEST_KEY "Chavedeteste"
// Valor máximo para testes em saveFile/LoadFile
#define MAX_SAVED_VALUES 100

// Struct para salvar os valores da senha + outputs
struct PasswordOutput
{
    char *password;
    char *output;
};
typedef struct PasswordOutput PassOutput;

/// Declara as funções a serem usadas.
int time();
void saveOutputFile();
void readOutputFiles();

int main()
{
    /// Salva os valores e tenta novamente com as mesmas
    /// senhas e mesma chave para ver se vem o mesmo valor
    saveOutputFile();
    //readOutputFiles();
    return 0;
}

// Salva os arquivos gerados aleatoriamente.
void saveOutputFile()
{
    printf("\nComeçou:\n");
    srand(time(NULL));

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    PassOutput outputsToSave[MAX_SAVED_VALUES];

    int counter = 0;

    for (int i = 0; i < MAX_SAVED_VALUES; i++)
    {
        char senha[101];

        int senhaValue = rand() % 100;

        char *saida;
        char *saidaTree;

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

        saidaTree = treeOperation(saida);

        strcpy(outputsToSave[counter].password, senha);
        strcpy(outputsToSave[counter].output, saidaTree);

        printf("\nSenha: %s", outputsToSave[counter].password);
        printf("\nRegular output: %s", saida);
        printf("\nTree Output: %s", outputsToSave[counter].output);

        counter++;
    }
    printf("\nFinal\n");

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
        char *saidaTree = treeOperation(saida);

        for (int j = 0; j < strlen(saida); j++)
        {
            if (saidaTree[j] != passOutput[i].output[j])
            {
                printf("\nSenha: %s\nSaída2: %s\nOutput: %s\n",
                       passOutput[i].password,
                       saidaTree,
                       passOutput[i].output);

                errors++;
                break;
            }
        }

        free(saida);
        free(saidaTree);
    }
    printf("Errors: %d", errors);
}