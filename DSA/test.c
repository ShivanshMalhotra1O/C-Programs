#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

struct node *rightRotate(struct node *x)
{
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct node *splay(struct node *root, int key)
{

    if (root == NULL || root->key == key)
        return root;

    if (root->key > key)
    {

        if (root->left == NULL)
            return root;

        if (root->left->key > key)
        {

            root->left->left = splay(root->left->left, key);

            root = rightRotate(root);
        }
        else if (root->left->key < key)
        {

            root->left->right = splay(root->left->right, key);

            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    else
    {

        if (root->right == NULL)
            return root;

        if (root->right->key > key)
        {

            root->right->left = splay(root->right->left, key);

            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key)
        {

            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

struct node *insert(struct node *root, int k)
{

    if (root == NULL)
        return newNode(k);

    root = splay(root, k);

    if (root->key == k)
        return root;

    struct node *newnode = newNode(k);

    if (root->key > k)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }

    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }

    return newnode;
}

struct node *delete_key(struct node *root, int key)
{
    struct node *temp;
    if (!root)
        return NULL;

    root = splay(root, key);

    if (key != root->key)
        return root;

    if (!root->left)
    {
        temp = root;
        root = root->right;
    }

    else
    {
        temp = root;

        root = splay(root->left, key);

        root->right = temp->right;
    }

    free(temp);

    return root;
}

struct node *search(struct node *root, int key)
{
    return splay(root, key);
}

void print(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        print(root->left);
        print(root->right);
    }
}

int main()
{
    struct node *root;

    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 30);

    root = search(root, 40);

    printf("Modified Splay tree is \n");
    print(root);
    return 0;
}