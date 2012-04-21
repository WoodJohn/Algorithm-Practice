/*
POJ 1632
DFS!
������������С�;�����DFS��ö�١������Ƚϱ���ö����ߵĵ㣬dfsʱ����ǰ���������У�Ȼ��Ӹõ�
�������ҽ�����ҵ����������ȫ���ĵ㶼�����ģ���dfs�ұߵ�����㡣���������ӣ�ÿ��dfs���׵�ʱ
��ȡ�������е���Сֵ��Ϊ��������Ҫ�ҵľ��ǽ���е����ֵ��
��һ��д��ʱ��Ƚ�2B���뵱Ȼ����ΪҪ�ҵ��������ҵ�ʱ��ż���������������ʹ����bool���������أ�
�����ȴӷǴ𰸽�������;���𰸽��ʱ�ᵼ�´𰸽����֮��ļ����в����ôӶ�����������Ϊÿ��
��ͷ������ʼǰ���bool���飬Ȼ��ÿ�β����Ƿ����ӿռ䶼��һ�飨������Ӱ�����ֵ�ļ�¼������ʱ��
�����˵ڶ���bug��ÿ��dfsһ�����Ժ�Ҫ���õ��bool��¼���ã�����֮���и���ֵʱ�㲻�����޸�֮
��TLE���������룬����ʱ����ָ�����ģ��Ҳ���
˯ǰ����һ�ᣬ����������΢���룬����ֻҪ��dfs��ö��ʱ�Ӹ���֦�����ˡ����������ǰ��������Ǹ�
���еĳ��ȣ���Ŀǰ��ѡ�еĽ������+Ŀǰ��㻹����չ���ӿռ�������Ŀ <= ��ǰ����������ֵ����
�����������ˣ���Ϊ����Ҳ��������ֵ�����ˡ�����DFS�����ʣ������ǰ�����Ľ���Ǵ𰸽�㣬��ô
�϶������ҵ����ֵ�Ž��벻��Ҫ������״̬����������֦�������Լ������е����ý�ռ䡣����ύ��
ʱ�����ǰ�fout�Ļ�cout���๱����һ��WA��orz����
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

void sdfs(int a);
void ddfs(int a);

struct snode
{
    int cnt;
    int edges[37];
}snodes[37];

struct dnode
{
    int cnt;
    int edges[37];
}dnodes[37];

bool adj[37][37];
bool sused[37];
bool dused[37];
bool slog[37];
vector<int> sv;
vector<int> dv;
int mMax;

void sdfs(int a)
{
    sused[a] = true;
    sv.push_back(a);
    for (int i = 0; i < snodes[a].cnt; i++)
    {
        if (dv.size() + snodes[a].cnt - i <= mMax)
            break;
        int temp = snodes[a].edges[i];
        if (!dused[temp])
        {
            bool cc = true;
            for (int j = 0; j < sv.size(); j++)
            {
                if (!adj[sv[j]][temp])
                {
                    cc = false;
                    break;
                }
            }
            if (cc)
                ddfs(temp);
        }
    }
    int mm = sv.size() < dv.size() ? sv.size() : dv.size();
    if (mm > mMax)
        mMax = mm;
    sv.pop_back();
    sused[a] = false;
}

void ddfs(int a)
{
    dused[a] = true;
    dv.push_back(a);
    for (int i = 0; i < dnodes[a].cnt; i++)
    {
        if (sv.size() + dnodes[a].cnt - i <= mMax)
            break;
        int temp = dnodes[a].edges[i];
        if (!sused[temp] && !slog[temp])
        {
            bool cc = true;
            for (int j = 0; j < dv.size(); j++)
            {
                if (!adj[temp][dv[j]])
                {
                    cc = false;
                    break;
                }
            }
            if (cc)
                sdfs(temp);
        }
    }
    int mm = sv.size() < dv.size() ? sv.size() : dv.size();
    if (mm > mMax)
        mMax = mm;
    dv.pop_back();
    dused[a] = false;
}

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(snodes, 0, sizeof(snodes));
        memset(dnodes, 0, sizeof(dnodes));
        memset(adj, 0, sizeof(adj));
        memset(slog, 0, sizeof(slog));
        while (n--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            snodes[a].edges[snodes[a].cnt++] = b;
            dnodes[b].edges[dnodes[b].cnt++] = a;
            adj[a][b] = true;
        }
        mMax = 0;
        for (int i = 0; i < 37; i++)
        {
            if (snodes[i].cnt > 0)
            {
                sv.clear();
                dv.clear();
                memset(sused, 0, sizeof(sused));
                memset(dused, 0, sizeof(dused));
                sdfs(i);
                slog[i] = true;
            }
        }
        cout << mMax << endl;
    }
    return 0;
}
