#include<iostream>
#include<math.h>
using namespace std;

struct Node {
    int info;
    Node* left, * right;
    Node(int info)
    {
        this->info = info;
        left = NULL;
        right = NULL;
    }
};

int getWidth(Node* root, int level);
int height(Node* root);

int getMaxWidth(Node* root)
{
    int maxWidth = 0;
    int width;
    int h = height(root);

    for (int i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }

    return maxWidth;
}

int getWidth(Node* root, int level)
{

    if (root == NULL)
        return 0;

    if (level == 1)
        return 1;

    else if (level > 1)
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
}

int height(Node* root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    cout << "Maximum width is " << getMaxWidth(root) << endl;
    return 0;
}