#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *root = NULL;

node *newNode(int val)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert(int val, node *tree)
{
    if (tree == NULL)
    {
        root=newNode(val);
    }
    if ((val < tree->data))
    {
        tree->left = insert(val, tree->left);
    }
    else
    {
        tree->right = insert(val, tree->right);
    }
}

node *inorderTraversal(node *tree)
{
    if (tree != NULL)
    {
        printf("bst is empty!!!");
        return;
    }
        inorderTraversal(tree->left);
        printf("\t%d\t", tree->data);
        inorderTraversal(tree->right);
}

node *preorderTraversal(node *tree)
{
    if (tree == NULL)
    {
        printf("bst is empty!!!");
        return NULL;
    }
    printf("%d", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

node *postorderTraversal(node *tree)
{
    if (tree == NULL)
    {
        printf("bst is empty!!!");
        return NULL;
    }
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("%d", tree->data);
}

node *minValueNode(node *tree)
{
    node *current = tree;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

node *deleteNode(int val, node *tree)
{
    if (tree == NULL)
    {
        printf("\nNot such value in the bst");
    }
    if ((val < tree->data))
    {
        tree->left = deleteNode(val, tree->left);
    }
    else if (val > tree->data)
    {
        tree->right = deleteNode(val, tree->right);
    }
    else
    {
        if (tree->left == NULL)
        {
            node *temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL)
        {
            node *temp = tree->left;
            free(tree);
            return temp;
        }
        node *temp = minValueNode(tree->right);
        tree->data = temp->data;
        tree->right = deleteNode(temp->data, tree->right);
    }
    return NULL;
}

node *searchNode(int val, node *tree)
{
    if (tree == NULL)
    {
        printf("\nSearch is unsuccessfull!!!");
    }
    if ((val == tree->data))
    {
        printf("\nSearch successfull");
    }
    else if (tree->data < val)
    {
        deleteNode(val, tree->right);
    }
    else
    {
        deleteNode(val, tree->left);
    }
}

int main()
{
    int ch, e = 1, op, val;
    while (e)
    {
        printf("\n BST OPERATION");
        printf("\n______________MENU______________");
        printf("\n 1.INSERT \n 2.DELETE \n 3.SEARCH \n 4.IN-ORDER TRAVERSAL \n 5.PRE-ORDER TRAVERSAL\n 6.POST-ORDER TRAVERSAL\n 7.EXIT");
        printf("\n_________________________________\n");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value to be inserted:");
            scanf("%d", &val);
            insert(val, root);
            break;
        case 2:
            printf("\nEnter the value to be deleted:");
            scanf("%d", &val);
            deleteNode(val, root);
            break;
        case 3:
            printf("\nEnter the value to be searched:");
            scanf("%d", &val);
            searchNode(val, root);
        case 4:
            printf("\nIn-order traversal of elements");
            inorderTraversal(root);
            break;
        case 5:
            printf("\npre-order traversal of elements");
            preorderTraversal(root);
            break;
        case 6:
            printf("\npost-order traversal of elements");
            postorderTraversal(root);
            break;
        case 7:
            e = 0;
            printf("\n exiting");
            break;
        default:
            printf("\n please enter valid choice\n");
            break;
        }
    }
    return 0;
}