#pragma once

#include <iostream>

using namespace std;

template <typename T>
class BinaryHeap
{
	private:
		int cap;
		int count;
		T* heap;

		static const int defaultCapacity = 4;

		void resize()
		{
			cap *= 2;
			auto newHeap = new T[cap];

			for (int i = 0; i < count; i++)
			{
				newHeap[i] = heap[i];
			}

			delete[] heap;
			heap = newHeap;
		}

		void siftDown(int start)
		{
			if (start < count)
			{
				while (leftChild(start) < count)
				{
					int child = leftChild(start);

					if (rightChild(start) < count && (heap[child] > heap[rightChild(start)]))
					{
						child = rightChild(start);
					}

					if (heap[start] < heap[child])
					{
						break;
					}
					else
					{
						swap(heap[start], heap[child]);
						start = child;
					}
				}
			}
		}

		static int parent(int i) { return (i - 1) / 2; }
		static int leftChild(int i) { return 2 * i + 1; }
		static int rightChild(int i) { return 2 * i + 2; }

	public:

		~BinaryHeap()
		{
			delete[] heap;
			heap = nullptr;
		}

		BinaryHeap(int cap)
		{
			if (cap <= 0)
			{
				cap = defaultCapacity;
			}

			this->cap = cap;
			count = 0;
			heap = new T[cap];
		}

		T Min()
		{
			if (IsEmpty())
			{
				throw new exception("is empty");
			}

			return heap[0];
		}

		bool IsEmpty()
		{
			return this->count == 0;
		}

		void Add(T value)
		{
			if (count == cap) resize();

			int i = count;
			heap[count++] = value;

			while (i > 0 && (heap[i] < heap[parent(i)]))
			{
				swap(heap[i], heap[parent(i)]);
				i = parent(i);
			}
		}

		T Remove()
		{
			if (IsEmpty())
			{
				throw new exception("is empty");
			}

			auto value = heap[0];
			swap(heap[0], heap[count - 1]);
			count--;

			siftDown(0);

			return value;
		}
};

