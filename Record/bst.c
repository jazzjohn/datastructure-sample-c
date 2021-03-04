#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;



node *createNode(int val)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node *findNode(node *temp, node *tree)
{
    if ((temp->data > tree->data) && (tree->right == NULL))
    {
        tree->right = temp;
    }
    else if ((temp->data > tree->data) && (tree->right != NULL))
    {
        tree->right=findNode(temp, tree->right);
    }
    else if ((temp->data < tree->data) && (tree->left == NULL))
    {
        tree->left = temp;
    }
    else if ((temp->data < tree->data) && (tree->left != NULL))
    {
        tree->left=findNode(temp, tree->left);
    }
    
}

node *insert(int val, node *tree)
{
    node *temp=createNode(val);
    if (tree == NULL)
    {
        tree=temp;
    }
    else
    {
        findNode(temp,tree);
    }
}

node *inorderTraversal(node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if(tree->left!=NULL)
        inorderTraversal(tree->left);
    printf("\t%d\t", tree->data);
    if(tree->right!=NULL)
        inorderTraversal(tree->right);
}

node *preorderTraversal(node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    printf("\t%d\t", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

node *postorderTraversal(node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("\t%d\t", tree->data);
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
        // if((tree->left==NULL)&&(tree->right==NULL))
        // {
        //     node *temp= tree;
        //     tree==NULL;
        //     return temp;
        // }
        if ((tree->left == NULL))
        {
            node *temp = tree->right;
            tree == NULL;
            return temp;
        }
        else if ((tree->right == NULL))
        {
            node *temp = tree->left;
            tree == NULL;
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
        searchNode(val, tree->right);
    }
    else
    {
        searchNode(val, tree->left);
    }
}

int main()
{
    int ch, e = 1, op, val;
    node *root = NULL;
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
            root = insert(val, root);
            break;
        case 2:
            printf("\nEnter the value to be deleted:");
            scanf("%d", &val);
            deleteNode(val, root);
            printf("one value  is deleted");
            break;
        case 3:
            printf("\nEnter the value to be searched:");
            scanf("%d", &val);
            searchNode(val, root);
            break;
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