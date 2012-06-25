#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct node
{
    int x, y;
}m[50005];

int n;

bool cmp(node a, node b)
{
    if (a.y == b.y)
        return a.x > b.x;
    return a.y > b.y;
}

int main()
{
    while (scanf("%d", &n) != -1)
    {
        if (n == 0)
            break;
        int i;
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &m[i].x, &m[i].y);
        }
        sort(m, m + n, cmp);
        int gap = m[0].x;
        int res = 1;
        for (i = 1; i < n; i++)
        {
            if (m[i].x > gap)
            {
                res++;
                gap = m[i].x;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
