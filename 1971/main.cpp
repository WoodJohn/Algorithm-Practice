#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x;
    int y;
}points[1001], mid[1000001];

int cmp(const void *a, const void *b)
{
    point p = *((point *)a);
    point q = *((point *)b);
    if (p.x == q.x)
        return p.y - q.y;
    return p.x - q.x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        if (n < 4)
        {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; i ++)
        {
            scanf("%d %d", &(points[i].x), &(points[i].y));
        }
        int count = 0;
        for (int i = 0; i < n - 1; i ++)
        {
            for (int j = i + 1; j < n; j ++)
            {
                mid[count].x = points[i].x + points[j].x;
                mid[count ++].y = points[i].y + points[j].y;
            }
        }
        qsort(mid, count, sizeof(point), cmp);
        int pos = 0;
        int sum = 0;
        while (pos < count)
        {
            int t = pos;
            int tcount = 0;
            while (t < count - 1 && mid[t].x == mid[t + 1].x && mid[t].y == mid[t + 1].y)
            {
                tcount ++;
                t ++;
            }
            if (tcount > 0)
            {
                sum += (tcount + 1) * tcount / 2;
            }
            pos = t + 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}
