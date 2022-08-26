#include <iostream>
#include <Math.h>
using namespace std;

struct Node 
{
	int info;
	Node* left, * right;
	Node(int el)
	{
		this->info = el;
		this->left = nullptr;
		this->right = nullptr;
	}
};

bool isBSTUtil(Node* root, int min, int max)
{
	if (root == nullptr)
		return true;
	if (root->info > min && root->info < max && isBSTUtil(root->left, min, root->info) && isBSTUtil(root->right, root->info, max))
		return true;
	else 
		return false;
}
bool isBST(Node *root)
{
	return isBSTUtil(root, INT_MIN, INT_MAX);
}
int maxHeight(Node* root)
{
	if (root == nullptr)
		return 0;
	if (maxHeight(root->left) == -1)
		return -1;
	return 1 + max(maxHeight(root->left), maxHeight(root->right));
}
bool isBalanced(Node* root)
{
	if (root == nullptr)
		return true;
	if (abs(maxHeight(root->left) - maxHeight(root->right)) < 1 && isBalanced(root->left) && isBalanced(root->right))
		return true;
	else
		return false;
}

int main() 
{
	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(6);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(7);
	if (isBST(root))
		cout << "The binary tree is BST." << endl;
	else
		cout << "The binary tree is not BST." << endl;

	if (isBalanced(root))
		cout << "The binary tree is balanced." << endl;
	else
		cout << "The binary tree is not balanced." << endl;
}