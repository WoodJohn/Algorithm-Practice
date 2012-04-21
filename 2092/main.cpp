#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nn
{
    int v;
    int index;
} num[10001];

int cmp(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    if (p.v == q.v)
    {
        return p.index - q.index;
    }
    return q.v - p.v;
}

int main()
{
    int n,m;
    while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0))
    {
        for (int i = 0; i < 10001; i ++)
        {
            num[i].v = 0;
            num[i].index = i;
        }
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
            {
                int t;
                scanf("%d", &t);
                num[t].v ++;
            }
        }
        qsort(num, 10001, sizeof(nn), cmp);
        int pos = 1;
        while (num[pos].v == num[pos - 1].v)
            pos ++;
        while (num[pos].v == num[pos + 1].v && pos < 10000)
        {
            printf("%d ", num[pos].index);
            pos ++;
        }
        printf("%d\n",num[pos].index);
    }
    return 0;
}
