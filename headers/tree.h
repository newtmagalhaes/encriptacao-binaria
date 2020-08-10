#pragma once

/**
 *    Implementando estrutura de dados de Árvore
 * onde cada nó armazena um caractere (char)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *leftNode, *rightNode;
    char data;
} Tree;

Tree * createNode()
{
    Tree *newNode = NULL;
    do
    {
        newNode = (Tree *)malloc(sizeof(Tree));
    } while (newNode == NULL);

    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    newNode->data = '\0';

    return newNode;
}

Tree ** getNextNodeArr(Tree *nodeArr[], unsigned nodeArrLength)
{
    Tree **nextNodeArr = (Tree **)realloc(NULL, 2 * nodeArrLength * sizeof(Tree));

    for (int i = 0; i < 2*nodeArrLength; i++)
    {
        if (i % 2 == 0)
        {
            nextNodeArr[i] = nodeArr[i/2] != NULL ? nodeArr[i/2]->leftNode : NULL;
        }
        else
        {
            nextNodeArr[i] = nodeArr[i/2] != NULL ? nodeArr[i/2]->rightNode : NULL;
        }
    }

    return nextNodeArr;
}

// Verifica se dado um array de (Tree *) há pelo menos 1 ponteiro diferente de NULL
int isCurrNodeArrNotNull(Tree *nodeArr[], unsigned nodeArrLength)
{
    for (int i = 0; i < nodeArrLength; i++)
    {
        if (nodeArr[i] != NULL)
        {
            return 1;
        }
    }
    return 0;
}

void freeNodeArr(Tree *nodeArr[], unsigned nodeArrLength)
{
    for (int i = 0; i < nodeArrLength; i++)
    {
        nodeArr[i] = NULL;
    }
    free(nodeArr);
}

void printNodeArr(Tree *nodeArr[], unsigned nodeArrLength)
{
    for (int i = 0; i < nodeArrLength; i++)
    {
        if (nodeArr[i] == NULL)
        {
            printf("\t#");
        }
        else
        {
            printf("\t%c", nodeArr[i]->data);
        }
    }
    printf("\n");
}

void printTree(Tree *root)
{
    if (root == NULL)
    {
        printf("There's no Tree to print!");
    }
    else
    {
        unsigned currLength = 1;
        Tree **currNodeArr = (Tree **)realloc(NULL, currLength * sizeof(Tree *));
        currNodeArr[0] = root;

        Tree **nextNodeArr = getNextNodeArr(currNodeArr, currLength);

        printf("Tree start!\n");
        do
        {
            printNodeArr(currNodeArr, currLength);
            freeNodeArr(currNodeArr, currLength);

            currLength *= 2;

            currNodeArr = nextNodeArr;
            nextNodeArr = getNextNodeArr(currNodeArr, currLength);
        } while (isCurrNodeArrNotNull(currNodeArr, currLength));
        printf("Tree end!\n");
    }
}

void binaryInsert(Tree *root, char insertData)
{
    if (root->data == '\0')
    {
        root->data = insertData;
    }
    else
    {
        if (insertData <= root->data)
        {
            if (root->leftNode == NULL)
            {
                root->leftNode = createNode();
            }
            binaryInsert(root->leftNode, insertData);
        }
        else
        {
            if (root->rightNode == NULL)
            {
                root->rightNode = createNode();
            }
            binaryInsert(root->rightNode, insertData);
        }
    }
}

char *getCharArrFromNodeArr(Tree *nodeArr[], unsigned nodeArrLength)
{
    unsigned charArrLength = (nodeArrLength + 1) * sizeof(char);
    char *charArr = NULL;

    do
    {
        charArr = (char *)malloc(charArrLength);
    } while (charArr == NULL);

    for (int i = 0; i < nodeArrLength; i++)
    {
        charArr[i] = nodeArr[i] != NULL? nodeArr[i]->data : '#';
    }
    charArr[nodeArrLength] = '\0';

    return charArr;
}

char *getTreeInStr(Tree *root)
{
    if (root == NULL)
    {
        printf("There's no Tree to get str!");
        return NULL;
    }
    else
    {
        unsigned newStrLength = 1, currLength = 1;
        char *str = (char *)calloc(1, sizeof(char)),
            *currCharArr = (char *)calloc(1, sizeof(char));


        Tree **currNodeArr = (Tree **)realloc(NULL, currLength * sizeof(Tree));
        currNodeArr[0] = root;

        Tree **nextNodeArr = getNextNodeArr(currNodeArr, currLength);

        do
        {
            currCharArr = getCharArrFromNodeArr(currNodeArr, currLength);

            newStrLength += currLength;
            str = (char *)realloc(str, newStrLength);
            strcat(str, currCharArr);

            free(currCharArr);
            freeNodeArr(currNodeArr, currLength);

            currLength *= 2;
            currNodeArr = nextNodeArr;
            nextNodeArr = getNextNodeArr(currNodeArr, currLength);
        } while (isCurrNodeArrNotNull(currNodeArr, currLength));

        return str;
    }
}
