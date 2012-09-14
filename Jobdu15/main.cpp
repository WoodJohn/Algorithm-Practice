#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int v;
    int start;
}dp[100005];

int n;
int num[100005];

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        int mMax = -1005;
        int maxS = -1;
        int maxE = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            if (i == 0)
            {
                dp[i].v = num[i];
                dp[i].start = i;
            }
            else
            {
                if (dp[i - 1].v >= 0)
                {
                    dp[i].v = dp[i - 1].v + num[i];
                    dp[i].start = dp[i - 1].start;
                }
                else
                {
                    dp[i].v = num[i];
                    dp[i].start = i;
                }
            }
            if (dp[i].v > mMax)
            {
                mMax = dp[i].v;
                maxS = dp[i].start;
                maxE = i;
            }
        }
        printf("%d %d %d\n", mMax, maxS, maxE);
    }
    return 0;
}
