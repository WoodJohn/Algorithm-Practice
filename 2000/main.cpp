#include <iostream>
#include <string.h>
using namespace std;

int dp[10005];

int calc(int a)
{
    if (dp[a])
        return dp[a];
    int sum = 0;
    int i = 1;
    int t = a;
    while (t >= i)
    {
        t -= i;
        sum += i * i;
        i++;
    }
    if (t > 0)
        sum += t * i;
    dp[a] = sum;
    return sum;
}

int main()
{
    int n;
    memset(dp, 0, sizeof(dp));
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << n << ' ' << calc(n) << endl;
    }
    return 0;
}
