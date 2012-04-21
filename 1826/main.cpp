/*
POJ 1826
DFS + HASH
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#define N 100007
using namespace std;

int n;

struct point
{
    int x;
    int y;
    int v;
    bool used;
};

int data[200001][2];

vector<point> v[N];

int key(int x, int y)
{
    return ((x * x) % N + (y * y) % N) % N;
}

int find(int x, int y)
{
    int k = key(x, y);
    for (int i = 0; i < v[k].size(); i++)
    {
        if (v[k][i].x == x && v[k][i].y == y)
        {
            if (!v[k][i].used)
            {
                v[k][i].used = true;
                return v[k][i].v;
            }
            else
            {
                return -1;
            }
        }
    }
    return -1;
}

int dfs(int x, int y)
{
    int t = find(x, y);
    if (t == -1)
        return 0;
    int t1 = dfs(x - 1, y);
    if (t1 != -1)
        t += t1;
    int t2 = dfs(x + 1, y);
    if (t2 != -1)
        t += t2;
    int t3 = dfs(x, y - 1);
    if (t3 != -1)
        t += t3;
    int t4 = dfs(x, y + 1);
    if (t4 != -1)
        t += t4;
    return t;
}

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        for (int i = 0; i < N; i++)
            v[i].clear();
        for (int i = 0; i < n; i++)
        {
            point p;
            scanf("%d%d%d", &p.x, &p.y, &p.v);
            p.used = false;
            data[i][0] = p.x;
            data[i][1] = p.y;
            v[key(p.x, p.y)].push_back(p);
        }
        int mMax = 0;
        for (int i = 0; i < n; i++)
        {
            int t = dfs(data[i][0], data[i][1]);
            if (t > mMax)
                mMax = t;
        }
        printf("%d\n", mMax);
    }
    return 0;
}
