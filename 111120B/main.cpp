#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool chosen[10];
bool can[101][1025];
int num[10];
int n;
int cur;
int p2[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

inline bool getPos(int n, int a)
{
    return n & p2[a];
}

void assign(int a)
{
    int i;
    for (i = 0; i < 10; i++)
        chosen[i] = getPos(a, i);
}

bool dtest(int a, int b)
{
    bool used[10] = {false};
    int t = a % 10;
    used[t] = true;
    if (a > 9)
    {
        t = a / 10;
        if (used[t])
            return false;
        used[t] = true;
    }
    t = b % 10;
    if (used[t])
        return false;
    used[t] = true;
    if (b > 9)
    {
        t = b / 10;
        if (used[t])
            return false;
    }
    return true;
}

bool rtest(int a, int n)
{
    int t = a;
    while (t > 0)
    {
        int p = 1 << (t % 10);
        if (!(n & p))
            return false;
        t /= 10;
    }
    return true;
}

bool atest()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!can[num[i]][cur])
            return false;
    }
    return true;
}

void pre()
{
    int i, j;
    memset(can, false, sizeof(can));
    for (i = 1; i <= 100; i++)
    {
        int t = i;
        int mask = 0;
        bool check = true;
        while (t > 0)
        {
            int p = (1 << (t % 10));
            if (mask & p)
            {
                check = false;
            }
            mask |= (1 << (t % 10));
            t /= 10;
        }
        for (j = 0; j < 1024; j++)
        {
            if ((j & mask) == mask && check)
                can[i][j] = true;
            else
            {
                int k;
                for (k = 1; k <= i / 2; k++)
                {
                    if (dtest(k , i - k))
                    {
                        if (rtest(k, j) && rtest(i - k, j))
                        {
                            can[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int i;
    int cnt = 0;
    pre();
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        cnt++;
        for (i = 0; i < n; i++)
            scanf("%d", &num[i]);
        printf("Case %d: ", cnt);
        long long mMin = 9999999999;
        for (cur = 1; cur < 1024; cur++)
        {
            assign(cur);
            if (atest())
            {
                int res = 0;
                for (i = 9; i >= 0; i--)
                {
                    if (chosen[i])
                    {
                        res = 10 * res + i;
                    }
                }
                if (res < mMin)
                    mMin = res;
            }
        }
        cout << mMin << endl;
    }
    return 0;
}
