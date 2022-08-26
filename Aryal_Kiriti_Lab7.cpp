#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int info;
	Node* left, *right;
	Node(int el)
	{
		this->info = el;
		this->left = this->right = nullptr;
	}
};

void postOrder(Node* temp)
{
	if (temp == nullptr)
		return;
	postOrder(temp->left);
	postOrder(temp->right);
	cout << temp->info << " ";
}

void swapChild(Node* t1)
{
	Node* temp;
	if (t1 == NULL)
		return;
	swapChild(t1->left);
	swapChild(t1->right);
	temp = t1->left;
	t1->left = t1->right;
	t1->right = temp;
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout << "The tree traversed in postorder is: ";
	postOrder(root);
	cout << endl << endl;
	cout << "The tree traversed in postorder after swap is: ";
	swapChild(root);
	postOrder(root);
}