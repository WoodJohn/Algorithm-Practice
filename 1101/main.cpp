/*
POJ 1101
BFS + 优先队列，这题有点tricky，感觉最后要靠数据才能过。需要研究完美解法。
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;

int dx, dy;

struct node
{
    friend bool operator< (node a, node b)
    {
        if (a.seg == b.seg)
        {
            if (a.x == dx || a.y == dy)
                return false;
            if (b.x == dx || b.y == dy)
                return true;
            return true;
        }//根据数据加的附加判定，感觉很low。。
        return a.seg > b.seg;
    }
    int x;
    int y;
    short dir;
    int seg;
};

int w, h;
char point[77][77];
bool used[77][77];
priority_queue<node> pq;
int ccnt;

void bfs()
{
    while (!pq.empty())
    {
        node t = pq.top();
        pq.pop();
        if (t.x == dx && t.y == dy)
        {
            cout << "Pair " << ccnt << ": " << t.seg << " segments." << endl;
            ccnt++;
            return;
        }
        if (t.x > 0 && !used[t.x - 1][t.y] && (point[t.x - 1][t.y] != 'X' || (t.x - 1 == dx && t.y == dy)))
        {
            node newnode;
            newnode.x = t.x - 1;
            newnode.y = t.y;
            newnode.dir = 1;
            if (t.dir != newnode.dir)
            {
                newnode.seg = t.seg + 1;
            }
            else
            {
                newnode.seg = t.seg;
            }
            used[t.x - 1][t.y] = true;
            pq.push(newnode);
        }
        if (t.x <= w && !used[t.x + 1][t.y] && (point[t.x + 1][t.y] != 'X' || (t.x + 1 == dx && t.y == dy)))
        {
            node newnode;
            newnode.x = t.x + 1;
            newnode.y = t.y;
            newnode.dir = 1;
            if (t.dir != newnode.dir)
            {
                newnode.seg = t.seg + 1;
            }
            else
            {
                newnode.seg = t.seg;
            }
            used[t.x + 1][t.y] = true;
            pq.push(newnode);
        }
        if (t.y > 0 && !used[t.x][t.y - 1] && (point[t.x][t.y - 1] != 'X' || (t.x == dx && t.y - 1 == dy)))
        {
            node newnode;
            newnode.x = t.x;
            newnode.y = t.y - 1;
            newnode.dir = 2;
            if (t.dir != newnode.dir)
            {
                newnode.seg = t.seg + 1;
            }
            else
            {
                newnode.seg = t.seg;
            }
            used[t.x][t.y - 1] = true;
            pq.push(newnode);
        }
        if (t.y <= h && !used[t.x][t.y + 1] && (point[t.x][t.y + 1] != 'X'  || (t.x == dx && t.y + 1 == dy)))
        {
            node newnode;
            newnode.x = t.x;
            newnode.y = t.y + 1;
            newnode.dir = 2;
            if (t.dir != newnode.dir)
            {
                newnode.seg = t.seg + 1;
            }
            else
            {
                newnode.seg = t.seg;
            }
            used[t.x][t.y + 1] = true;
            pq.push(newnode);
        }
    }
    cout << "Pair " << ccnt << ": impossible." << endl;
    ccnt++;
}

int main()
{
    int cnt = 1;
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            break;
        memset(point, 0, sizeof(point));
        getchar();
        for (int i = 0; i < h; i++)
        {
            char s[76];
            gets(s);
            for (int j = 0; j < w; j++)
            {
                point[j + 1][i + 1] = s[j];
            }
        }
        cout << "Board #" << cnt << ":" << endl;
        cnt++;
        int sx, sy;
        ccnt = 1;
        while (cin >> sx >> sy >> dx >> dy)
        {
            if (sx == 0 && sy == 0 && dx == 0 && dy == 0)
                break;
            memset(used, 0, sizeof(used));
            while (!pq.empty())
            {
                pq.pop();
            }
            node init;
            init.x = sx;
            init.y = sy;
            init.dir = 0;
            init.seg = 0;
            pq.push(init);
            used[sx][sy] = true;
            bfs();
        }
        cout << endl;
    }
    return 0;
}
