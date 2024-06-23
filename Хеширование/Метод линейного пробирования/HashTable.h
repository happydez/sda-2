#pragma once

#include <iostream>

using namespace std;

// For integers
class HashTable
{
	private:

		int cap;
		int count;
		int* table;
		static const int defaultCapacity = 4;

		int hash(int value)
		{
			return value % cap; // for strings: value.length() % cap
		}

		int findIndex(int value)
		{
			int index = hash(value);

			while (table[index] != -1)
			{
				index = (index + 1) % cap;
			}

			return index;
		}

		void resize()
		{
			cap *= 2;
			auto newTable = new int[cap];

			for (int i = 0; i < count; i++)
			{
				newTable[i] = table[i];
			}

			for (int i = count; i < cap; i++)
			{
				newTable[i] = -1;
			}

			delete[] table;
			table = newTable;
		}

	public:

		~HashTable()
		{
			delete[] table;
		}

		HashTable()
		{
			count = 0;
			cap = defaultCapacity;
			table = new int[cap];

			for (int i = 0; i < cap; i++)
			{
				table[i] = -1;
			}
		}

		void Insert(int value)
		{
			if (count == cap)
			{
				resize();
			}

			int index = findIndex(value);

			count++;
			table[index] = value;
		}

		void Remove(int value)
		{
			int index = hash(value);

			int i = 0;
			while ((i < cap) && (table[index] != value))
			{
				i++;
				index = (index + 1) % cap;
			}

			if (i != cap)
			{
				this->count--;
				table[index] = -1;
			}
		}

		void Print()
		{
			if (this->count == 0)
			{
				cout << "is empty" << endl;
				return;
			}

			for (int i = 0; i < cap; i++)
			{
				if (table[i] != -1)
				{
					cout << "[" << i << "]: " << table[i] << endl;
				}
			}
		}

		bool Contains(int value)
		{
			int index = hash(value);

			int i = 0;
			while ((i < cap) && (table[index] != value))
			{
				i++;
				index = (index + 1) % cap;
			}

			return i == cap;
		}
};

