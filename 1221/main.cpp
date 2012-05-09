#include <iostream>
#include <string.h>
using namespace std;

long long dp[1001][1001];
long long res[1001];

long long c1(int a, int b)
{
    if (a < b)
        return 0;
    if (a == b)
        return 1;
    if (dp[a][b] != 0)
        return dp[a][b];
    int i;
    long long sum = 0;
    for (i = 1; i <= b; i++)
    {
        sum += c1(a - b, i);
    }
    dp[a][b] = sum;
    return sum;
}

long long c2(int a)
{
    if (res[a] != 0)
        return res[a];
    int i;
    if (a % 2)
    {
        long long sum = 0;
        for (i = 1; i <= a; i += 2)
        {
            int j;
            for (j = i; j >= 0; j--)
            {
                sum += c1((a - i) / 2, j);
            }
        }
        res[a] = sum;
        return sum;
    }
    else
    {
        long long sum = 0;
        for (i = 1; i <= a / 2; i++)
        {
            sum += c1(a / 2, i);
        }
        for (i = 2; i <= a; i += 2)
        {
            int j;
            for (j = i; j >= 0; j--)
            {
                sum += c1((a - i) / 2, j);
            }
        }
        res[a] = sum;
        return sum;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        dp[1][1] = 1;
        memset(dp, 0, sizeof(dp));
        memset(res, 0, sizeof(res));
        cout << n << ' ' << c2(n) << endl;
    }
    return 0;
}
