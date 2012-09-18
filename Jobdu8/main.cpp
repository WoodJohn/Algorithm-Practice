#include <iostream>
#include <stdio.h>
using namespace std;

int m,n;
int num[1005][1005];

void out(int y, int x, int w, int h)
{
    for (int i = x; i < x + w; i++)
    {
        printf("%d ", num[y][i]);
    }
    for (int i = y + 1; i < y + h; i++)
    {
        printf("%d ", num[i][x + w - 1]);
    }
    if (h > 1)
    {
        for (int i = x + w - 2; i >= x; i--)
        {
            printf("%d ", num[y + h - 1][i]);
        }
    }
    if (w > 1)
    {
        for (int i = y + h - 2; i > y; i--)
        {
            printf("%d ", num[i][x]);
        }
    }
}

int main()
{
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &num[i][j]);
            }
        }
        int mmin = m < n ? m : n;
        for (int i = 0; i < (mmin + 1) / 2; i++)
        {
            out(i, i, n - i * 2, m - i * 2);
        }
        printf("\n");
    }
    return 0;
}
