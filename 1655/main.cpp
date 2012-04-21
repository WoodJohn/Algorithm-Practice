/*
POJ 1655
朴素的算法是用DFS来简单模拟，这样需要O(N^2)的时间。
后来推出一个公式，即某个node的balance值只由其下面的子树的node数目决定。于是只需要随便找个node
作为root，通过一次DFS即可推出所有node的子node值。
需要注意的是在计算balance过程中，不能把父node也作为子树的根来考虑，因此还需要在node里记录
parent编号。
该算法在DFS部分是O(N)的，在计算部分最坏情况下应该还是O(N)级别的（没仔细想和证明）
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
}nodes[20001];

int t, n;
bool used[20001];
vector<int> graph[20001];
int root;
int dp[20001];

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
    cin >> t;
    while (t--)
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
        int minN;
        int mMin = 999999999;
        root = 1;
        used[root] = true;
        dfs(root);
        for (int i = 1; i <= n; i++)
        {
            int temp = find(i);
            if (temp < mMin)
            {
                mMin = temp;
                minN = i;
            }

        }
        cout << minN << ' ' << mMin << endl;
    }
    return 0;
}
