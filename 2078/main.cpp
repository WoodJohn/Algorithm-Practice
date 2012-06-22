#include <iostream>
#include <string.h>
using namespace std;

int num[8][8];
int n;
int colsum[8];
int mMin;

void dfs(int r)
{
    int i;
    if (r == n)
    {
        int mMax = 0;
        for (i = 0; i < n; i++)
        {
            if (colsum[i] > mMax)
                mMax = colsum[i];
        }
        if (mMax < mMin)
            mMin = mMax;
        return;
    }
    int offset;
    for (offset = 0; offset < n; offset++)
    {
        for (i = 0; i < n; i++)
        {
            colsum[i] += num[r][(i + offset) % n];
        }
        dfs(r + 1);
        for (i = 0; i < n; i++)
        {
            colsum[i] -= num[r][(i + offset) % n];
        }
    }
}

int main()
{
    int i, j;
    while (cin >> n)
    {
        if (n == -1)
            break;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> num[i][j];
            }
        }
        memset(colsum, 0, sizeof(colsum));
        mMin = 100000;
        dfs(0);
        cout << mMin << endl;
    }
    return 0;
}
