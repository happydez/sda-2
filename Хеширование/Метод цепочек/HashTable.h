#pragma once

#include <iostream>

#include "LinkedList.h"

using namespace std;

template <class T, class THash>
class HashTable
{
	private:

		int cap;
		int count;
		LinkedList<T>** arr;

		static const int defaultCapacity = 8;

	public:

		HashTable()
		{
			cap = defaultCapacity;
			count = 0;

			arr = new LinkedList<T>*[cap];
			for (int i = 0; i < cap; i++)
			{
				arr[i] = nullptr;
			}
		}

		~HashTable()
		{
			for (int i = 0; i < cap; i++)
			{
				if (arr[i] != nullptr)
				{
					delete arr[i];
					arr[i] = nullptr;
				}
			}

			delete[] arr;
		}

		void Add(T value, const THash& hash = THash())
		{
			if (arr[hash(value, cap)] == nullptr)
			{
				arr[hash(value, cap)] = new LinkedList<T>();
			}

			arr[hash(value, cap)]->PushBack(value);
		}

		void Remove(T value, const THash& hash = THash())
		{
			if (arr[hash(value, cap)] != nullptr)
			{
				arr[hash(value, cap)]->Remove(value);
			}
		}

		bool Contains(T value, const THash& hash = THash())
		{
			if (arr[hash(value, cap)] != nullptr)
			{
				LinkedList<T>* it = arr[hash(value, cap)];

				if (it->Search(value) != nullptr)
				{
					return true;
				}
			}

			return false;
		}
};

