#include <iostream>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#define OFFSET 10000
using namespace std;

struct node
{
    int l;
    int r;
    int cnt;
}v[262144], h[262144];

struct segment
{
    int l;
    int len;
    int cor;
    bool isTop;
}vs[10005], hs[10005];

int cmp(const void *a, const void *b)
{
    segment p = *((segment *)a);
    segment q = *((segment *)b);
    if (p.cor == q.cor)
    {
        if (q.isTop)
            return 1;
    }
    return p.cor - q.cor;
}

void build(int l, int r, int num)
{
    v[num].l = l;
    v[num].r = r;
    h[num].l = l;
    h[num].r = r;
    v[num].cnt = h[num].cnt = 0;
    if (r - l <= 1)
        return;
    build(l, (l + r) >> 1, (num << 1) + 1);
    build((l + r) >> 1, r, (num << 1) + 2);
}

int sum;

void insertV(int l, int r, int num, bool add)
{
    node t = v[num];
    if (t.l == l && t.r == r && r - l == 1)
    {
        if (add)
        {
            v[num].cnt++;
            if (v[num].cnt == 1)
                sum++;
        }
        else
        {
            v[num].cnt--;
            if (v[num].cnt == 0)
                sum++;
        }
        return;
    }
    else
    {
        int mid = (t.l + t.r) >> 1;
        if (mid >= r)
            insertV(l, r, (num << 1) + 1, add);
        else if (mid <= l)
            insertV(l, r, (num << 1) + 2, add);
        else
        {
            insertV(l, mid, (num << 1) + 1, add);
            insertV(mid, r, (num << 1) + 2, add);
        }
    }
}

void insertH(int l, int r, int num, bool add)
{
    node t = h[num];
    if (t.l == l && t.r == r && r - l == 1)
    {
        if (add)
        {
            h[num].cnt++;
            if (h[num].cnt == 1)
                sum++;
        }
        else
        {
            h[num].cnt--;
            if (h[num].cnt == 0)
                sum++;
        }
        return;
    }
    else
    {
        int mid = (t.l + t.r) >> 1;
        if (mid >= r)
            insertH(l, r, (num << 1) + 1, add);
        else if (mid <= l)
            insertH(l, r, (num << 1) + 2, add);
        else
        {
            insertH(l, mid, (num << 1) + 1, add);
            insertH(mid, r, (num << 1) + 2, add);
        }
    }
}

int main()
{

    int n;
    while(scanf("%d", &n) != EOF){
        build(0, 32768, 0);
        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            vs[2 * i].l = y1 + OFFSET;
            vs[2 * i].len = y2 - y1;
            vs[2 * i].cor = x1 + OFFSET;
            vs[2 * i].isTop = true;
            vs[2 * i + 1].l = y1 + OFFSET;
            vs[2 * i + 1].len = y2 - y1;
            vs[2 * i + 1].cor = x2 + OFFSET;
            vs[2 * i + 1].isTop = false;
            hs[2 * i].l = x1 + OFFSET;
            hs[2 * i].len = x2 - x1;
            hs[2 * i].cor = y1 + OFFSET;
            hs[2 * i].isTop = true;
            hs[2 * i + 1].l = x1 + OFFSET;
            hs[2 * i + 1].len = x2 - x1;
            hs[2 * i + 1].cor = y2 + OFFSET;
            hs[2 * i + 1].isTop = false;
        }
        qsort(vs, 2 * n, sizeof(segment), cmp);
        qsort(hs, 2 * n, sizeof(segment), cmp);
        sum = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            insertV(vs[i].l, vs[i].l + vs[i].len, 0, vs[i].isTop);
            insertH(hs[i].l, hs[i].l + hs[i].len, 0, hs[i].isTop);
        }
        printf("%d\n", sum);
    }
    return 0;
}
