#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#include "BinaryHeap.h"

using namespace std;

int main()
{
    auto bh = new BinaryHeap<int>(4);

    for (auto v : { 4, 1, 2, 7, 6, 5, 3, 12 })
    {
        bh->Add(v);
    }

    while (!bh->IsEmpty())
    {
        cout << bh->Remove() << " ";
    }

    return 0;
}
