#include <iostream>
#include <string.h>
using namespace std;

bool g[15][15];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline int min(int a, int b)
{
    return a < b ? a : b;
}

struct straw
{
    int x1, x2, y1, y2;
}s[15];

bool check(int a, int b)
{
    straw s1 = s[a];
    straw s2 = s[b];
    if (s1.x1 == s1.x2 && s2.x1 == s2.x2) //parallel with Y
    {
        return (s1.x1 == s2.x1 && (s1.y2 >= s2.y1 && s1.y1 <= s2.y2));
    }
    else
    {
        if ((s1.y2 - s1.y1) * (s2.x2 - s2.x1) == (s1.x2 - s1.x1) * (s2.y2 - s2.y1)) // parallel
        {
            if ((s1.x2 - s1.x1) * (s2.y1 - s1.y1) == (s2.x1 - s1.x1) * (s1.y2 - s1.y1)) // same line
            {
                return (s2.x1 >= s1.x1 && s2.x1 <= s1.x2);
            }
            return false;
        }
        else
        {
            double y;
            double x = double((s2.y1 * s2.x2 - s2.y2 * s2.x1) * (s1.x1 - s1.x2) - (s1.y1 * s1.x2 - s1.y2 * s1.x1) * (s2.x1 - s2.x2)) / (double)((s1.y2 - s1.y1) * (s2.x1 - s2.x2) - (s2.y2 - s2.y1) * (s1.x1 - s1.x2));
            if (s1.x1 != s1.x2)
            {
                y = (double)(s1.y1 * s1.x2 - s1.x1 * s1.y2 + x * (s1.y2 - s1.y1)) / (double)(s1.x2 - s1.x1);
            }
            else
            {
                y = (double)(s2.y1 * s2.x2 - s2.x1 * s2.y2 + x * (s2.y2 - s2.y1)) / (double)(s2.x2 - s2.x1);
            }
            return (x >= s1.x1 && x <= s1.x2 && x >= s2.x1 && x <= s2.x2 && y >= min(s1.y1, s1.y2) && y <= max(s1.y1, s1.y2) && y >= min(s2.y1, s2.y2) && y <= max(s2.y1, s2.y2));
        }
    }
}

int main()
{
    int n, i;
    while (cin >> n)
    {
        if (n == 0)
            break;
        memset(g, false, sizeof(g));
        for (i = 1; i <= n; i++)
        {
            g[i][i] = true;
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int tmp;
            if (a > c || (a == c && b > d))
            {
                tmp = a;
                a = c;
                c = tmp;
                tmp = b;
                b = d;
                d = tmp;
            }
            s[i].x1 = a;
            s[i].x2 = c;
            s[i].y1 = b;
            s[i].y2 = d;
        }
        int j, k;
        for (i = 1; i < n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                g[i][j] = g[j][i] = check(i, j);
            }
        }
        for (k = 1; k <= n; k++)
        {
            for (i = 1; i < n; i++)
            {
                for (j = i + 1; j <= n; j++)
                {
                    if (g[i][j])
                        continue;
                    if (g[i][k] && g[k][j])
                        g[i][j] = g[j][i] = true;
                }
            }
        }
        int a, b;
        while (cin >> a >> b)
        {
            if (a == b && b == 0)
                break;
            if (g[a][b])
                cout << "CONNECTED" << endl;
            else
                cout << "NOT CONNECTED" << endl;
        }
    }
    return 0;
}
