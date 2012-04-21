#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct nn
{
    int small;
    int big;
}data[201];

inline int min(int a, int b)
{
    return a > b ? b : a;
}

int cmp(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    if (p.small == q.small)
    {
        return p.big - q.big;
    }
    return p.small - q.small;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        memset(data, 0, sizeof(nn));
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a = (a + 1) / 2;
            b = (b + 1) / 2;
            data[i].small = min(a, b);
            data[i].big = a + b - data[i].small;
        }
        qsort(data, n, sizeof(nn), cmp);
        int pos = 0;
        int count = 0;
        while (pos < n)
        {
            if (data[pos].big == 0)
            {
                pos++;
                continue;
            }
            int pos1 = pos + 1;
            int big = data[pos].big;
            while (pos1 < n)
            {
                if (data[pos1].big == 0 || data[pos1].small <= big)
                {
                    pos1++;
                    continue;
                }
                big = data[pos1].big;
                data[pos1].small = data[pos1].big = 0;
                pos1++;
            }
            data[pos].small = data[pos].big = 0;
            count++;
            pos++;
        }
        printf("%d\n", count * 10);
    }
    return 0;
}
