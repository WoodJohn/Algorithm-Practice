/*
POJ 1159
DP«ÛLCS
*/

#include <stdio.h>

char s1[5005], s2[5005];
int dp[2][5005];

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    scanf("%s", s1);
    for (i = 0; i < n; i++)
    {
        dp[0][i] = dp[1][i] = 0;
        s2[n - i - 1] = s1[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s1[i] == s2[j])
            {
                if (i == 0 || j == 0)
                    dp[i % 2][j] = 1;
                else
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                }
            }
            else
            {
                if (i > 0)
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
                }
                if (j > 0)
                {
                    if (dp[i % 2][j] < dp[i % 2][j - 1])
                    {
                        dp[i % 2][j] = dp[i % 2][j - 1];
                    }
                }
            }
        }
    }
    printf("%d\n", n - dp[(n - 1) % 2][n - 1]);
    return 0;
}
