#include <iostream>
#include <vector>
#include <algorithm>

#include "BinaryTree.h"

using namespace std;

int main()
{
    auto bt = new BinaryTree<int>();

    for (auto x : { 7, 5, 1, 2, 4, 8 })
    {
        bt->Insert(x, x);
    }

    bt->InorderWalk();

    return 0;
}
