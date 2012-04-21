#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int n, h, w;
char cur;
int a[101][101];
char r[101][101];

char dfs(int y, int x, char toFill)
{
    int ty, tx;
    int min = a[y][x];
    if (y > 0)
    {
        if (a[y - 1][x] < min)
        {
            min = a[y - 1][x];
            ty = y - 1;
            tx = x;
        }
    }
    if (x > 0)
    {
        if (a[y][x - 1] < min)
        {
            min = a[y][x - 1];
            ty = y;
            tx = x - 1;
        }
    }
    if (x < w - 1)
    {
        if (a[y][x + 1] < min)
        {
            min = a[y][x + 1];
            ty = y;
            tx = x + 1;
        }
    }
    if (y < h - 1)
    {
        if (a[y + 1][x] < min)
        {
            min = a[y + 1][x];
            ty = y + 1;
            tx = x;
        }
    }
    if (min == a[y][x])
    {
        if (r[y][x] == '.')
        {
            if (toFill == '.')
            {
                r[y][x] = char(cur + 1);
                cur = cur + 1;
            }
            else
                r[y][x] = toFill;
        }
    }
    else
    {
        r[y][x] = dfs(ty, tx, toFill);
    }
    return r[y][x];
}

int main()
{
    int i;
    ofstream fout;
    fout.open("out.out", ios::out);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cur = 'a';
        cin >> h >> w;
        int j, k;
        for (j = 0; j < h; j++)
        {
            for (k = 0; k < w; k++)
            {
                cin >> a[j][k];
                r[j][k] = '.';
            }
        }
        r[0][0] = cur;
        for (j = 0; j < h; j++)
        {
            for (k = 0; k < w; k++)
            {
                dfs(j, k, r[j][k]);
            }
        }
        fout << "Case #" << i << ":" << endl;
        for (j = 0; j < h; j++)
        {
            for (k = 0; k < w - 1; k++)
            {
                fout << r[j][k] << ' ';
            }
            fout << r[j][w - 1] << endl;
        }
    }
    fout.close();
    return 0;
}
