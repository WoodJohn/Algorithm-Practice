#include <stdio.h>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct point
{
    int x;
    int y;
    int p;
} field[2501];

int cmp(const void *a, const void *b)
{
    point p = *((point *)a);
    point q = *((point *)b);
    return q.p - p.p;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int k,m,n,t;
    scanf("%d", &t);
    while (t --)
    {
        int count = 0;
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < m; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                int temp;
                scanf("%d", &temp);
                if (temp > 0)
                {
                    field[count].p = temp;;
                    field[count].y = i;
                    field[count].x = j;
                    count ++;
                }
            }
        }
        qsort(field, count, sizeof(point), cmp);
        int pos = 0;
        int sum = 0;
        k -= 2 + field[pos].y + 1;
        while (k >= field[pos].y)
        {
            sum += field[pos ++].p;
            k -= abs(field[pos].x - field[pos - 1].x) + abs(field[pos].y - field[pos - 1].y) + 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}
