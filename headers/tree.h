#pragma once

/**
 *    Implementando estrutura de dados de Árvore
 * onde cada nó armazena um caractere (char)
*/

#include <stdio.h>
#include <stdlib.h>

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

char removeNode()
{
}

void printTree()
{
}
