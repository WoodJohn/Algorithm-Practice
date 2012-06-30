#include <iostream>
#include <string.h>
using namespace std;

int n, m;
long long dp[15][2005];

int main()
{
    int c;
    cin >> c;
    int i;
    for (i = 1; i <= c; i++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        int j;
        for (j = 1; j <= m; j++)
        {
            dp[1][j] = 1;
        }
        int k, p;
        for (k = 2; k <= n; k++)
        {
            for (j = 1 << (k - 1); j <= m; j++)
            {
                long long sum = 0;
                for (p = 1 << (k - 2); p <= j / 2; p++)
                {
                    sum += dp[k - 1][p];
                }
                dp[k][j] = sum;
            }
        }
        long long s = 0;
        for (j = 1 << (n - 1); j <= m; j++)
            s += dp[n][j];
        cout << "Case " << i << ": n = " << n << ", m = " << m << ", # lists = " << s << endl;
    }
    return 0;
}
