#include <iostream> 
#include <stack> 
#include <stdlib.h> 
#include <algorithm> 
#include <math.h> 
using namespace std;

typedef struct Node
{
	char info;
	Node* left, * right;
} Node;
typedef struct Node* Tree;

Tree createNode(int info);
Tree constructTree(Tree T, char postfix[]);
int getPriority(char ch);
void convert(string infix, char postfix[]);
void resultExpression(char postfix[]);
void show_node(Tree T);
void preorder(Tree T);
void inorder(Tree T);
void display(Tree tree, char postfix[]);
bool expCorrect(string infix);
bool isOperator(char ch);
bool isDigit(char c);


int main()
{
	cout << "\n Enter Expression : ";
	string input;
	cin >> input;
	if (!expCorrect(input)) 
	{
	cout << " Expression can only contain [ 1-9,( ,) ,+ ,- ,* , /] " << endl;
	return 0;
	}
	char* ch = new char();
	convert(input, ch);
	Tree t1 = NULL;
	t1 = constructTree(t1, ch);
	display(t1, ch);
	return 0;
}

void display(Tree tree, char ch[])
{
	cout << "\n InOrder Traverse (Left, Parent, Right) : ";
	inorder(tree);
	cout << " " << endl;
	cout << "\n The result of the expression ";
	resultExpression(ch);
	cout << "\n PreOrder Traverse of the tree expression(Parent, Left, Right) : ";
	preorder(tree);
	cout << " " << endl;
	
}

bool isDigit(char ch)
{
	if (ch > 47 && ch < 58)
	return true;
	else
		return false;
}
bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}

bool expCorrect(string str)
{
	for (unsigned int i = 0; i < str.length(); i++) 
	{
		if (!isDigit(str[i]) && !isOperator(str[i]) && str[i] != '(' && str[i] != ')')
			return false;
	}
	return true;
}

Tree createNode(int info)
{
	Node* temp = new Node();
	if (temp == NULL)
	{
		cout << "Out of space!\n";
		return (temp);
	}
	temp->left = NULL;
	temp->right = NULL;
	temp->info = info;
	return temp;
};

Tree constructTree(Tree tree, char ch[])
{
	int i = 0;
	stack<Node*> st;
	Node* t1;
	Node* t2;
	while (ch[i] != '\0')
	{
		if (!(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/'))
		{
			tree = createNode(ch[i]);
			st.push(tree);
		}
		else
		{
			tree = createNode(ch[i]);
			t1 = st.top(); 
			st.pop();
			t2 = st.top(); 
			st.pop();
			tree->right = t1;
			tree->left = t2;
			st.push(tree);
		}
		i++;
	}
	return tree;
}

void show_node(Tree T)
{
	cout << T->info << " ";
}
void preorder(Tree T)
{
	if (T != NULL)
	{
		show_node(T);
		preorder(T->left);
		preorder(T->right);
	}
}
void inorder(Tree T)
{
	if (T != NULL)
	{
		inorder(T->left);
		show_node(T);
		inorder(T->right);
	}
}
	int getPriority(char ch)
	{
		switch (ch)
		{
			case '/':
			case '*':
			return 2;
			case '+':
			case '-':
			return 1;
			default:
			return 0;
	}
}
void convert(string str, char ch[])
{
	unsigned int count = 0;
	stack<char> st;
	int postCount = 0;
	char el;
	while (count < str.length())
	{
		el = str[count];
		if (el == '(')
		{
			st.push(el);
			count++;
			continue;
		}
		if (el == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				ch[postCount++] = st.top();
				st.pop();
			}
			if (!st.empty())
			{
			st.pop();
			}
			count++;
			continue;
		}

		if (getPriority(el) == 0)
		{
			ch[postCount++] = el;
		}
		else
		{
			if (st.empty())
			{
				st.push(el);
			}
			else
			{
				while (!st.empty() && st.top() != '(' &&
				getPriority(el) <= getPriority(st.top()))
				{
					ch[postCount++] = st.top();
					st.pop();
				}
				st.push(el);
			}
		}
		count++;
	}

	while (!st.empty())
	{
	ch[postCount++] = st.top();
	st.pop();
	}
	ch[postCount] = '\0';
}

void resultExpression(char postfix[])
{
	stack<float> result;
	int k = 0;
	bool error = false;
	while (postfix[k] && !error)
	{
		char ch = postfix[k];
		if (isDigit(ch))
		{
			result.push((float)postfix[k] - '0');
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			float num1 = result.top();
			result.pop();
			float num2 = result.top();
			result.pop();
			float calculate = 0;
			switch (ch)
			{
				case '+':
				calculate = num2 + num1;
				break;
				case '-':
				calculate = num2 - num1;
				break;
				case '*':
				calculate = num2 * num1;
				break;
				case '/':
				if (num1 == 0)
				{
					cout << "\n Math Error: Can't Divide by Zero " << endl;
					error = true;
					break;
				}
				calculate = num2 / num1;
				break;
			}
			result.push(calculate);
		}
		k++;
	}
	if (!error)
		cout << " = " << result.top() << endl;
}
