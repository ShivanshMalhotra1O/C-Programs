#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int value;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the value (0 for no node ):");
    scanf("%d", &value);

    newnode->data = value;
    if (value == 0)
    {
        return 0;
    }
    else
    {

        printf("left child of %d\n", value);
        newnode->left = create();

        printf("right child of %d\n", value);
        newnode->right = create();

        return newnode;
    }
}

void inorder(struct node *root)
{

    if (root == 0)
    {
        return;
    }
    else
    {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{

    if (root == 0)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{

    if (root == 0)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root;
    root = create();

    printf("Preorder data is : \n");
    preorder(root);
    printf("\n");
    printf("Inorder data is : \n");
    inorder(root);
    printf("\n");
    printf("Preorder data is \n");
    postorder(root);
    printf("\n");
    return 0;
}