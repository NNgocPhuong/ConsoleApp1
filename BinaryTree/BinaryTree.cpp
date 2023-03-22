#include<iostream>

class Node
{
public:
	int data;
	Node* left;
	Node* right;
public:
	Node(int value) : data(value)
	{
		left = right = NULL;
	}
};

class BinaryTree
{
	Node* root;
	void spTraversal(Node* p)
	{
		if (p != NULL)
		{
			spTraversal(p->left);
			std::cout << p->data << '\t';
			spTraversal(p->right);
		}
	}
	void spDelete(Node* p, int value)
	{
		if (p != NULL)
		{

		}
	}
public:
	BinaryTree()
	{
		root = NULL;
	}
	void addNode(int value)
	{
		Node* current = root;
		if (root == NULL) {
			root = new Node(value);
		}
		else
		{
			while (true)
			{
				if (value < current->data)
				{
					if (current->left != NULL)
						current = current->left;
					else
						current->left = new Node(value);
				}
				else if (value > current->data)
				{
					if (current->right != NULL)
						current = current->right;
					else
						current->right = new Node(value);
				}
				else
				{
					break;
				}
			}
		}
	}

	void deleteNode(int value)
	{
		
	}

	void traversal()
	{
		spTraversal(root);
	}
};


int main()
{
	BinaryTree T;
	T.addNode(8);
	T.addNode(4);
	T.addNode(15);
	T.addNode(2);
	T.addNode(5);
	T.addNode(10);
	T.addNode(1);
	T.traversal();

	return 0;
}
