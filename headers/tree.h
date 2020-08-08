#include <stdio.h>
#include <stdlib.h>

struct item
{
    int cod;
};
typedef struct item Item;

struct node
{
    Item item;
    struct node *leftNode;
    struct node *rigthNode;
};
typedef struct node Node;

Node *treeInitialize()
{
    return NULL;
}

Item itemCreate(int cod)
{
    Item item;
    item.cod = cod;
    return item;
}

Node *treeInsert(Node *root, Item x)
{
    if (root == NULL)
    {
        Node *aux = (Node *)malloc(sizeof(Node));
        aux->item = x;
        aux->leftNode = NULL;
        aux->rigthNode = NULL;
        return aux;
    }
    else
    {
        if (x.cod > root->item.cod)
        {
            root->rigthNode = treeInsert(root->rigthNode, x);
        }
        else
        {
            root->leftNode = treeInsert(root->leftNode, x);
        }
    }
    return root;
}

void treeFree(Node *root)
{
    if (root != NULL)
    {

        treeFree(root->leftNode);
        treeFree(root->rigthNode);
        free(root);
    }
}

void treePrint(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->item.cod);
        treePrint(root->leftNode);
        treePrint(root->rigthNode);
    }
}

Node *treeSearch(Node *root, int cod)
{

    if (root != NULL)
    {
        if (root->item.cod == cod)
            return root;
        else if (cod > root->item.cod)
            return treeSearch(root->rigthNode, cod);
        else
            return treeSearch(root->leftNode, cod);
    }
    return NULL;
}

int main()
{
    Node *root = treeInitialize();
    root = treeInsert(root, itemCreate(12));
    root = treeInsert(root, itemCreate(15));
    root = treeInsert(root, itemCreate(10));
    root = treeInsert(root, itemCreate(9));
    root = treeInsert(root, itemCreate(5));
    root = treeInsert(root, itemCreate(20));
    treePrint(root);
    printf("\n");

    treePrint(treeSearch(root, 15));

    treeFree(root);

    return 0;
}
