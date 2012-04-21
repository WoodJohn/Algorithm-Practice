#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,a,b;
vector<int> graph[10001], contests[10001];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline int min(int a, int b)
{
    return a < b ? a : b;
}

struct nn
{
    int str;
    char name[102];
}teams[5001];

bool cmp(int a, int b)
{
    return teams[a - n].str > teams[b - n].str;
}

void find(int a, int pre)
{
    for (int i = 0; i < graph[a].size(); i ++)
    {
        if (graph[a][i] != pre)
        {
            find(graph[a][i], a);
        }
    }
    sort(contests[a].begin(), contests[a].end(), cmp);
    if (pre > 0)
    {
        if (contests[a].size() == 1)
        {
            contests[pre].push_back(contests[a][0]);
        }
        else if (contests[a].size() > 0)
        {
            contests[pre].push_back(contests[a][0]);
            contests[pre].push_back(contests[a][1]);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    {
        for (int i = 1; i < n; i ++)
        {
            graph[i].clear();
            contests[i].clear();
        }
        for (int i = 0; i < n + m - 1; i ++)
        {
            scanf("%d %d", &a, &b);
            int x = min(a, b);
            int y = max(a, b);
            if (y <= n)
            {
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
            else
            {
                contests[x].push_back(y);
            }
        }
        for (int i = 1; i <= m; i ++)
        {
            scanf("%s %d", teams[i].name, &teams[i].str);
        }
        find(1, -1);
        sort(contests[1].begin(), contests[1].end(), cmp);
        for (int i = 0; i < contests[1].size(); i ++)
        {
            printf("%s\n", teams[contests[1][i] - n].name);
        }
    }
    return 0;
}
