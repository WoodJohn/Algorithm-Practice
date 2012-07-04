#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

bool used[105];
int pre[105];
int mMin;
int last;
int n;
int out[105];

void result()
{
    int cnt = 0;
    out[cnt++] = last;
    last = pre[last];
    while (last)
    {
        out[cnt++] = last;
        last = pre[last];
    }
}

void dfs(int a, int len)
{
    if (len >= mMin)
        return;
    if (used[n - a])
    {
        if (len < mMin)
        {
            mMin = len;
            last = a;
            result();
        }
        return;
    }
    for (int i = a; i > 0; i--)
    {
        if (used[i] && i + a < n && !used[i + a])
        {
            used[i + a] = true;
            pre[i + a] = a;
            dfs(i + a, len + 1);
            used[i + a] = false;
        }
    }
}

int main()
{
    pre[1] = 0;
    while (cin >> n)
    {
        if (!n)
            break;
        if (n == 1)
        {
            cout << "1" << endl;
            continue;
        }
        memset(used, false, sizeof(used));
        mMin = 1000;
        used[1] = true;
        dfs(1, 1);
        for (int i = mMin - 1; i >= 0; i--)
            cout << out[i] << ' ';
        cout << n << endl;
    }
    return 0;
}
