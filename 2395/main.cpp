#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 1000000001
using namespace std;

struct edge
{
    int a;
    int b;
    int l;
    friend bool operator < (edge a, edge b)
    {
        return a.l > b.l;
    }
}edges[10005];

priority_queue<edge> q;
int n, m;
bool used[2005];
int g[2005][2005];
vector<int> gv[2005];
int mMax;

void prim()
{
    int cnt = 0;
    while (cnt < n - 1)
    {
        edge t = q.top();
        q.pop();
        while (used[t.a] && used[t.b])
        {
            t = q.top();
            q.pop();
        }
        int op = used[t.a] ? t.b : t.a;
        if (t.l > mMax)
            mMax = t.l;
        used[op] = true;
        for (int i = 0; i < gv[op].size(); i++)
        {
            edge e = edges[gv[op][i]];
            int tt = e.a == op ? e.b : e.a;
            if (!used[tt])
                q.push(e);
        }
        cnt++;
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
    memset(used, false,sizeof(used));
    memset(g, -1, sizeof(g));
    mMax = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        edges[i].a = a;
        edges[i].b = b;
        edges[i].l = l;
        if (a == 1 || b == 1)
            q.push(edges[i]);
        if (g[a][b] == -1 || g[a][b] < l)
        {
            g[a][b] = g[b][a] = l;
        }
        gv[a].push_back(i);
        gv[b].push_back(i);
    }
    used[1] = true;
    prim();
    cout << mMax << endl;}
    return 0;
}
