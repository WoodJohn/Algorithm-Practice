/*
POJ 1201
SPFA(BellmanFord)
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define INF 999999999
using namespace std;

struct node
{
    int dest;
    int v;
};

int mMax, mMin;
int n;
vector<node> graph[50002];
int d[50002];
queue<int> q;

void spfa()
{
    bool tag[50002];
    memset(tag, 0, sizeof(tag));
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        tag[t] = false;
        for (int i = 0; i < graph[t].size(); i++)
        {
            int dest = graph[t][i].dest;
            int tmp = d[dest];
            if (d[t] + graph[t][i].v < d[dest])
            {
                d[dest] = d[t] + graph[t][i].v;
            }
            if (tmp != d[dest] && !tag[dest])
            {
                q.push(dest);
                tag[dest] == true;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 50002; i++)
    {
        d[i] = INF;
    }
    while (!q.empty())
        q.pop();
    mMax = 0;
    mMin = INF;
    while (n--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        node t;
        t.dest = b + 1;
        t.v = -c;
        if (b + 1 > mMax)
            mMax = b + 1;
        if (a < mMin)
            mMin = a;
        graph[a].push_back(t);
    }
    for (int i = mMin; i < mMax; i++)
    {
        node t;
        t.dest = i + 1;
        t.v = 0;
        node t2;
        t2.dest = i;
        t2.v = 1;
        graph[i].push_back(t);
        graph[i + 1].push_back(t2);
    }
    d[mMin] = 0;
    d[mMax] = INF;
    q.push(mMin);
    spfa();
    printf("%d\n", -d[mMax]);
    return 0;
}
