#include <iostream>
#include <string.h>
using namespace std;

int f, v;
int dp[105][105];
int val[105][105];

int main()
{
    cin >> f >> v;
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < v; j++)
            dp[i][j] = -999999999;
    }
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> val[i][j];
        }
    }
    int mMax = -9999999;
    for (int i = 0; i < f; i++)
    {
        for (int j = i; j <= v - f + i; j++)
        {
            if (i == 0)
                dp[i][j] = val[i][j];
            else
            {
                for (int k = i - 1; k < j; k++)
                {
                    int t = dp[i - 1][k] + val[i][j];
                    if (t > dp[i][j])
                        dp[i][j] = t;
                }
                if (i == f - 1 && dp[i][j] > mMax)
                    mMax = dp[i][j];
            }
        }
    }
    cout << mMax << endl;
    return 0;
}
