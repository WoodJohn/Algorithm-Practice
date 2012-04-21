#include <iostream>
#include <string.h>
using namespace std;

int n, i;
int dp[101][101];
int data[101][101];
int mMax;

int find(int a, int j)
{
    if (a == 0 && j == 0)
    {
        dp[a][j] = data[a][j];
        return dp[a][j];
    }
    if (dp[a][j] > 0)
        return dp[a][j];
    int t = 0;
    if (j > 0)
    {
        int temp = find(a - 1, j - 1);
        if (temp > t)
            t = temp;
    }
    if (j < i)
    {
        int temp = find(a - 1, j);
        if (temp > t)
            t = temp;
    }
    dp[a][j] = t + data[a][j];
    return dp[a][j];
}

int main()
{
    memset(dp, 0, sizeof(dp));
    mMax = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> data[i][j];
            int t = find(i, j);
            if (t > mMax)
                mMax = t;
        }
    }
    cout << mMax << endl;
    return 0;
}
