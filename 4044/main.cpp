#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int num1[35], num2[35];
int t1[35], t2[35];
int dp[35][35];

bool cmp(int a, int b)
{
    if (a % 10 == b % 10)
        return a < b;
    return a % 10 < b % 10;
}

int calc(int a, int b)
{
    if (a < 0 || b < 0)
        return 0;
    if (dp[a][b] != -1)
        return dp[a][b];
    if (t1[a] != t2[b])
    {
        dp[a][b] = 0;
        return 0;
    }
    dp[a][b] = calc(a - 1, b - 1) + 1;
    return dp[a][b];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        int i, j;
        for (i = 0; i < n1; i++)
        {
            cin >> num1[i];
        }
        for (i = 0; i < n2; i++)
        {
            cin >> num2[i];
        }
        sort(num1, num1 + n1, greater<int>());
        sort(num2, num2 + n2, greater<int>());
        int cnt1 = 0;
        for (i = 0; i < n1; i++)
        {
            if (i > 0)
            {
                if (num1[i] == num1[i - 1])
                    continue;
            }
            t1[cnt1++] = num1[i];
        }
        int cnt2 = 0;
        for (i = 0; i < n2; i++)
        {
            if (i > 0)
            {
                if (num2[i] == num2[i - 1])
                    continue;
            }
            t2[cnt2++] = num2[i];
        }
        int mMax = 0;
        int maxi = 0;
        memset(dp, -1, sizeof(dp));
        for (i = 0; i < cnt1; i++)
        {
            for (j = 0; j < cnt2; j++)
            {
                int t = calc(i, j);
                if (t > mMax)
                {
                    mMax = t;
                    maxi = i;
                }
                else if (t == mMax)
                {
                    if (t1[i - t + 1] > t1[maxi - t + 1])
                    {
                        maxi = i;
                    }
                }
            }
        }
        if (mMax == 0)
        {
            cout << "NONE" << endl;
            continue;
        }
        int res[35];
        int cnt = 0;
        for (i = maxi - mMax + 1; i <= maxi; i++)
        {
            res[cnt++] = t1[i];
        }
        for (i = 0; i < cnt - 1; i++)
        {
            cout << res[i] << ' ';
        }
        cout << res[cnt - 1] << endl;
        sort(res, res + cnt, cmp);
        for (i = 0; i < cnt - 1; i++)
        {
            cout << res[i] << ' ';
        }
        cout << res[cnt - 1] << endl;
    }
    return 0;
}
