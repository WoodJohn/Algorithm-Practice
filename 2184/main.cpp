#include <iostream>
#include <algorithm>
#define OFFSET 100000
using namespace std;

struct cow
{
    int s;
    int f;
    cow(int a = 0, int b = 0) : s(a), f(b){}
}c[105];

int dp[2 * OFFSET + 5]; //dp[i]表示其中TS值为i时另一个的最大值，非常巧妙。由于i可能为负值，需要加上一个offset
int mMax;
int l, r;

void calc(int a)
{
    cow cc = c[a];
    if (cc.s > 0)
    {
        int i;
        for (i = r; i >= l; i--)
        {
            if (dp[i + OFFSET] != -OFFSET && dp[i + OFFSET] + cc.f > dp[i + cc.s + OFFSET])
            {
                dp[i + cc.s + OFFSET] = dp[i + OFFSET] + cc.f;
                if (i + cc.s > r)
                    r = i + cc.s;
                if (i + cc.s < l)
                    l = i + cc.s;
            }
        }
        if (dp[cc.s + OFFSET] < cc.f)
        {
            dp[cc.s + OFFSET] = cc.f;
            if (cc.s > r)
                r = cc.s;
            if (cc.s < l)
                l = cc.s;
        }
    }
    else
    {
        int i;
        for (i = l; i <= r; i++)
        {
            if (dp[i + OFFSET] != -OFFSET && dp[i + OFFSET] + cc.f > dp[i + cc.s + OFFSET])
            {
                dp[i + cc.s + OFFSET] = dp[i + OFFSET] + cc.f;
                if (i + cc.s > r)
                    r = i + cc.s;
                if (i + cc.s < l)
                    l = i + cc.s;
            }
        }
        if (dp[cc.s + OFFSET] < cc.f)
        {
            dp[cc.s + OFFSET] = cc.f;
            if (cc.s > r)
                r = cc.s;
            if (cc.s < l)
                l = cc.s;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int i;
    for (i = 0; i < 2 * OFFSET + 5; i++)
        dp[i] = -OFFSET;
    mMax = 0;
    l = OFFSET;
    r = -OFFSET;
    for (i = 0; i < n; i++)
    {
        cin >> c[i].s >> c[i].f;
        calc(i);
    }
    for (i = 0; i <= OFFSET; i++)
    {
        if (dp[i + OFFSET] >= 0 && dp[i + OFFSET] + i > mMax)
            mMax = dp[i + OFFSET] + i;
    }
    cout << mMax << endl;
    return 0;
}
