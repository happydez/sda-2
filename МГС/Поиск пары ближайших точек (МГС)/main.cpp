#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Point
{
    public:
        float X, Y;

        Point(float x, float y)
        {
            this->X = x;
            this->Y = y;
        }
};

pair<int, int> BruteForceClosestPoints(Point* points, int len)
{
    int i1 = 0, i2 = 0;
    float minDist = FLT_MAX;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            float dist = sqrt(pow(points[i].X - points[j].X, 2) + pow(points[i].Y - points[j].Y, 2));

            if (dist < minDist)
            {
                i1 = i;
                i2 = j;
                minDist = dist;
            }
        }
    }

    return pair<int, int>(i1, i2);
}

int main()
{
    const int len = 5;

    auto points = new Point[len]
    {
        // 0             1
        Point(0.0, 0.0), Point(0.5, 0.0),
        // 2             3
        Point(3.2, 7.4), Point(1.0, -2.0),
        // 4
        Point(100.0, 100.0)
    };

    auto result = BruteForceClosestPoints(points, len);

    cout << "points: " << result.first << " & " << result.second << " are closest to each other" << endl;

    return 0;
}
