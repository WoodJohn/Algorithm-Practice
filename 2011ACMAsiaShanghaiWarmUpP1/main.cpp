#include <string.h>
#include <stdio.h>

int t, n;
int list[100001];

inline int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int i, j;
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        memset(list, 0, sizeof(list));
        int a, b;
        scanf("%d%d%d", &n, &a, &b);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &list[j]);
        }
        __int64 total = a + b;
        int day = 1;
        int pos = 0;
        while (pos < n)
        {
            if (pos < n - 1)
            {
                int cost1 = 2 * a;
                int cost2 = (list[pos + 1] - list[pos] - 1) * b;
                total += min(cost1, cost2);
                day = list[++pos];
                total += b;
            }
            else
            {
                pos++;
            }
        }
        total += a;
        printf("Case #%d: %I64d\n", i, total);
    }
    return 0;
}
