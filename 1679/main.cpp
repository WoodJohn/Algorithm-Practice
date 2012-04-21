/*
POJ 1679
求一个给定连通图的MST是否唯一
不使用discuss里所说的先求一次MST，然后枚举删边再求的方法，我的方法是：先求一次MST，记录边的使
用情况，然后再求一次，这次尽量使用未使用的边。若发现可以用到未使用的边，则说明不唯一。解题过程
中比较2的是开始时忘了记录pre数组的值，导致结果不对。（还是得严格按照算法方法写啊。。）
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define N 100
using namespace std;

const int INF = 1 << 30;

int n, m;

struct node
{
    int pre;
    int num;
    int c;
    int cnt;
    int list[101];
}nodes[N + 1];

struct edge
{
    int v;
    bool used;
    edge()
    {
        v = -1;
        used = false;
    }
}adj[N + 1][N + 1];

bool used[N + 1];

bool operator < (node a, node b)
{
    return a.c > b.c;
}

priority_queue<node> pq;
bool hasnew;
int total;

void bfs(int sign)
{
    node temp, cur;
    while (!pq.empty())
    {
        vector<node> same;
        same.clear();
        cur = pq.top();
        pq.pop();
        if (used[cur.num])
            continue;
        same.push_back(cur);
        if (!pq.empty())
        {
            temp = pq.top();
            while (!pq.empty() && temp.c == cur.c)
            {
                if (!used[temp.num])
                    same.push_back(temp);
                pq.pop();
                temp = pq.top();
            }
        }
        int size = same.size();
        node t;
        for (int i = 0; i < size; i++)
        {
            node tt = same[i];
            if (!used[tt.num])
            {
                if (sign == 1 && tt.pre != 0 && !adj[tt.pre][tt.num].used)
                {
                    hasnew = true;
                    return;
                }
            }
            t = tt;
        }
        used[t.num] = true;
        if (t.pre != 0)
            adj[t.pre][t.num].used = adj[t.num][t.pre].used = true;
        if (!sign)
            total += t.c;
        for (int j = 0; j < t.cnt; j++)
        {
            int tt = t.list[j];
            if (!used[tt] && nodes[tt].c >= adj[t.num][tt].v)
            {
                node tmp;
                tmp.num = tt;
                tmp.cnt = nodes[tt].cnt;
                tmp.pre = t.num;
                tmp.c = adj[t.num][tt].v;
                for (int k = 0; k < nodes[tt].cnt; k++)
                {
                    tmp.list[k] = nodes[tt].list[k];
                }
                pq.push(tmp);
            }
        }
        for (int j = 0; j < size; j++)
        {
            if (same[j].num != t.num)
                pq.push(same[j]);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(nodes, 0, sizeof(nodes));
        while (m--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edge tmp;
            tmp.v = c;
            adj[a][b] = adj[b][a] = tmp;
            nodes[a].list[nodes[a].cnt++] = b;
            nodes[b].list[nodes[b].cnt++] = a;
        }
        for (int i = 1; i <= n; i++)
        {
            nodes[i].num = i;
        }
        total = 0;
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= n; i++)
        {
            nodes[i].c = INF;
            nodes[i].pre = 0;
        }
        nodes[1].c = 0;
        while (!pq.empty())
            pq.pop();
        pq.push(nodes[1]);
        bfs(0);
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= n; i++)
        {
            nodes[i].c = INF;
            nodes[i].pre = 0;
        }
        nodes[1].c = 0;
        while (!pq.empty())
            pq.pop();
        pq.push(nodes[1]);
        hasnew = false;
        bfs(1);
        if (hasnew)
            cout << "Not Unique!" << endl;
        else
            cout << total << endl;
    }
    return 0;
}
