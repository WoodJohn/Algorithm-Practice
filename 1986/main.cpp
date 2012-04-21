/*
POJ 1986
离线LCA算法（Tarjan）
算法如下（需要写并查集）：
LCA(u)
{
    makeset(u);
    an[findset(u)] = u;
    for each node t as u's child:
    {
        LCA(t);//由于是DFS，因此往往需要用visit数组来判重，否则死循环
        union(t, u);//以u为新根
        an[findset(t)] = u;
    }
    checked[u] = true;
    for each quest (u, v): //为了保证能搜索到结果，需要对u，v的两种排列都搜一次
    {
        if (checked[v])
        {
            lc[u][v] = an[findset(v)]; // 得到结果
        }
    }
}
需要好好理解算法各个步骤的含义
*/

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

struct edge
{
    int oppo;
    int dis;
};

struct quest
{
    int oppo;
    int index;
};

vector<edge> graph[40001];
vector<quest> quests[40001];
int n, m;
int f[40001];
int an[40001];
int depth[40001];
bool checked[40001];
bool used[40001];
int result[10001];
int qlen;

int findset(int a)
{
    if (f[a] != a)
        f[a] = findset(f[a]);
    return f[a];
}

void uni(int a, int b)
{
    f[findset(a)] = findset(b);
}

void LCA(int a)
{
    f[a] = a;
    an[a] = a;
    used[a] = true;
    for (int i = 0; i < graph[a].size(); i++)
    {
        edge t = graph[a][i];
        if (!used[t.oppo])
        {
            LCA(t.oppo);
            uni(t.oppo, a);
            an[findset(t.oppo)] = a;
        }
    }
    checked[a] = true;
    for (int i = 0; i < quests[a].size(); i++)
    {
        quest t = quests[a][i];
        int v = t.oppo;
        if (checked[v])
        {
            int lc = an[findset(v)];
            if (lc == v || lc == a)
            {
                result[t.index] = depth[a] > depth[v] ? depth[a] - depth[v] : depth[v] - depth[a];
            }
            else
            {
                result[t.index] = depth[v] + depth[a] - 2 * depth[lc];
            }
        }
    }
}

void init()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        graph[i].clear();
        quests[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        char c;
        int a, b, d;
        scanf("%d %d %d %c", &a, &b, &d, &c);
        edge e1, e2;
        e1.oppo = b;
        e1.dis = d;
        e2.oppo = a;
        e2.dis = d;
        graph[a].push_back(e1);
        graph[b].push_back(e2);
    }
    memset(used, 0, sizeof(used));
    memset(checked, 0, sizeof(checked));
    scanf("%d", &qlen);
    for (int i = 0; i < qlen; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        quest q1, q2;
        q1.oppo = b;
        q1.index = i;
        q2.oppo = a;
        q2.index = i;
        quests[a].push_back(q1);
        quests[b].push_back(q2);
    }
    depth[1] = 0;
}

void buildtree(int root)
{
    used[root] = true;
    for (int i = 0; i < graph[root].size(); i++)
    {
        edge t = graph[root][i];
        if (!used[t.oppo])
        {
            depth[t.oppo] = depth[root] + t.dis;
            buildtree(t.oppo);
        }
    }
}

int main()
{
    init();
    buildtree(1);
    memset(used, 0, sizeof(used));
    LCA(1);
    for (int i = 0; i < qlen; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}
