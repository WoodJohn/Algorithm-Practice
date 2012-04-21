/*
POJ 1655
���ص��㷨����DFS����ģ�⣬������ҪO(N^2)��ʱ�䡣
�����Ƴ�һ����ʽ����ĳ��node��balanceֵֻ���������������node��Ŀ����������ֻ��Ҫ����Ҹ�node
��Ϊroot��ͨ��һ��DFS�����Ƴ�����node����nodeֵ��
��Ҫע������ڼ���balance�����У����ܰѸ�nodeҲ��Ϊ�����ĸ������ǣ���˻���Ҫ��node���¼
parent��š�
���㷨��DFS������O(N)�ģ��ڼ��㲿��������Ӧ�û���O(N)����ģ�û��ϸ���֤����
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
