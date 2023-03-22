#include<iostream>
// thay nhac ve nha tim hieu
// tim min cost, tim duong di ngan nhat, bangr bam
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int value) : data(value)
	{
		left = NULL;
		right = NULL;
	}
};

class BinaryTree
{
private:
	Node* root;
private:
	void display(Node* a)
	{
		if (a != NULL)
		{
			display(a->left);
			std::cout << a->data << '\t';
			display(a->right);
		}
	}
	void them_Node(Node*& a, int value)
	{
		if (a == NULL)
			a = new Node(value);
		else
		{
			if (value < a->data)
				them_Node(a->left, value);
			else if (value > a->data)
				them_Node(a->right, value);
		}
	}
	Node* tim_con_trai_nhat_ben_phai(Node* a)
	{
		Node* current = a;
		if (current->left != NULL)
			tim_con_trai_nhat_ben_phai(current->left);
		return current;
	}
	void xoa_Node(Node*& a, int value)
	{
		if (a != NULL)
		{
			if (value < a->data)
				xoa_Node(a->left, value);
			else if (value > a->data)
				xoa_Node(a->right, value);
			else
			{
				if (a->left != NULL && a->right != NULL)
				{
					Node* current = tim_con_trai_nhat_ben_phai(a->right);
					a->data = current->data;
					xoa_Node(a->right, current->data);
				}
				else
				{
					Node* p = a;
					if (a->left == NULL)
					{
						a = a->right;
						delete p;
					}
					else if (a->right == NULL)
					{
						a = a->left;
						delete p;
					}
				}
			}
		}
		else
		{
			std :: cout << "Khong co node do trong cay";
		}
	}
	// ádadffwef
	bool tim_Node(Node* a, int gia_tri)
	{
		if (a == NULL)
			return false;
		else
		{
			if (gia_tri < a->data)
				tim_Node(a->left, gia_tri);
			else if (gia_tri > a->data)
				tim_Node(a->right, gia_tri);
			else if(gia_tri == a->data)
			{
				return true;
			}
		}
	}
public: 
	BinaryTree() { root = NULL; }
	void add_Node(int _data)
	{
		/*if (root == NULL)
			root = new Node(_data);
		else
		{
			Node* current = root;
			while (true)
			{
				if (_data < current->data)
				{
					if (current->left == NULL)
					{
						current->left = new Node(_data);
						break;
					}
					else
					{
						current = current->left;
					}
				}
				else if (_data > current->data)
				{
					if (current->right == NULL)
					{
						current->right = new Node(_data);
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
		}*/
		them_Node(root, _data);
	}
	void delete_Node(int _data)
	{
		xoa_Node(root, _data);
	}
	void Traversal()
	{
		display(root);
	}
	void find(int value)
	{
		if (tim_Node(root, value))
			std::cout << "Node co trong cay nhi phan";
		else
			std::cout << "Node khong co trong cay nhi phan";
	}
};

int main()
{
	BinaryTree a;
	a.add_Node(4);
	a.add_Node(5);
	a.add_Node(15);
	a.add_Node(1);
	a.add_Node(3);
	a.add_Node(0);
	a.add_Node(12);
	a.add_Node(19);
	a.Traversal();

	a.delete_Node(1);
	a.delete_Node(15);
	std::cout << std::endl;
	a.Traversal();
	std::cout << std::endl;
	a.find(15);
	std::cout << std::endl;
	a.find(4);
	std::cout << std::endl;
	a.find(19);
	return 0;
}
