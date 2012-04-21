/*
POJ 1691
本质上是求一个有向无环图的所有拓扑排序序列中的某个和值的最小值
用DFS硬搜过的，这题数据量很小，如果增大数据规模，可能需要用DP来解决。本题的代码参考了1128的解
法，即DFS每个位置，用used数组和偏序关系来枚举当前位置可选的矩形，并加入回溯。凡是穷举的题目（
例如八皇后和数独）都可以用这种模板来写。
*/

#include <stdio.h>
#include <string.h>
using namespace std;

struct square
{
    int cnt;
    int pre[15];
    int lx, ty, rx, by;
    int color;
    int depth;
}sqs[16];

bool check(square a, square b)
{
    if (a.by == b.ty)
    {
        return (a.lx <= b.lx && a.rx > b.lx) || (a.rx >= b.rx && a.lx < b.rx) || (a.lx >= b.lx && a.rx <= b.rx);
    }
    return false;
}

bool used[16];

bool checkpre(int a)
{
    for (int i = 0; i < sqs[a].cnt; i++)
    {
        if (!used[sqs[a].pre[i]])
            return false;
    }
    return true;
}

int cnt;
int t, n;
int cur;
int mMin;

void dfs(int a, int color)
{
    if (a == n)
    {
        if (cur < mMin)
            mMin = cur;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && checkpre(i))
        {
            used[i] = true;
            int cap = (color == 0 || sqs[i].color != color) ? 1 : 0;
            cur += cap;
            dfs(a + 1, sqs[i].color);
            cur -= cap;
            used[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(sqs, 0, sizeof(sqs));
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d%d", &sqs[i].ty, &sqs[i].lx, &sqs[i].by, &sqs[i].rx, &sqs[i].color);
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (check(sqs[i], sqs[j]))
                {
                    sqs[j].pre[sqs[j].cnt++] = i;
                }
                else if (check(sqs[j], sqs[i]))
                {
                    sqs[i].pre[sqs[i].cnt++] = j;
                }
            }
        }
        mMin = 1 << 30;
        cur = 0;
        memset(used, 0, sizeof(used));
        dfs(0, 0);
        printf("%d\n", mMin);
    }
    return 0;
}
