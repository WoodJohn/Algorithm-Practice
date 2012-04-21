#include <stdlib.h>
#include <stdio.h>

struct nn
{
    int x;
    int y;
} points[131073];

int cmpxy(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    if (p.x == q.x)
        return p.y - q.y;
    return p.x - q.x;
}

int cmpyx(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    if (p.y == q.y)
        return p.x - q.x;
    return p.y - q.y;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --)
    {
        int m,n,k;
        int count = 0, sum = 0;
        scanf("%d %d %d", &m, &n, &k);
        if (k == 0)
        {
            int result;
            if (m == 1 && n == 1)
            {
                result = 0;
            }
            else if (m == 1 || n == 1)
                result = 1;
            else
                result = m + n;
            printf("%d\n", result);
            continue;
        }
        while (k --)
        {
            scanf("%d %d", &points[count].x, &points[count].y);
            count ++;
        }
        qsort(points, count, sizeof(nn), cmpxy);
        int i = 0;
        while (i < count && n > 1)
        {
            int j = i;
            if (j == 0 && m > 1)
            {
                sum += points[j].x - 1;
            }
            while (j < count - 1 && points[j].x == points[j + 1].x)
            {
                j ++;
            }
            if (points[i].y >= 3)
                sum ++;
            for (int k = i; k < j; k ++)
            {
                if (points[k + 1].y - points[k].y >= 3)
                    sum ++;
            }
            if (n - points[j].y >= 2)
                sum ++;
            i = j + 1;
            if (i < count && m > 1)
            {
                sum += points[i].x - points[j].x - 1;
            }
            else if (m > 1)
            {
                sum += n - points[j].x;
            }
        }
        qsort(points, count, sizeof(nn), cmpyx);
        i = 0;
        while (i < count && m > 1)
        {
            int j = i;
            if (j == 0 && n > 1)
            {
                sum += points[j].y - 1;
            }
            while (j < count - 1 && points[j].y == points[j + 1].y)
            {
                j ++;
            }
            if (points[i].x >= 3)
                sum ++;
            for (int  k = i; k < j; k ++)
            {
                if (points[k + 1].x - points[k].x >= 3)
                    sum ++;
            }
            if (m - points[j].x >= 2)
                sum ++;
            i = j + 1;
            if (i < count && n > 1)
            {
                sum += points[i].y - points[j].y - 1;
            }
            else if (n > 1)
            {
                sum += m - points[j].y;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
