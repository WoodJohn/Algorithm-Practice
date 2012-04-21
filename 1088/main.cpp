#include <stdio.h>
#include <string.h>

int data[100][100];
int dp[100][100];
int r,c;

int find(int a, int b)
{
    if (dp[a][b] != 0)
        return dp[a][b];
    int temp = 0;
    int max = 0;
    if (a > 0)
    {
        if (data[a][b] > data[a - 1][b])
            temp = find(a - 1, b);
        if (temp > max)
            max = temp;
    }
    if (b > 0)
    {
        if (data[a][b] > data[a][b - 1])
            temp = find(a, b - 1);
        if (temp > max)
            max = temp;
    }
    if (a < r - 1)
    {
        if (data[a][b] > data[a + 1][b])
            temp = find(a + 1, b);
        if (temp > max)
            max = temp;
    }
    if (b < c - 1)
    {
        if (data[a][b] > data[a][b + 1])
            temp = find(a, b + 1);
        if (temp > max)
            max = temp;
    }
    max ++;
    dp[a][b] = max;
    return max;
}

int main()
{
    scanf("%d %d", &r, &c);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < r; i ++)
    {
        for (int j = 0; j < c; j ++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    int max = 0;
    for (int i = 0; i < r; i ++)
    {
        for (int j = 0; j < c; j ++)
        {
            int t = find(i, j);
            if (t > max)
                max = t;
        }
    }
    printf("%d\n", max);
    return 0;
}
