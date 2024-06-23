#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Node
{
	public:
		T Data;
		Node* Next;
		Node* Prev;

		Node()
		{
			this->Data = T();
			this->Next = this->Prev = nullptr;
		}

		Node(T data) : Node()
		{
			this->Data = data;
		}

		~Node()
		{
			delete this->Next;
			delete this->Prev;
			this->Next = nullptr;
			this->Prev = nullptr;
		}

};

template <typename T>
class LinkedList
{
	private:

		Node<T>* head;
		Node<T>* tail;

	public:

		LinkedList()
		{
			this->head = this->tail = nullptr;
		}

		~LinkedList()
		{
			Clear();
		}

		bool IsEmpty()
		{
			return this->head == nullptr;
		}

		Node<T>* PushBack(T data)
		{
			Node<T>* n = new Node<T>(data);

			if (IsEmpty())
			{
				this->head = this->tail = n;
			}
			else
			{
				this->tail->Next = n;
				n->Prev = this->tail;
				this->tail = n;
			}

			return n;
		}

		Node<T>* PushFront(T data)
		{
			Node<T>* n = new Node<T>(data);

			if (IsEmpty())
			{
				this->head = this->tail = n;
			}
			else
			{
				this->head.Prev = n;
				n->Next = this->head;
				this->head = n;
			}

			return n;
		}

		void PopBack()
		{
			if (IsEmpty())
			{
				return;
			}

			Node<T>* prev = this->tail->Prev;

			if (prev != nullptr)
			{
				prev->Next = nullptr;
			}
			else
			{
				this->head = nullptr;
			}

			this->tail->Prev = nullptr;
			delete this->tail;
			this->tail = prev;
		}

		void PopFront()
		{
			if (IsEmpty())
			{
				return;
			}

			Node<T>* next = this->head->Next;

			if (next != nullptr)
			{
				next->Prev = nullptr;
			}
			else
			{
				this->tail = nullptr;
			}

			this->head->Next = nullptr;
			delete this->head;
			this->head = next;
		}

		Node<T>* Search(T data)
		{
			Node<T>* it = this->head;

			while (it != nullptr)
			{
				if (it->Data == data)
				{
					break;
				}

				it = it->Next;
			}

			return it;
		}

		void Remove(T data)
		{
			Node<T>* n = Search(data);

			if (n == nullptr)
			{
				return;
			}

			if (n->Prev == nullptr)
			{
				PopFront();
			}
			else if (n->Next == nullptr)
			{
				PopBack();
			}
			else
			{
				Node<T>* left = n->Prev;
				Node<T>* right = n->Next;

				left->Next = right;
				right->Prev = left;

				n->Prev = nullptr;
				n->Next = nullptr;
				delete n;
			}
		}

		void Clear()
		{
			while (!IsEmpty())
			{
				PopFront();
			}
		}
};

