#include <stdio.h>
#include <stdlib.h>

#define N 100

bool tree[101][101] = {false};


struct nn
{
    int x;
    int y;
    int z;
} data[100001];

int cmp(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    return p.z - q.z;
}

int lowbit(int x)
{
    return x&(-x);
}

void update(int x, int y)
{
    int i,j;
    for (i = x; i <= N; i += lowbit(i))
    {
        for (j = y; j <= N; j += lowbit(j))
        {
            tree[i][j] = true;
        }
    }
}

bool sum(int x, int y)
{
    int res = 0;
    int i,j;
    for (i = x; i > 0; i -= lowbit(i))
    {
        for (j = y; j > 0; j -= lowbit(j))
        {
            if (tree[i][j])
                return true;
        }
    }
    return false;
}

int main()
{
    int a,b,c;
    int n;
    scanf("%d", &n);
    int count = 0;
    while (n --)
    {
        scanf("%d %d %d", &a, &b, &c);
        data[count].x = a;
        data[count].y = b;
        data[count ++].z = c;
    }
    qsort(data, count, sizeof(nn), cmp);
    int s = 0;
    int i = 0;
    while (i < count)
    {
        int temp = i;
        while (data[i].z == data[i + 1].z && i < count - 1)
        {
            if (!sum(data[i].x - 1, data[i].y - 1))
                s ++;
            i ++;
        }
        if (!sum(data[i].x - 1, data[i].y - 1))
                s ++;
        for (int j = temp; j <= i; j ++)
        {
            update(data[j].x, data[j].y);
        }
        i ++;
    }
    printf("%d\n", s);
    return 0;
}
