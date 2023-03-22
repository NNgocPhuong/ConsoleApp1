#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void init(Node*& root)
{
	root = NULL;
}

Node* create_data(int value)
{
	Node* ptr = new Node;
	ptr->data = value;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

void add_Node(Node*& root, int key)
{
	if (root == NULL) {
		Node* p = create_data(key);
		root = p;
	}
	else
	{
		Node* p = root;
		while (p->data > key)
		{
			if (p->left == NULL) {
				p->left = create_data(key);
				break;
			}
			else
				p = p->left;
		}
		while (p->data < key)
		{
			if (p->right == NULL) {
				p->right = create_data(key);
				break;
			}
			else
				p = p->right;
		}
	}
}
void display(Node* root)
{
	if (root != NULL)
	{
		cout << root->data << '\t';
		display(root->left);
		//cout << root->data << '\t';
		display(root->right);
	}
}
bool find_Node(Node* root, int key)
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		if (key < root->data)
		{
			find_Node(root->left, key);
		}
		else if (key > root->data)
		{
			find_Node(root->right, key);
		}
		else
		{
			return true;
		}
	}
}
void find_left_child(Node*& p, Node*& a)
{
	if (a->left != NULL)
	{
		find_left_child(p, a->left);
	}
	else
	{
		p->data = a->data;
		p = a;
		a = a->right;
	}
}
void remove_Node(Node*& root, int key)
{
	if (root == NULL) {
		cout << "Khong co gi de xoa";
	}
	else
	{
		if (key < root->data)
		{
			remove_Node(root->left, key);
		}
		else if (key > root->data)
		{
			remove_Node(root->right, key);
		}
		else
		{
			Node* p = root;
			if (p->left == NULL)
				root = root->right;
			else if (p->right == NULL)
				root = root->left;
			else
				find_left_child(p, p->right);
			delete p;
		}
	}
}
int main()
{
	Node* root;
	init(root);
	add_Node(root, 77);
	add_Node(root, 71);
	add_Node(root, 70);
	add_Node(root, 79);
	add_Node(root, 78);
	add_Node(root, 89);
	add_Node(root, 99);
	add_Node(root, 63);
	add_Node(root, 96);
	add_Node(root, 26);
	display(root);

	cout << endl;

	/*if (find_Node(root, 12))
		cout << "Node co trong cay nhi phan";
	else
		cout << "Node khong co trong cay nhi phan";

	cout << endl;

	remove_Node(root, 12);
	remove_Node(root, 2);
	remove_Node(root, 7);
	display(root);*/
	return 0;
}
