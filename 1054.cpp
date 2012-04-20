#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <sys/time.h>
#define N 100007
using namespace std;

struct point
{
    int x;
    int y;
    point *next;
    point()
    {
        next = NULL;
    }
}points[5001];

int cmp(const void *a, const void *b)
{
    point p = *((point *)a);
    point q = *((point *)b);
    if (p.x == q.x)
        return p.y - q.y;
    return p.x - q.x;
}

point *ht[N] = {NULL};
int mMax = 2;
int r, c;

bool testExist(int x, int y);

inline int key(int x, int y)
{
    return (x * x + y * y) % N;
}

void insert(int a, int b)
{
    int k = key(a, b);
    if (ht[k] == NULL)
    {
        ht[k] = new point();
        ht[k]->x = a;
        ht[k]->y = b;
        return;
    }
    point *cur = ht[k];
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = new point();
    cur->next->x = a;
    cur->next->y = b;
}

void check(int a, int b)
{
    int sum = 2;
    int sx = points[b].x;
    int sy = points[b].y;
    int stepx = points[b].x - points[a].x;
    int stepy = points[b].y - points[a].y;
    int tx = sx + stepx;
    int ty = sy + stepy;
    while (1)
    {
        if (tx < 1 || tx > r)
            break;
        if (ty < 1 || ty > c)
            break;
        if (!testExist(tx, ty))
        {
            return;
        }
        sum++;
        tx = tx + stepx;
        ty = ty + stepy;
    }
    //reverse
    sx = points[a].x;
    sy = points[a].y;
    tx = sx - stepx;
    ty = sy - stepy;
    while (1)
    {
        if (tx < 1 || tx > r)
            break;
        if (ty < 1 || ty > c)
            break;
        if (!testExist(tx, ty))
        {
            return;
        }
        sum++;
        tx = tx - stepx;
        ty = ty - stepy;
    }
    if (sum > mMax)
        mMax = sum;
}

bool testExist(int x, int y)
{
    int k = key(x, y);
    point *cur = ht[k];
    while (cur != NULL)
    {
        if (cur->x == x && cur->y == y)
            return true;
        cur = cur->next;
    }
    return false;
}

int main()
{
    int n;
    timeval t1, t2, t3;
    scanf("%d%d%d", &r, &c, &n);
    int i, j, a, b;
//    memset(used, 0, sizeof(used));
    gettimeofday(&t1, NULL);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        points[i].x = a;
        points[i].y = b;
        insert(a, b);
    }
    qsort(points, n, sizeof(point), cmp);
    gettimeofday(&t2, NULL);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int stepx = points[j].x - points[i].x;
            int stepy = points[j].y - points[i].y;
            if (stepx > 0)
            {
                int start = points[i].x;
                while (start - stepx > 1)
                    start -= stepx;
                if (start + (mMax - 1) * stepx >= r)
                    break;
            }
            if (stepy > 0)
            {
                int start = points[i].y;
                while (start - stepy > 1)
                    start -= stepy;
                if (start + (mMax - 1) * stepy >= c)
                    continue;
            }
            else if (stepy < 0)
            {
                int start = points[j].y;
                while (start + stepy > 1)
                    start += stepy;
                if (start + (mMax - 1) * (-stepy) >= c)
                    continue;
            }
            check(i, j);
        }
    }
    gettimeofday(&t3, NULL);
    printf("a = %u, b = %u\n", (t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_usec - t1.tv_usec) / 1000, (t3.tv_sec - t2.tv_sec) * 1000 + (t3.tv_usec - t2.tv_usec) / 1000);
    if (mMax < 3)
        mMax = 0;
    cout << mMax << endl;
    return 0;
}
