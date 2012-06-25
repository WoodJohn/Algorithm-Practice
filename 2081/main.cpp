#include <iostream>
#include <vector>
#define N 10007
using namespace std;

vector<int> ht[N];

inline int key(int a)
{
    return a % N;
}

bool find(int a)
{
    int k = key(a);
    int i;
    for (i = 0; i < ht[k].size(); i++)
    {
        if (ht[k][i] == a)
            return true;
    }
    return false;
}

void insert(int a)
{
    int k = key(a);
    ht[k].push_back(a);
}

int dp[500005] = {0};

int calc(int a)
{
    if (a == 0)
        return 0;
    if (dp[a] > 0)
        return dp[a];
    int t = calc(a - 1);
    if (t - a <= 0 || find(t - a))
    {
        dp[a] = t + a;
        if (!find(dp[a]))
        {
            insert(dp[a]);
        }
    }
    else
    {
        dp[a] = t - a;
        insert(t - a);
    }
    return dp[a];
}

int main()
{
    int n, i;
    for (i = 1; i <= 500000; i++)
        calc(i);
    while (cin >> n)
    {
        if (n == -1)
            break;
        cout << dp[n] << endl;
    }
    return 0;
}
