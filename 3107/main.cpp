/*
POJ 3107
��1655���ƣ�����1655�����޸Ķ������������ݹ�ģ�ϴ���Ҫ�Ż�
����������TLE�������ٶ�ƿ�����ڽ�ͼ��vector���ٶ�̫������Ҫ�Լ�дһ����ͼ������
�����ϵĽ��ⱨ�����ҵ���Ŀǰ���ֽ�ͼ�������ǳ������Ҫ��������Ტ��ס��
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

