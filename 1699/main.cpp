#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

string strs[11];
int cs[11][11];
int t, n;
bool used[11];
int mMin;

void calc(int a, int b)
{
    int len = strs[a].length();
    int mMax = 0;
    int pos = len - 1;
    while (pos >= 0)
    {
        if (strs[a][pos] == strs[b][0])
        {
            int apos = pos;
            int bpos = 0;
            while (apos < len)
            {
                if (strs[a][apos] != strs[b][bpos])
                    break;
                apos++;
                bpos++;
            }
            if (apos == len)
            {
                if (len - pos > mMax)
                    mMax = len - pos;
            }
        }
        pos--;
    }
    cs[a][b] = mMax;
}

void dfs(int a, int cur, int pre)
{
    if (cur >= mMin)
        return;
    if (a == n)
    {
        if (cur < mMin)
            mMin = cur;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            if (pre == -1)
            {
                dfs(a + 1, cur + strs[i].length(), i);
            }
            else
            {
                dfs(a + 1, cur + strs[i].length() - cs[pre][i], i);
            }
            used[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            cin >> strs[i];
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                calc(i, j);
                calc(j, i);
            }
        }
        mMin = 1 << 30;
        memset(used, 0, sizeof(used));
        dfs(0, 0, -1);
        printf("%d\n", mMin);
    }
    return 0;
}
