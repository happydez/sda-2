#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#include "HashTable.h"

using namespace std;

int main()
{
    auto table = new HashTable();

    for (auto v : { 1, 2, 3, 4, 5, 6, 7, 12, 13, 104 })
    {
        table->Insert(v);
    }

    table->Print();

    for (auto v : { 1, 2, 3, 4, 5, 6, 7, 12, 13, 104 })
    {
        table->Remove(v);
    }

    table->Print();

    return 0;
}
