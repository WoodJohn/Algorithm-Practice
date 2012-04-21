#include <stdio.h>
#include <string.h>
#define N 200001
using namespace std;

struct nn
{
    int l;
    int r;
    int count;
} tree[4 * N];

int data[N];
int pos[N];
int result[N];
int n;

void build(int p, int a, int b)
{
    tree[p].l = a;
    tree[p].r = b;
    tree[p].count = b - a + 1;
    if (a == b)
        return;
    int np = p << 1;
    int mid = (a + b) >> 1;
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
    while (scanf("%d", &n) != EOF)
    {
//        memset(data, 0, sizeof(data));
//        memset(pos, 0, sizeof(pos));
//        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &pos[i], &data[i]);
            pos[i]++;
        }
        build(1, 1, n);
        for (int i = n; i > 0; i--)
        {
            int t = findk(1, pos[i]);
            result[t] = data[i];
        }
        for (int i = 1; i < n; i++)
        {
            printf("%d ", result[i]);
        }
        printf("%d\n", result[n]);
    }
    return 0;
}
