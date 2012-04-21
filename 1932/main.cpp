/*
POJ 1932
Bellman-Ford(SPFA)
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define INF 99999999
using namespace std;

int n;
int e[101];
vector<int> graph[101];
vector<int> pre[101];
int r[101];
bool can[101]; //是否可达n
bool tag[101];  //从1出发是否可达
queue<int> q;

void bfs()
{
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        can[t] = true;
        for (int i = 0; i < pre[t].size(); i++)
        {
            int d = pre[t][i];
            if (!can[d])
                q.push(d);
        }
    }
}

void spfa()
{
    bool check[101] = {false};
    int cnt[101] = {0};
    cnt[1] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        check[t] = false;
        for (int i = 0; i < graph[t].size(); i++)
        {
            int d = graph[t][i];
            if (r[d] < r[t] + e[d])
            {
                r[d] = r[t] + e[d];
                if (r[d] > 0 && !check[d])
                {
                    if (cnt[d] >= n - 1)
                        return;
                    q.push(d);
                    cnt[d]++;
                    tag[d] = true;
                    check[d] = true;
                }
            }
        }
    }
}

int main()
{
    while (cin >> n)
    {
        if (n == -1)
            break;
        for (int i = 0; i < 101; i++)
        {
            graph[i].clear();
            r[i] = -INF;
        }
        memset(pre, 0, sizeof(pre));
        memset(can, 0, sizeof(can));
        memset(tag, 0, sizeof(tag));
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            e[i] = a;
            while (b--)
            {
                int c;
                cin >> c;
                graph[i].push_back(c);
                pre[c].push_back(i);
            }
        }
        while (!q.empty())
        {
            q.pop();
        }
        q.push(n);
        bfs();
        r[1] = 100;
        tag[1] = true;
        q.push(1);
        spfa();
        bool check = false;
        if (tag[n])
            check = true;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (graph[i].size() == 0 || !tag[i])
                    continue;
                for (int j = 0; j < graph[i].size(); j++)
                {
                    int d = graph[i][j];
                    if (r[d] < r[i] + e[d])
                    {
                        if (can[d] && tag[d])
                        {
                            check = true;
                            break;
                        }
                    }
                }
                if (check)
                    break;
            }
        }
        if (check)
            cout << "winnable" << endl;
        else
            cout << "hopeless" << endl;
    }
    return 0;
}
