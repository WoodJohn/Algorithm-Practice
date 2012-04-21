/*
POJ 1639
特定结点限制度数不大于K的MST
算法模板：先用Kruskal计算除去特定结点n0之外的其他结点的MST，然后对于该MST中的每个连通分量，
找到其中与n0权值最小的一个，使其与n0相连（一定可以找到，否则该图不是连通图）。如果n0的度数
N大于K则无解（Why？），否则做K - N次如下处理：枚举所有与n0有通路但在当前树中还未与n0相连的
点，先将该点与n0相连（这样必然导致产生一个环），设该边权值为w1，然后从该环中找到一条不与n0
相连且权值最大的边，设该权值为w2。删掉该边，则整体权值之和减小了（w2 - w1）。注意w2不能小于
w1，即在寻找最大值时要将w1设为mMax的初始值。通过枚举，找到最大的这样的（w2 - w1），即实现了
给当前树中的n0增加一个度数，且为整棵树的权值之和减少了max（w2 - w1）。若在枚举中发现（w2 - w1）
的最大值为0，则说明已经无法优化，可以跳出枚举，输出结果。
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    string name;
    int w[21];
    node()
    {
        memset(w, 0, sizeof(w));
    }
}nodes[21];

struct edge
{
    int from;
    int to;
    int w;
    bool used;
}edges[801];

bool myless(edge e1, edge e2)
{
    return e1.w < e2.w;
}

int n;
int cars;
int nodecnt;
int edgecnt;
int sets[21];
bool adj[21][21]= {false};
bool used[21];

int findroot(int a)
{
    if (sets[a] != a)
    {
        sets[a] = findroot(sets[a]);
    }
    return sets[a];
}

void joint(int a, int b)
{
    int r1 = findroot(a);
    int r2 = findroot(b);
    sets[r1] = r2;
}

int findname(string name)
{
    for (int i = 0; i < nodecnt; i++)
    {
        if (name == nodes[i].name)
            return i;
    }
    return -1;
}

int start;
int sp, tp;
int tempMax;

bool dfs(int current)
{
    bool check = false;
    used[current] = true;
    for (int i = 0; i < nodecnt; i++)
    {
        if (nodes[current].w[i] != 0 && adj[current][i])
        {
            int t = 0;
            if (used[i] && i == 0)
            {
                if (current == start)
                    continue;
                else
                {
                    return true;
                }
            }
            else if (!used[i])
            {
                t = dfs(i);
                if (!t)
                    continue;
                else
                    check = true;
                t = nodes[current].w[i];
                if (t > tempMax)
                {
                    tempMax = t;
                    sp = current;
                    tp = i;
                }
            }
        }
    }
    return check;
}

int main()
{
    nodecnt = edgecnt = 0;
    int total = 0;
    cin >> edgecnt;
    node n0;
    n0.name = "Park";
    nodes[nodecnt++] = n0;
    for (int i = 0; i < edgecnt; i++)
    {
        string n1, n2;
        int dis;
        cin >> n1 >> n2 >> dis;
        int p1 = findname(n1);
        int p2 = findname(n2);
        if (p1 == -1)
        {
            node nn;
            nn.name = n1;
            p1 = nodecnt;
            nodes[nodecnt++] = nn;
        }
        if (p2 == -1)
        {
            node nn;
            nn.name = n2;
            p2 = nodecnt;
            nodes[nodecnt++] = nn;
        }
        nodes[p1].w[p2] = dis;
        nodes[p2].w[p1] = dis;
        edge ee;
        ee.from = p1;
        ee.to = p2;
        ee.w = dis;
        edges[i] = ee;
    }
    cin >> cars;
    for (int i = 0; i < nodecnt; i++)
    {
        sets[i] = i;
    }
    sort(edges, edges + edgecnt, myless);
    for (int i = 0; i < edgecnt; i++)
    {
        edge e = edges[i];
        if (e.from == 0 || e.to == 0)
            continue;
        if (findroot(e.from) != findroot(e.to))
        {
            joint(e.from, e.to);
            total += e.w;
            adj[e.from][e.to] = adj[e.to][e.from] = true;
        }
    }
    vector<int> branches[21];
    int cnt = 0;
    memset(used, 0, sizeof(used));
    for (int i = 1; i < nodecnt; i++)
    {
        int t = findroot(i);
        if (!used[t])
        {
            branches[cnt].push_back(t);
            branches[cnt].push_back(i);
            cnt++;
            used[t] = true;
        }
        else
        {
            int pos;
            for (pos = 0; pos < cnt; pos++)
            {
                if (branches[pos][0] == t)
                    break;
            }
            branches[pos].push_back(i);
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        int mMin = 1 << 30;
        int minN;
        for (int j = 1; j < branches[i].size(); j++)
        {
            int t = branches[i][j];
            if (nodes[0].w[t] != 0 && nodes[0].w[t] < mMin)
            {
                mMin = nodes[0].w[t];
                minN = t;
            }
        }
        adj[0][minN] = adj[minN][0] = true;
        total += mMin;
    }
    if (cnt < cars)
    {
        for (int i = 0; i < cars - cnt; i++)
        {
            int mMax = 0;
            int todels, todelt;
            int toadd;
            for (start = 1; start < nodecnt; start++)
            {
                if (nodes[0].w[start] != 0 && !adj[0][start])
                {
                    tempMax = nodes[0].w[start];
                    memset(used, 0, sizeof(used));
                    adj[0][start] = adj[start][0] = true;
                    used[0] = true;
                    dfs(start);
                    adj[0][start] = adj[start][0] = false;
                    int temp = tempMax - nodes[0].w[start];
                    if (temp > mMax)
                    {
                        mMax = temp;
                        todels = sp;
                        todelt = tp;
                        toadd = start;
                    }
                }
            }
            if (mMax == 0)
                break;
            total -= mMax;
            adj[toadd][0] = adj[0][toadd] = true;
            adj[todels][todelt] = adj[todelt][todels] = false;
        }
    }
    printf("Total miles driven: %d\n", total);
    return 0;
}
