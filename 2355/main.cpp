#include <iostream>
#include <stdio.h>
#define INF 1000000000
using namespace std;

inline int min(int a, int b)
{
    return a > b ? b : a;
}

int l1, l2, l3, c1, c2, c3, n;

int dp[10005];
int dis[10005];

int main()
{
    scanf("%d%d%d%d%d%d", &l1, &l2, &l3, &c1, &c2, &c3);
    scanf("%d", &n);
    int start, end;
    scanf("%d%d", &start, &end);
    int s = start + end;
    start = min(start, end);
    end = s - start;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &dis[i]);
        dp[i] = INF;
    }
    dp[start] = 0;
    for (int i = start + 1; i <= end; i++)
    {
        for (int j = i - 1; j >= start; j--)
        {
            int t = dis[i] - dis[j];
            if (t <= l3)
            {
                int cost;
                if (t > l2)
                    cost = c3;
                else if (t > l1)
                    cost = c2;
                else
                    cost = c1;
                if (cost + dp[j] < dp[i])
                    dp[i] = cost + dp[j];
            }
            else
            {
                break;
            }
        }
    }
    cout << dp[end] << endl;
    return 0;
}
