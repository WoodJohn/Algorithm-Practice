#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

struct road
{
    int op;
    int w;
};

struct dis
{
    int index;
    int d;
    bool taken;
    dis()
    {
        taken = false;
    }
}d[100001];

class cmp
{
public:
    bool operator()(const dis &d1, const dis &d2)
    {
        return d1.d > d2.d;
    }
};

vector<road> g[100001];
priority_queue<dis, vector<dis>, cmp> dd;
int n, m, s, l;

void init()
{
    scanf("%d%d%d", &n, &m, &s);
    int i;
    for (i = 1; i <= n; i++)
    {
        d[i].index = i;
        d[i].d = INF;
    }
    d[s].d = 0;
    for (i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        road r1, r2;
        if (a == s)
        {
            d[b].d = c;
        }
        else if (b == s)
        {
            d[a].d = c;
        }
        r1.op = b;
        r2.op = a;
        r1.w = r2.w = c;
        g[a].push_back(r1);
        g[b].push_back(r2);
    }
    for (i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        dd.push(d[i]);
    }
    scanf("%d", &l);
}

void relax(int u, int v, int w)
{
    if (d[v].d > d[u].d + w)
    {
        d[v].d = d[u].d + w;
        dd.push(d[v]);
    }
}

void calc()
{
    int cnt = 1;
    int i;
    while (cnt < n)
    {
        dis td = dd.top();
        dd.pop();
        while (d[td.index].taken)
        {
            td = dd.top();
            dd.pop();
        }
        d[td.index].taken = true;
        cnt++;
        int index = td.index;
        for (i = 0; i < g[index].size(); i++)
        {
            if (g[index][i].op == s)
                continue;
            relax(index, g[index][i].op, g[index][i].w);
        }
    }
    int res = 0;
    int j;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < g[i].size(); j++)
        {
            int from = i;
            int to = g[i][j].op;
            if ((d[from].d > l && d[to].d < l) || (d[from].d < l && d[to].d > l))
            {
                res++;
            }
            else if (d[from].d < l && d[to].d < l)
            {
                int max = d[from].d > d[to].d ? d[from].d : d[to].d;
                int min = d[from].d + d[to].d - max;
                if (max - min < g[i][j].w)
                {
                    if (l - min + l - max < g[i][j].w)
                    {
                        res += 2;
                    }
                    else if (l - min + l - max == g[i][j].w)
                    {
                        res++;
                    }
                }
            }
            else if ((d[from].d == l && d[to].d < l) || (d[from].d < l && d[to].d == l))
            {
                int max = d[from].d > d[to].d ? d[from].d : d[to].d;
                int min = d[from].d + d[to].d - max;
                if (l - min < g[i][j].w)
                    res++;
            }
        }
    }
    res /= 2;
    for (i = 1; i <= n; i++)
    {
        if (d[i].d == l)
            res++;
    }
    cout << res << endl;
}

int main()
{
    init();
    calc();
    return 0;
}
