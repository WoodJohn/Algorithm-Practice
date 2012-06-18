#include <iostream>
#include <string.h>
#define INF 10000
using namespace std;

int n, mMin;
char g[20][20];
char ori[20][20];

inline void change(int x, int y)
{
    if (g[x][y] == 'y')
        g[x][y] = 'w';
    else
        g[x][y] = 'y';
}

void press(int x, int y)
{
    change(x, y);
    if (x > 0)
        change(x - 1, y);
    if (y > 0)
        change(x, y - 1);
    if (x < n - 1)
        change(x + 1, y);
    if (y < n - 1)
        change(x, y + 1);
}

int test(int a)
{
    int i;
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        if (a & (1 << i))
        {
            press(0, i);
            sum++;
            if (sum >= mMin)
                return INF;
        }
    }
    int j;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (g[i - 1][j] == 'w')
            {
                press(i, j);
                sum++;
                if (sum >= mMin)
                    return INF;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (g[n - 1][i] == 'w')
            return INF;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> ori[i];
        }
        int mMax = 1 << n;
        mMin = INF;
        for (i = 0; i < mMax; i++)
        {
            memcpy(g, ori, sizeof(ori));
            int t = test(i);
            if (t < mMin)
                mMin = t;
        }
        if (mMin == INF)
            cout << "inf" << endl;
        else
            cout << mMin << endl;
    }
    return 0;
}
