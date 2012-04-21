/*
POJ 2378
与1655类似，根据1655代码修改而来
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

struct node
{
    int parent;
    int childs;
}nodes[10001];

int t, n;
bool used[10001];
vector<int> graph[10001];
int root;

void dfs(int a)
{
    int cnt = 0;
    for (int i = 0; i < graph[a].size(); i++)
    {
        int temp = graph[a][i];
        if (!used[temp])
        {
            nodes[temp].parent = a;
            used[temp] = true;
            dfs(temp);
            cnt += nodes[temp].childs + 1;
        }
    }
    nodes[a].childs = cnt;
}

int find(int a)
{
    int mMax = 0;
    for (int i = 0; i < graph[a].size(); i++)
    {
        int temp = graph[a][i];
        if (temp == nodes[a].parent)
            continue;
        if (nodes[temp].childs + 1 > mMax)
            mMax = nodes[temp].childs + 1;
    }
    if (n - 1 - nodes[a].childs > mMax)
        mMax = n - 1 - nodes[a].childs;
    return mMax;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        graph[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(used, 0, n * sizeof(bool));
    memset(nodes, 0, n * sizeof(node));
    root = 1;
    used[root] = true;
    dfs(root);
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        int temp = find(i);
        if (temp <= n / 2)
        {
            result.push_back(i);
        }

    }
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}

