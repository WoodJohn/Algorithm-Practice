#include <stdio.h>
#include <stdlib.h>

#define N 20000

struct nn
{
    int v;
    int x;
} cows[20001];

int cmp(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    return p.v - q.v;
}

int tc[20001] = {0};
int sc[20001] = {0};

int lowbit(int x)
{
    return x&(-x);
}

void updatetc(int x)
{
    for (int i = x; i <= N; i += lowbit(i))
    {
        tc[i] ++;
    }
}

void updatesc(int x)
{
    for (int i = x; i <= N; i += lowbit(i))
    {
        sc[i] += x;
    }
}

__int64 sumtc(int x)
{
    __int64 t = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        t += tc[i];
    }
    return t;
}

__int64 sumsc(int x)
{
    __int64 t = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        t += sc[i];
    }
    return t;
}

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    __int64 s = 0;
    int total = 0;
    while (n --)
    {
        scanf("%d %d", &cows[count].v, &cows[count].x);
        count ++;
    }
    qsort(cows, count, sizeof(nn), cmp);
    for (int i = 0; i < count; i ++)
    {
        if (i > 0)
            s += cows[i].v * (cows[i].x * sumtc(cows[i].x) - sumsc(cows[i].x) + total - sumsc(cows[i].x) - cows[i].x * (i - sumtc(cows[i].x)));
        updatetc(cows[i].x);
        updatesc(cows[i].x);
        total += cows[i].x;
    }
    printf("%I64d\n", s);
    return 0;
}
