#include <iostream>
#include <string.h>
using namespace std;

int t;
int w[41];
int c[11];
int n;
int s;

bool dfs(int a)
{
    if (a == n)
    {
        return true;
    }
    int p;
    for (int i = 0; i < s; ++i)
    {
        if (w[i] < s)
        {
            p = i;
            break;
        }
    }
    for (int i = 10; i > 0; --i)
    {
        if (c[i] > 0 && p + i <= s && w[p] + i <= s)
        {
            int k;
            for (k = 0; k < i && w[p + k] + i <= s; ++k)
            {
                w[p + k] += i;
            }
            if (k == i)
            {
                --c[i];
                if (dfs(a + 1))
                    return true;
                ++c[i];
            }
            for (int pp = 0; pp < k; ++pp)
            {
                w[p + pp] -= i;
            }
        }
    }
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s >> n;
        int sum = 0;
        memset(c, 0, sizeof(c));
        int a;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            sum += a * a;
            ++c[a];
        }
        bool ans = true;
        if (sum != s * s)
        {
            ans = false;
        }
        if (ans)
        {
            memset(w, 0, sizeof(w));
            ans = dfs(0);
        }
        ans ? cout << "KHOOOOB!" << endl : cout << "HUTUTU!" << endl;
    }
    return 0;
}
