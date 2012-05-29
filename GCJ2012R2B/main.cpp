#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
int w, l;
struct circle
{
    int index;
    int r;
}c[1001];

struct point
{
    double x;
    double y;
}p[1001];

bool cmp(circle a, circle b)
{
    return b.r > a.r;
}

bool check(point pp, int a)
{
    if (pp.x > w || pp.y > l)
        return false;
    int i;
    for (i = 0; i < n; i++)
    {
        if (p[i].x < 0)
            continue;
        if ((long long)(p[i].x - pp.x) * (p[i].x - pp.x) + (p[i].y - pp.y) * (p[i].y - pp.y) < (long long)(c[i].r + c[a].r) * (c[i].r + c[a].r))
            return false;
    }
    return true;
}

bool searchV(int a)
{
    int i;
    point pp;
    for (i = 0; i < a; i++)
    {
        pp.x = p[i].x;
        pp.y = p[i].y + c[i].r + c[a].r;
        if (check(pp, a))
        {
            p[a].x = pp.x;
            p[a].y = pp.y;
            return true;
        }
    }
    return false;
}

bool searchH(int a)
{
    int i;
    point pp;
    for (i = 0; i < a; i++)
    {
        pp.x = p[i].x + c[i].r + c[a].r;
        pp.y = p[i].y;
        if (check(pp, a))
        {
            p[a].x = pp.x;
            p[a].y = pp.y;
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    int i;
    FILE *out = fopen("out.out", "w");
    for (i = 1; i <= t; i++)
    {
        cin >> n >> w >> l;
        int j;
        for (j = 0; j < n; j++)
        {
            cin >> c[j].r;
            c[j].index = j;
        }
        for (j = 0; j < n; j++)
        {
            p[j].x = p[j].y = -1.0;
        }
        p[0].x = 0.0;
        p[0].y = 0.0;
        int k;
        for (j = 1; j < n; j++)
        {
            if (searchV(j))
                continue;
            if (searchH(j))
                continue;
        }
        fprintf(out, "Case #%d: ", i);
        for (j = 0; j < n - 1; j++)
        {
            fprintf(out, "%lf %lf ", p[j].x, p[j].y);
        }
        fprintf(out, "%lf %lf\n", p[n - 1].x, p[n - 1].y);
    }
    return 0;
}
