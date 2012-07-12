#include <stdio.h>

struct card
{
    int top;
    int bottom;
}c[5005];

int n, m, x1, x2, y1, y2;

bool left(int x, int y, int a)
{
    int xx1 = c[a].top;
    int xx2 = c[a].bottom;
    if (xx1 == xx2)
        return x < xx1;
    double tx = xx2 - double(y - y2) * (xx2 - xx1) / (y1 - y2);
    return x < tx;
}

bool check(int x, int y, int a)
{
    return left(x, y, a + 1);
}

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
        c[0].top = x1;
        c[0].bottom = x1;
        c[n + 1].top = x2;
        c[n + 1].bottom = x2;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &c[i].top, &c[i].bottom);
        }
        int cnt[5005] = {0};
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            for (int j = 0; j <= n; j++)
            {
                if (check(a, b, j))
                {
                    cnt[j]++;
                    break;
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            printf("%d: %d\n", i, cnt[i]);
        }
        printf("\n");
    }
    return 0;
}
