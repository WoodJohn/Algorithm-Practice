#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

struct node
{
    int pos;
    long long d;
    friend bool operator < (node a, node b)
    {
        if (a.d == -1)
            return b.d != -1;
        if (b.d == -1)
            return false;
        return a.d > b.d;
    }
}nodes[2005];

priority_queue<node> q;
int n, m;
long long g[2005][2005];
vector<int> gv[2005];
int pre[2005];
bool used[2005];
int mMax = 0;

void dijkstra()
{
    int cnt = 0;
    while (cnt < n)
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
        if (pre[tt] != 0)
        {
            if (g[pre[tt]][tt] > mMax)
                mMax = g[pre[tt]][tt];
        }
        for (int i = 0; i < gv[tt].size(); i++)
        {
            int tmp = gv[tt][i];
            if (!used[tmp] && g[tt][tmp] != -1 && (g[1][tmp] == -1 || g[1][tt] + g[tt][tmp] < g[1][tmp]))
            {
                g[1][tmp] = g[1][tt] + g[tt][tmp];
                nodes[tmp].d = g[1][tmp];
                pre[tmp] = tt;
                q.push(nodes[tmp]);
            }
        }
        cnt++;
    }
}

int main()
{
    while (scanf("%d%d", &n, &m)){
        mMax = 0;
    memset(g, -1, sizeof(g));
    memset(used, false, sizeof(used));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (g[a][b] == -1)
        {
            g[a][b] = g[b][a] = c;
            gv[a].push_back(b);
        }
        else if (c < g[a][b])
        {
            g[a][b] = g[b][a] = c;
        }
    }
    g[1][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        nodes[i].pos = i;
        nodes[i].d = g[1][i];
        if (g[1][i] != -1 && i != 1)
            pre[i] = 1;
        q.push(nodes[i]);
    }
    dijkstra();
    for (int i = 2; i <= n; i++)
    {
        cout << i;
        int t = i;
        while (pre[t])
        {
            cout << "->" << pre[t];
            t = pre[t];
        }
        cout << endl;
    }
    cout << mMax << endl;}
    return 0;
}
