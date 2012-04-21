/*
POJ 1724
A*算法（BFS + 优先队列）
*/

#include <iostream>
#include <queue>

using namespace std;

struct nn
{
    friend bool operator< (nn a, nn b)
    {
        return a.dis > b.dis;
    }
    int c;
    int dis;
    int cost;
};

vector<int> gr[101];
vector<int> di[101];
vector<int> co[101];
int k, n, r;
priority_queue<nn> pq;

void bfs()
{
    while (!pq.empty())
    {
        nn t = pq.top();
        pq.pop();
        if (t.c == n)
        {
            cout << t.dis << endl;
            return;
        }
        for (int i = 0; i < gr[t.c].size(); i++)
        {
            int dest = gr[t.c][i];
            int dist = di[t.c][i];
            int cost = co[t.c][i];
            if (t.cost + cost <= k)
            {
                nn newnode;
                newnode.c = dest;
                newnode.dis = t.dis + dist;
                newnode.cost = t.cost + cost;
                pq.push(newnode);
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    cin >> k;
    cin >> n;
    cin >> r;
    while(!pq.empty())
    {
        pq.pop();
    }
    while (r--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        gr[a].push_back(b);
        di[a].push_back(c);
        co[a].push_back(d);
    }
    nn init;
    init.c = 1;
    init.dis = 0;
    init.cost = 0;
    pq.push(init);
    bfs();
    return 0;
}

