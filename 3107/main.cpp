/*
POJ 3107
与1655类似，根据1655代码修改而来。但是数据规模较大，需要优化
经过无数次TLE，发现速度瓶颈在于建图。vector的速度太慢，需要自己写一个建图方法。
从网上的解题报告中找到了目前这种建图方法，非常精妙，需要深刻理解体会并记住！
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define maxn 50010

struct node
{
    int to;
    int next;
}edge[maxn << 1];
int p[maxn], n, id;

inline void insert(int x, int y)
{
    edge[id].to = y;
    edge[id].next = p[x];
    p[x] = id++;
}

bool used[maxn] = {false};
int root;
int ans1 = 0, ans2 = 0;
bool done = false;

int dfs(int cur)
{
    if (done)
        return 0;
    int i, j, sum = 1;
    used[cur] = true;

    for(i = p[cur]; i != -1; i = edge[i].next)
    {
        j = edge[i].to;
        if(!used[j])
        {
            sum += dfs(j);
        }
    }
    if (ans1 == 0 && sum >= (n >> 1) + 1)
    {
        ans1 = cur;
        done = true;
    }
    if (sum << 1 == n)
    {
        ans2 = cur;
    }
    return sum;
}

int main()
{
    scanf("%d", &n);
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    root = 1;
    dfs(root);
    if (ans2 == 0)
    {
        printf("%d\n", ans1);
    }
    else
    {
        if (ans1 > ans2)
        {
            int temp = ans1;
            ans1 = ans2;
            ans2 = temp;
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}

