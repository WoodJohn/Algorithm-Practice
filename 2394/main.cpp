#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <string.h>
#include <stdio.h>
#define INF 999999999
using namespace std;

int g[505][505];

struct node
{
    int pos;
    int d;
}nodes[505];

bool operator < (node a, node b)
{
    return a.d > b.d;
}

priority_queue<node> q;
bool used[505];
int pos[105];
int p, c, f, m;
vector<int> gv[505];

void dijkstra()
{
    int cnt = 0;
    while (cnt < f)
    {
        node t = q.top();
        q.pop();
        while (used[t.pos])
        {
            t = q.top();
            q.pop();
        }
        int tt = t.pos;
        used[tt] = true;
        for (int i = 0; i < gv[tt].size(); i++)
        {
            int tmp = gv[tt][i];
            if (!used[tmp] && g[tt][tmp] + g[1][tt] < g[1][tmp])
            {
                g[1][tmp] = g[tt][tmp] + g[1][tt];
                nodes[tmp].d = g[1][tmp];
                q.push(nodes[tmp]);
            }
        }
        cnt++;
    }
}

int main()
{
    scanf("%d%d%d%d", &f, &p, &c, &m);
    memset(g, -1, sizeof(g));
    while (!q.empty())
        q.pop();
    for (int i = 0; i < p; i++)
    {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        if (g[a][b] == -1)
        {
            g[a][b] = g[b][a] = l;
            gv[a].push_back(b);
            gv[b].push_back(a);
        }
        else if (l < g[a][b])
            g[a][b] = g[b][a] = l;
    }
    for (int i = 1; i <= f; i++)
    {
        used[i] = false;
        nodes[i].pos = i;
        if (g[1][i] == -1)
            g[1][i] = nodes[i].d = INF;
        else
            nodes[i].d = g[1][i];
    }
    for (int i = 1; i <= c; i++)
    {
        scanf("%d", &pos[i]);
    }
    g[1][1] = 0;
    nodes[1].d = 0;
    for (int i = 1; i <= f; i++)
    {
        q.push(nodes[i]);
    }
    dijkstra();
    vector<int> res;
    for (int i = 1; i <= c; i++)
    {
        if (g[1][pos[i]] <= m)
        {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
