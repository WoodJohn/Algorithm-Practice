/*
POJ 1691
����������һ�������޻�ͼ�������������������е�ĳ����ֵ����Сֵ
��DFSӲ�ѹ��ģ�������������С������������ݹ�ģ��������Ҫ��DP�����������Ĵ���ο���1128�Ľ�
������DFSÿ��λ�ã���used�����ƫ���ϵ��ö�ٵ�ǰλ�ÿ�ѡ�ľ��Σ���������ݡ�������ٵ���Ŀ��
����˻ʺ��������������������ģ����д��
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
