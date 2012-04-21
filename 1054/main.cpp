#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#define N 1000007
using namespace std;

struct point
{
    int x;
    int y;
    int index;
    point *next;
    point()
    {
        next = NULL;
    }
}points[5001];

bool used[5001][5001];

point *ht[N] = {NULL};
int mMax = 0;
int r, c;

int testExist(int x, int y);

inline int key(int x, int y)
{
    return (x * x + y * y) % N;
}

void insert(int a, int b, int i)
{
    int k = key(a, b);
    if (ht[k] == NULL)
    {
        ht[k] = new point();
        ht[k]->x = a;
        ht[k]->y = b;
        ht[k]->index = i;
        return;
    }
    point *cur = ht[k];
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = new point();
    cur->next->x = a;
    cur->next->y = b;
    cur->next->index = i;
}

void check(int a, int b)
{
    int i, j;
    int sum = 2;
    int stepx = points[b].x - points[a].x;
    int stepy = points[b].y - points[a].y;
    int sx = points[b].x;
    int sy = points[b].y;
    int tx = sx + stepx;
    int ty = sy + stepy;
    int prev = b;
    vector<int> r1, r2;
    while (1)
    {
        r1.push_back(prev);
        if (tx < 1 || tx > r)
            break;
        if (ty < 1 || ty > c)
            break;
        int t = testExist(tx, ty);
        if (t == -1)
        {
            for (i = 0; i < r1.size() - 1; i++)
            {
                for (j = i + 1; j < r1.size(); j++)
                    used[r1[i]][r1[j]] = used[r1[j]][r1[i]] = true;
            }
            return;
        }
        sum++;
        tx = tx + stepx;
        ty = ty + stepy;
        prev = t;
    }
    for (i = 0; i < r1.size() - 1; i++)
    {
        for (j = i + 1; j < r1.size(); j++)
            used[r1[i]][r1[j]] = used[r1[j]][r1[i]] = true;
    }
    //reverse
    sx = points[a].x;
    sy = points[a].y;
    tx = sx - stepx;
    ty = sy - stepy;
    prev = a;
    while (1)
    {
        r2.push_back(prev);
        if (tx < 1 || tx > r)
            break;
        if (ty < 1 || ty > c)
            break;
        int t = testExist(tx, ty);
        if (t == -1)
        {
            for (i = 0; i < r2.size() - 1; i++)
            {
                for (j = i + 1; j < r2.size(); j++)
                    used[r2[i]][r2[j]] = used[r2[j]][r2[i]] = true;
            }
            return;
        }
        sum++;
        tx = tx - stepx;
        ty = ty - stepy;
        prev = t;
    }
    for (i = 0; i < r2.size() - 1; i++)
    {
        for (j = i + 1; j < r2.size(); j++)
            used[r2[i]][r2[j]] = used[r2[j]][r2[i]] = true;
    }
    if (sum > 2 && sum > mMax)
        mMax = sum;
}

int testExist(int x, int y)
{
    int k = key(x, y);
    point *cur = ht[k];
    while (cur != NULL)
    {
        if (cur->x == x && cur->y == y)
            return cur->index;
        cur = cur->next;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d%d%d", &r, &c, &n);
    int i, j;
    memset(used, 0, sizeof(used));
    for (i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        points[i].x = a;
        points[i].y = b;
        points[i].index = i;
        insert(a, b, i);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (!used[i][j])
                check(i, j);
        }
    }
    cout << mMax << endl;
    return 0;
}
