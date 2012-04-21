/*
POJ 2112
一个无向图，其中前K个顶点为挤奶点，后C个顶点为奶牛。要求合理安排，使每个奶牛都被分配到一个挤奶点，且走得最远的奶牛所走路程最短，
且每个挤奶点的奶牛数量不超过M。
可以看出这题是一道二分图多重匹配（即不是1对1）的问题，使用匈牙利算法（我的理解）：在以某个最大距离maxd为限制的情况下，一一检测
每个奶牛是否可以满足。满足的条件是：若存在某个在距离限制以内的挤奶点尚未占满，则将该奶牛A放入该点；若已满，则枚举已在改点内的奶
牛B，寻找是否存在另一个可用挤奶点存放B（显然这是一个递归的过程），再将A放入该点。然后，用二分法枚举可行的maxd，找到其最小值即可。
主要收获：二份答案的方法，以及多重匈牙利算法（推广到单重是显然而简单的）
*/

#include <stdio.h>
#include <string.h>
#define INF 99999999

int k, c, m;

int dist[231][231];
bool used[31];
int list[31][201];

void init()
{
    int t;
    memset(dist, 0, sizeof(dist));
    scanf("%d%d%d", &k, &c, &m);
    for (int i = 0; i < k + c; i++)
    {
        for (int j = 0; j < k + c; j++)
        {
            scanf("%d", &t);
            if (t == 0)
                dist[i][j] = INF;
            else
                dist[i][j] = t;
        }
    }
}

void floyd()
{
    for (int t = 0; t < k + c; t++)
    {
        for (int i = 0; i < k + c; i++)
        {
            for (int j = 0; j < k + c; j++)
            {
                if (dist[i][j] > dist[i][t] + dist[t][j])
                    dist[i][j] = dist[i][t] + dist[t][j];
            }
        }
    }
}

bool find(int start, int maxd)
{
    for (int i = 0; i < k; i++)
    {
        if (dist[start][i] > maxd)
            continue;
        if (!used[i])
        {
            used[i] = true;
            int num = list[i][0];
            if (num < m)
            {
                list[i][++list[i][0]] = start;
                return true;
            }
            if (num == m)
            {
                for (int j = 1; j <= num; j++)
                {
                    if (find(list[i][j], maxd))
                    {
                        list[i][j] = start;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool check(int dis)
{
    memset(list, 0, sizeof(list));
    for (int i = k; i < k + c; i++)
    {
        memset(used, 0, sizeof(used));
        if (!find(i, dis))
            return false;
    }
    return true;
}

int bs()
{
    int l = 0, r = 100000;
    while (l != r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    init();
    floyd();
    printf("%d\n", bs());
    return 0;
}
