#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

//dp[i][j]表示i个评分的D - P值为j + 400时的最大和
//递推方程：dp[i][j] = max(dp[i - 1][j - dk + pk] + dk + pk), 1 <= k <= m
int m, n;
int dp[21][801];
int path[21][801];
int d[201];
int p[201];

bool test(int i, int j, int k)
{
    int x = i;
    int y = j + 400 - d[k] + p[k];
    int z = path[x][y];
    if (z == k)
        return false;
    while (x > 0 && z != -1)
    {
        x--;
        y = y - (d[z] - p[z]);
        z = path[x][y];
        if (z == k && x != 0)
            return false;
    }
    return true;
}

void calc()
{
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = -20 * m; j <= 20 * m; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (j - d[k] + p[k] < -20 * m || j - d[k] + p[k] > 20 * m || dp[i][j + 400 - d[k] + p[k]] == -1)
                    continue;
                if (dp[i + 1][j + 400] <= dp[i][j + 400 - d[k] + p[k]] + d[k] + p[k])
                {
                    if (test(i, j, k))
                    {
                        dp[i + 1][j + 400] = dp[i][j + 400 - d[k] + p[k]] + d[k] + p[k];
                        path[i + 1][j + 400] = k;
                    }
                }
            }
        }
    }
}

void find()
{
    int i;
    int mMax = -1;
    int maxT;
    for (i = 0; i <= m * 20; i++)
    {
        if (dp[m][400 + i] > mMax)
        {
            mMax = dp[m][400 + i];
            maxT = 400 + i;
        }
        if (dp[m][400 - i] > mMax)
        {
            mMax = dp[m][400 - i];
            maxT = 400 - i;
        }
        if (mMax >= 0)
            break;
    }
    vector<int> result;
    int pp = 0, dd = 0;
    int z = path[m][maxT];
    while (z != -1 && m > 0)
    {
        m--;
        result.push_back(z);
        pp += p[z];
        dd += d[z];
        maxT -= (d[z] - p[z]);
        z = path[m][maxT];
    }
    printf("Best jury has value %d for prosecution and value %d for defence:\n", pp, dd);
    sort(result.begin(), result.end(), less<int>());
    for (i = 0; i < result.size(); i++)
    {
        printf(" %d", result[i] + 1);
    }
    cout << endl;
}

int main()
{
    int cnt = 0;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        cnt++;
        int i;
        cout << "Jury #" << cnt << endl;
        for (i = 0; i < n; i++)
        {
            cin >> p[i] >> d[i];
        }
        memset(dp, -1, sizeof(dp));
        memset(path, -1, sizeof(path));
        dp[0][400] = 0;
        calc();
        find();
    }
    return 0;
}
