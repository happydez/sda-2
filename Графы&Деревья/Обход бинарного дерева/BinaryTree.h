#pragma once

#include <iostream>

using namespace std;

template <typename T>
class BinaryTree
{
	private:

		struct BTNode
		{
			T data;
			int key;
			BTNode* p, * left, * right;

			BTNode(int key, T data, BTNode* p = nullptr, BTNode* left = nullptr, BTNode* right = nullptr)
			{
				this->key = key;
				this->data = data;
				this->p = p;
				this->left = left;
				this->right = right;
			}
		};

		BTNode* minimum(BTNode* x) 
		{
			while (x->left != nullptr) 
			{
				x = x->left;
			}

			return x;
		}

		BTNode* maximum(BTNode* x) 
		{
			while (x->right != nullptr) 
			{
				x = x->right;
			}

			return x;
		}

		BTNode* next(BTNode* x)
		{
			if (x->right != nullptr)
			{
				return maximum(x->right);
			}

			BTNode* y = x->p;
			while ((y != nullptr) && (x == y->right))
			{
				x = y;
				y = y->p;
			}

			return y;
		}

		BTNode* prev(BTNode* x)
		{
			if (x->left != nullptr)
			{
				return minimum(x->left);
			}

			BTNode* y = x->p;
			while ((y != nullptr) && (x == y->left))
			{
				x = y;
				y = y->p;
			}

			return y;
		}

		BTNode* searchHelper(BTNode* x, int key) 
		{
			while ((x != nullptr) && (x->key != key)) 
			{
				x = (x->key < key) ? x->right : x->left;
			}

			return x;
		}

		void insertHelper(BTNode* x, int key, T data)
		{
			BTNode* temp = nullptr;

			while (x != nullptr)
			{
				temp = x;

				if (x->key < key)
				{
					x = x->right;
				}
				else if (x->key > key)
				{
					x = x->left;
				}
				else
				{
					return;
				}
			}

			BTNode* y = new BTNode(key, data);
			y->p = temp;

			if (temp == nullptr)
			{
				this->root = y;
			}
			else if (temp->key < key)
			{
				temp->right = y;
			}
			else
			{
				temp->left = y;
			}
		}

		BTNode* removeHelper(BTNode*& z)
		{
			BTNode* y;

			if ((z->left == nullptr) || (z->right == nullptr)) 
			{
				y = z;
			}
			else {
				y = next(z);
			}

			BTNode* x;
			if (y->left != nullptr) 
			{
				x = y->left;
			}
			else 
			{
				x = y->right;
			}

			if (x != nullptr) 
			{
				x->p = y->p;
			}

			if (y->p == nullptr) 
			{
				this->root = x;
			}
			else if (y == y->p->left) 
			{
				y->p->left = x;
			}
			else 
			{
				y->p->right = x;
			}

			if (y != z) 
			{
				z->key = y->key;
			}

			return y;
		}

		void inorderWalkHelper(BTNode* x)
		{
			if (x != nullptr)
			{
				inorderWalkHelper(x->left);
				cout << x->key << " ";
				inorderWalkHelper(x->right);
			}
		}

		void deleteHelper(BTNode* x)
		{
			if (x != nullptr)
			{
				deleteHelper(x->left);
				deleteHelper(x->right);

				x->p = nullptr;
				delete x;
				x = nullptr;
			}

		}

		BTNode* root;

	public:

		~BinaryTree()
		{
			deleteHelper(root);
		}

		BinaryTree()
		{
			this->root = nullptr;
		}

		void Insert(int key, T data)
		{
			insertHelper(root, key, data);
		}

		bool Remove(int key)
		{
			BTNode* x = searchHelper(root, key);

			if (x == nullptr) 
			{
				return false;
			}

			removeHelper(x);

			return true;
		}

		bool Contains(int key)
		{
			return searchHelper(root, key) != nullptr;
		}

		void InorderWalk()
		{
			inorderWalkHelper(root);
		}
};

