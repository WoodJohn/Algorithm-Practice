#include <stdio.h>

struct nn
{
    int l;
    int r;
    int count;
}tree[8001 * 4];

int n;
int data[8001];
int result[8001];

void build(int p, int a, int b)
{
    tree[p].l = a;
    tree[p].r = b;
    tree[p].count = b - a + 1;
    if (a == b)
        return;
    int mid = (a + b) >> 1;
    int np = p << 1;
    build(np, a, mid);
    build(np + 1, mid + 1, b);
}

int findk(int p, int k)
{
    tree[p].count--;
    if (tree[p].l == tree[p].r)
        return tree[p].l;
    int np = p << 1;
    if (tree[np].count >= k)
        return findk(np, k);
    return findk(np + 1, k - tree[np].count);
}

int main()
{
    scanf("%d", &n);
    data[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &data[i]);
        data[i]++;
    }
    build(1, 1, n);
    for (int i = n; i >= 1; i--)
    {
        result[i] = findk(1, data[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}
