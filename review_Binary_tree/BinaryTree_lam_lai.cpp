#include<iostream>

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int _data = 0)
	{
		data = _data;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree
{
	Node* root;
	void display(Node* ptr)
	{
		if (ptr != NULL)
		{
			display(ptr->left);
			std::cout << ptr->data << '\t';
			display(ptr->right);
		}
	}

public:
	BinaryTree()
	{
		root = NULL;
	}
	void add_Node(int a)
	{
		if (root == NULL)
			root = new Node(a);
		else
		{
			Node* p = root;
			while (true)
			{
				if (a < p->data)
				{
					if (p->left == NULL)
					{
						p->left = new Node(a);
						break;
					}
					else
						p = p->left;
				}
				else if (a > p->data)
				{
					if (p->right == NULL)
					{
						p->right = new Node(a);
						break;
					}
					else
						p = p->right;
				}
				else
				{
					break;
				}

			}
		}
	}
	Node* find_the_left_child(Node* a) // tim node trai cung cua cay con phai
	{
		while (a->left != NULL)
		{
			a = a->left;
		}
		return a;
	}
	void delete_Node(int value)
	{
		if (root == NULL)
			return;
		else
		{
			Node* p = root;
			Node* parent = p;
			while (true)
			{
				if (value < p->data)
				{
					parent = p;
					p = p->left;
				}
				else if (value > p->data)
				{
					parent = p;
					p = p->right;
				}
				else
				{
					break;
				}
			}
			if (p != NULL)
			{
				//xoa node co 2 con
				if (p->left != nullptr && p->right != nullptr)
				{
					Node* current = find_the_left_child(p->right);
					p->data = current->data;
					Node* r = p->right;
					if (r == current)
						p->right = current->right;
					else
					{
						while (r->left != current)
						{
							r = r->left;
						}
						r->left = current->right;
					}
					delete current;
				}
				else
				{
					Node* r = NULL;
					if (p->left == NULL)
						r = p->right;
					else
						r = p->left;

					if (p->data < parent->data)
					{
						parent->left = r;
					}
					else if (p->data > parent->data) {
						parent->right = r;
					}
					delete p;
				}
			}
		}
	}

	void traversal()
	{
		display(root);
	}
};

int main()
{
	BinaryTree A;
	for (int i = 0; i < 15; i++)
	{
		int x;
		std::cin >> x;
		A.add_Node(x);
	}
	A.traversal();
	A.delete_Node(8);
	A.delete_Node(12);
	std::cout << std::endl;
	A.traversal();
}
