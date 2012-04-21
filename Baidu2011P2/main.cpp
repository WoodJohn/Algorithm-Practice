#include <stdio.h>
#include <string.h>
#define MAX 99999999
using namespace std;

int a, b;
int n;
int dp[101][101];
bool tree[101][101];

int find(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];
    if (x > 0)
    {
        int temp = 0;
        for (int i = y + 1; i < y + 15 && i < b; i++)
        {
            if (tree[x + 27][i])
            {
                temp++;
            }
        }
        for (int i = y + 1; i < y + 15 && i < b; i++)
        {
            if (tree[x][i])
            {
                temp--;
            }
        }
        dp[x][y] = find(x - 1, y) + temp;
        return dp[x][y];
    }
    else if (y > 0)
    {
        int temp = 0;
        for (int i = x + 1; i < x + 28 && x < a; i++)
        {
            if (tree[i][y + 14])
            {
                temp++;
            }
        }
        for (int i = x + 1; i < x + 28 && i < a; i++)
        {
            if (tree[i][y])
            {
                temp--;
            }
        }
        dp[x][y] = find(x, y - 1) + temp;
        return dp[x][y];
    }
}

int main()
{
    while (scanf("%d %d", &a, &b))
    {
        if (a == 0 && b == 0)
            break;
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        memset(tree, 0, sizeof(tree));
        dp[0][0] = 0;
        while (n--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            tree[x][y] = true;
            if (x < 28 && y < 15)
                dp[0][0]++;
        }
        int min = MAX;
        for (int i = 0; i <= a - 28; i++)
        {
            for (int j = 0; j <= b - 15; j++)
            {
                int t1 = dp[i][j];
                for (int p = 0; p <= a - 28; p++)
                {
                    for (int q = j; q <= b - 15; q++)
                    {
                        if (q < j + 15)
                        {
                            if (p + 28 < i || i + 28 < p)
                            {
                                continue;
                            }
                        }
                        int t2 = dp[p][q];
                        if (t1 + t2 < min)
                            min = t1 + t2;
                    }
                }
            }
        }
        printf("%d\n", 1);
    }
    return 0;
}
