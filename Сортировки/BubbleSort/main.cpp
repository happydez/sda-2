#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(int* data, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (data[i] > data[j])
            {
                swap(data[i], data[j]);
            }
        }
    }
}

void PrintData(int* data, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << data[i] << " ";
    }

    cout << endl;
}

int main()
{
    const int N = 5;
    auto data = new int[N]{ 5, 4, 3, 2, 1 };

    PrintData(data, N);

    BubbleSort(data, N);

    PrintData(data, N);
	
	delete[] data;

    return 0;
}
