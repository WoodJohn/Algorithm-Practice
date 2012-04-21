/*
POJ 1694
����һ�������涨��Ҷ�ڵ㿪ʼ��ʯͷ������һ���ڵ������ֱ���ӽڵ㶼����ʯͷʱ�����ܰ���Щʯͷ
�е�һ���ŵ��ý���� �������ջر��á��ʰ���������� ����Ҫ���ٿ�ʯͷ�����ߵ�root��
��ʵ��һ����ѧ�⡣��������ϴ������������������Ȼ���ٻ���ʣ��ʯͷ����˿��Բ������µݹ��㷨��
����ĳ���ڵ㣬������������ӽڵ�����Ž⣬Ȼ���������������Ϊa[0] ~ a[k]�����ҵ�a[i]+i��
���ֵ��Ϊ����Ľ������Ž⡣������Ҫ�ú����롣
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
