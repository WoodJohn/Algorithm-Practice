#include <stdio.h>

using namespace std;

int n;
int dp[3002][2];
int ll[3002][2];
int rl[3002][2];
int data[3002][2];

int find(int a, int b)
{
    if (a == 0)
    {
        dp[a][b] = 0;
    }
    if (dp[a][b] != 0)
        return dp[a][b];
}

int main()
{
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &data[i][0], &data[i][1]);
    }

    printf("%d\n", ls + rs);
    return 0;
}
