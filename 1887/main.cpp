#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int num[5005];
int dp[5005];
int cnt, t;

void calc()
{
    int i, j;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int mMax = 1;
    for (i = 1; i < cnt; i++)
    {
        int m = 1;
        for (j = 0; j < i; j++)
        {
            if (num[j] >= num[i])
            {
                int t = dp[j] + 1;
                if (t > m)
                    m = t;
            }
        }
        dp[i] = m;
        if (m > mMax)
            mMax = m;
    }
    printf("  maximum possible interceptions: %d\n", mMax);
}

int main()
{
    t = 1;
    int a;
    while (1)
    {
        cnt = 0;
        while (cin >> a)
        {
            if (a == -1)
                break;
            num[cnt++] = a;
        }
        if (cnt == 0)
            break;
        if (t > 1)
            printf("\n");
        printf("Test #%d:\n", t++);
        calc();
    }
    return 0;
}
