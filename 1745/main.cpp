#include <stdio.h>
#include <string.h>
using namespace std;

bool dp[10001][101];
int n,k;
int data[10001];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int d;
        scanf("%d", &d);
        data[i] = (d % k + k) % k;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][data[0]] = true;
    dp[0][k - data[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j ++)
        {
            if (dp[i - 1][j])
            {
                dp[i][(j + data[i]) % k] = true;
                dp[i][(j + k - data[i]) % k] = true;
            }
        }
    }
    if (dp[n - 1][0])
        printf("Divisible\n");
    else
        printf("Not divisible\n");
    return 0;
}
