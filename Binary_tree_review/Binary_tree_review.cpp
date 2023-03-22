#include<iostream>
template<class T>
class Node
{
public:
	Node* left;
	Node* right;
	T data;
public:
	Node(T value) : data(value)
	{
		left = right = NULL;
	}
};

template<class T>
class Binary_tree
{
private:
	Node<T>* root;
protected:
	Node<T>* sp_find_left_child(Node<T>* a)
	{
		Node<T>* current = a;
		while (current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}
	void sp_delete_Node(Node<T>*& a, T value)
	{
		if (a == NULL)
		{
			return;
		}
		else
		{
			Node<T>* current = a;
			while (true)
			{
				if (current->data < value)
				{
					current = current->right;
				}
				else if (current->data > value)
				{
					current = current->left;
				}
				else
				{
					break;
				}
			}
			Node<T>* p = current;
			if (current->left == NULL)
			{
				current = current->right;
				delete p;
			}
			else if (current->right == NULL)
			{
				current = current->left;
				delete p;
			}
			else
			{
				Node<T>* temp = sp_find_left_child(current->right);
				p->data = temp->data;
				sp_delete_Node(p->right, value);
			}
		}
	}
public:
	Binary_tree()
	{
		root = NULL;
	}
	~Binary_tree(){}
	void add_Node(T value)
	{
		if (root == NULL)
		{
			root = new Node<T>(value);
		}
		else
		{
			Node<T>* current = root;
			while (true)
			{
				if (current->data > value)
				{
					if (current->left == NULL)
					{
						current->left = new Node<T>(value);
						break;
					}
					else
					{
						current = current->left;
					}
				}
				else if (current->data < value)
				{
					if (current->right == NULL)
					{
						current->right = new Node<T>(value);
						break;
					}
					else
					{
						current = current->right;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	void delete_Node(T value)
	{
		sp_delete_Node(root, value);
	}
};


int main()
{
	Binary_tree<int> a;
	
	a.add_Node(4);
	a.add_Node(5);
	a.add_Node(15);
	a.add_Node(1);
	a.add_Node(3);
	a.add_Node(0);
	a.add_Node(12);
	a.add_Node(19);
	//a.Traversal();

	a.delete_Node(1);
	a.delete_Node(15);
	
}