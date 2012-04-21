/*
POJ 2112
һ������ͼ������ǰK������Ϊ���̵㣬��C������Ϊ��ţ��Ҫ������ţ�ʹÿ����ţ�������䵽һ�����̵㣬���ߵ���Զ����ţ����·����̣�
��ÿ�����̵����ţ����������M��
���Կ���������һ������ͼ����ƥ�䣨������1��1�������⣬ʹ���������㷨���ҵ���⣩������ĳ��������maxdΪ���Ƶ�����£�һһ���
ÿ����ţ�Ƿ�������㡣����������ǣ�������ĳ���ھ����������ڵļ��̵���δռ�����򽫸���ţA����õ㣻����������ö�����ڸĵ��ڵ���
ţB��Ѱ���Ƿ������һ�����ü��̵���B����Ȼ����һ���ݹ�Ĺ��̣����ٽ�A����õ㡣Ȼ���ö��ַ�ö�ٿ��е�maxd���ҵ�����Сֵ���ɡ�
��Ҫ�ջ񣺶��ݴ𰸵ķ������Լ������������㷨���ƹ㵽��������Ȼ���򵥵ģ�
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
