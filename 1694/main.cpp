/*
POJ 1694
给定一棵树。规定从叶节点开始放石头，仅当一个节点的所有直接子节点都放了石头时，才能把这些石头
中的一个放到该结点上 其他的收回备用。问按照这个规则 最少要多少颗石头才能走到root。
其实是一个数学题。由于需求较大的子树可以优先填满然后再回收剩余石头，因此可以采用如下递归算法：
对于某个节点，先求出其所有子节点的最优解，然后降序排序（设排序后为a[0] ~ a[k]），找到a[i]+i的
最大值即为所求的结点的最优解。理由需要好好想想。
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;
struct node
{
    int cnt;
    int child[200];
}nodes[200];

bool cmp(int a, int b)
{
    return nodes[a].cnt >= nodes[b].cnt;
}

int t, n, mMax;

int dfs(int a)
{
    if (nodes[a].cnt == 0)
        return 1;
    int mm = 0;
    int list[200];
    for (int i = 0; i < nodes[a].cnt; i++)
    {
        list[i] = dfs(nodes[a].child[i]);
    }
    sort(list, list + nodes[a].cnt, greater<int>());
    for (int i = 0; i < nodes[a].cnt; i++)
    {
        if (list[i] + i > mm)
            mm = list[i] + i;
    }
    return mm;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        while (n--)
        {
            int a;
            scanf("%d", &a);
            scanf("%d", &nodes[a].cnt);
            for (int i = 0; i < nodes[a].cnt; i++)
            {
                scanf("%d", &nodes[a].child[i]);
            }
        }
        mMax = dfs(1);
        printf("%d\n", mMax);
    }
    return 0;
}
