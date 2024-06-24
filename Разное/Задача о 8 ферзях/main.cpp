#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int SIZE = 8;
int board[SIZE][SIZE];

void showBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << ((board[i][j]) ? "Q " : ". ");
        }

        cout << endl;
    }
}

bool tryQueen(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        if (board[i][y])
        {
            return false;
        }
    }

    for (int i = 1; i <= x && y - i >= 0; i++)
    {
        if (board[x - i][y - i])
        {
            return false;
        }
    }

    for (int i = 1; i <= x && y + i < SIZE; i++)
    {
        if (board[x - i][y + i])
        {
            return false;
        }
    }

    return true;
}

void setQueen(int row)
{
    static int cnt = 0;

    if (row == SIZE)
    {
        showBoard();
        cout << "Result #" << ++cnt << endl << endl;

        return;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (tryQueen(row, i))
        {
            board[row][i] = 1;
            setQueen(row + 1);
            board[row][i] = 0;
        }
    }
}

int main()
{
    setQueen(0);

    return 0;
}