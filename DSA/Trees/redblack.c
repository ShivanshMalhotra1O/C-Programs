// C program for Red-Black Tree insertion
#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    char color;
    struct node *left, *right, *parent;
};

// Left Rotation
void LeftRotate(struct node **root, struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;
}

// Right Rotation (Similar to LeftRotate)
void rightRotate(struct node **root, struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;
}

// Utility function to fixup the Red-Black tree after standard BST insertion
void insertFixUp(struct node **root, struct node *z)
{
    // iterate until z is not the root and z's parent color is red
    while (z != *root && z != (*root)->left && z != (*root)->right && z->parent->color == 'R')
    {
        struct node *y;

        // Find uncle and store uncle in y
        if (z->parent && z->parent->parent && z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;

        // If uncle is RED, do following
        // (i)  Change color of parent and uncle as BLACK
        // (ii) Change color of grandparent as RED
        // (iii) Move z to grandparent
        if (!y)
            z = z->parent->parent;
        else if (y->color == 'R')
        {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        }

        // Uncle is BLACK, there are four cases (LL, LR, RL and RR)
        else
        {
            // Left-Left (LL) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Right Rotate Grandparent
            if (z->parent == z->parent->parent->left &&
                z == z->parent->left)
            {
                char ch = z->parent->color;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root, z->parent->parent);
            }

            // Left-Right (LR) case, do following
            // (i)  Swap color of current node  and grandparent
            // (ii) Left Rotate Parent
            // (iii) Right Rotate Grand Parent
            if (z->parent && z->parent->parent && z->parent == z->parent->parent->left &&
                z == z->parent->right)
            {
                char ch = z->color;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root, z->parent);
                rightRotate(root, z->parent->parent);
            }

            // Right-Right (RR) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Left Rotate Grandparent
            if (z->parent && z->parent->parent &&
                z->parent == z->parent->parent->right &&
                z == z->parent->right)
            {
                char ch = z->parent->color;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root, z->parent->parent);
            }

            // Right-Left (RL) case, do following
            // (i)  Swap color of current node  and grandparent
            // (ii) Right Rotate Parent
            // (iii) Left Rotate Grand Parent
            if (z->parent && z->parent->parent && z->parent == z->parent->parent->right &&
                z == z->parent->left)
            {
                char ch = z->color;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root, z->parent);
                LeftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 'B'; // keep root always black
}

// Utility function to insert newly node in RedBlack tree
void insert(struct node **root, int data)
{
    // Allocate memory for new node
    struct node *z;
    z = (struct node *)malloc(sizeof(struct node));
    z->data = data;
    z->left = z->right = z->parent = NULL;

    // if root is null make z as root
    if (*root == NULL)
    {
        z->color = 'B';
        (*root) = z;
    }
    else
    {
        struct node *y = NULL;
        struct node *x = (*root);

        // Follow standard BST insert steps to first insert the node
        while (x != NULL)
        {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (z->data > y->data)
            y->right = z;
        else
            y->left = z;
        z->color = 'R';

        // call insertFixUp to fix reb-black tree's property if it
        // is voilated due to insertion.
        insertFixUp(root, z);
    }
}

// A utility function to traverse Red-Black tree in inorder fashion
void inorder(struct node *root)
{
    static int last = 0;
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    if (root->data < last)
        printf("\nPUTE\n");
    last = root->data;
    inorder(root->right);
}


int main()
{
    struct node *root = NULL;
    printf("R&B");
    while (1)
    {
        printf("\nenter operations\n1->insert 2->display \n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            return 0;
        case 1:
        {
            printf("enter data to insert\n");
            int data;
            scanf("%d", &data);
            insert(&root, data);
        }
        break;
        case 2:
            inorder(root);
            break;

        default:
            printf("please enter valid inputs");
        }
    }
}