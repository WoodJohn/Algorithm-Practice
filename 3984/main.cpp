#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;

struct node
{
    int px;
    int py;
    int x;
    int y;
    int v;
}graph[5][5];

queue<node> q;
stack<int> s;
bool used[5][5];

void bfs()
{
    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        if (t.x == 4 && t.y == 4)
        {
            int x = t.px;
            int y = t.py;
            s.push(4);
            s.push(4);
            while (x != -1)
            {
                s.push(y);
                s.push(x);
                int tx = graph[x][y].px;
                int ty = graph[x][y].py;
                x = tx;
                y = ty;
            }
            return;
        }
        if (t.x > 0 && graph[t.x - 1][t.y].v != 1 && !used[t.x - 1][t.y])
        {
            graph[t.x - 1][t.y].px = t.x;
            graph[t.x - 1][t.y].py = t.y;
            used[t.x - 1][t.y] = true;
            q.push(graph[t.x - 1][t.y]);
        }
        if (t.x < 4 && graph[t.x + 1][t.y].v != 1 && !used[t.x + 1][t.y])
        {
            graph[t.x + 1][t.y].px = t.x;
            graph[t.x + 1][t.y].py = t.y;
            used[t.x + 1][t.y] = true;
            q.push(graph[t.x + 1][t.y]);
        }
        if (t.y > 0 && graph[t.x][t.y - 1].v != 1 && !used[t.x][t.y - 1])
        {
            graph[t.x][t.y - 1].px = t.x;
            graph[t.x][t.y - 1].py = t.y;
            used[t.x][t.y - 1] = true;
            q.push(graph[t.x][t.y - 1]);
        }
        if (t.y < 4 && graph[t.x][t.y + 1].v != 1 && !used[t.x][t.y + 1])
        {
            graph[t.x][t.y + 1].px = t.x;
            graph[t.x][t.y + 1].py = t.y;
            used[t.x][t.y + 1] = true;
            q.push(graph[t.x][t.y + 1]);
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> graph[i][j].v;
            graph[i][j].x = i;
            graph[i][j].y = j;
            graph[i][j].px = graph[i][j].py = -1;
        }
    }
    memset(used, 0, sizeof(used));
    q.push(graph[0][0]);
    used[0][0] = true;
    bfs();
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        int y = s.top();
        s.pop();
        printf("(%d, %d)\n", x, y);
    }
    return 0;
}
