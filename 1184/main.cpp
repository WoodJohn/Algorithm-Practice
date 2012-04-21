/*
POJ 1184
BFS+ǿ��֦
��ǿ�ļ�֦��ע�⵽�ı���ֵ�Ĳ�����ʵֻ��Up��Down���֣���˵õ�һ��ǿ��֦�������ǰ״̬�й��λ���ϵ�������
����Ŀ�����ò�ֻѡ��Up����Down������������Ϊ���ڲ���Ŀ���������һ������Ҫ�޸�����ֵ�ģ���ֻ��Up��Down
�ſ��Զ����޸ģ�����ʹ����������Up��Down�������ں�����ĳ���л�����Ҫ����Up��Down�����ϸ�ǿ��֦��94msAC
*/

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct node
{
    int state;
    int pos;
    int depth;
};
int n1, n2;
int result;
queue<node> q;
bool used[6000001];
bool inresult[10];
int pow10[6] = {100000, 10000, 1000, 100, 10, 1};

int mMax;
int mMin;

inline int numat(int n, int a)
{
    return (n / pow10[a]) % 10;
}

inline int swapat(int a, int p, int q)
{
    return a + (numat(a, p) - numat(a, q)) * pow10[q] + (numat(a, q) - numat(a, p)) * pow10[p];
}

void bfs()
{
    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        bool needChange = !inresult[numat(t.state, t.pos)];
        //case 1
        if (t.pos != 0 && !needChange)
        {
            node newnode;
            newnode.state = swapat(t.state, 0, t.pos);
            newnode.pos = t.pos;
            newnode.depth = t.depth + 1;
            if (newnode.state == n2)
            {
                result = newnode.depth;
                return;
            }
            int check = newnode.pos * 1000000 + newnode.state;
            if (!used[check])
            {
                used[check] = true;
                q.push(newnode);
            }
        }
        //case 2
        if (t.pos != 5 && !needChange)
        {
            node newnode;
            newnode.state = swapat(t.state, 5, t.pos);
            newnode.pos = t.pos;
            newnode.depth = t.depth + 1;
            if (newnode.state == n2)
            {
                result = newnode.depth;
                return;
            }
            int check = newnode.pos * 1000000 + newnode.state;
            if (!used[check])
            {
                used[check] = true;
                q.push(newnode);
            }
        }
        //case 3
        if (numat(t.state, t.pos) < mMax)
        {
            node newnode;
            newnode.state = t.state + pow10[t.pos];
            newnode.pos = t.pos;
            newnode.depth = t.depth + 1;
            if (newnode.state == n2)
            {
                result = newnode.depth;
                return;
            }
            int check = newnode.pos * 1000000 + newnode.state;
            if (!used[check])
            {
                used[check] = true;
                q.push(newnode);
            }
        }
        //case 4
        if (numat(t.state, t.pos) > mMin)
        {
            node newnode;
            newnode.state = t.state - pow10[t.pos];
            newnode.pos = t.pos;
            newnode.depth = t.depth + 1;
            if (newnode.state == n2)
            {
                result = newnode.depth;
                return;
            }
            int check = newnode.pos * 1000000 + newnode.state;
            if (!used[check])
            {
                used[check] = true;
                q.push(newnode);
            }
        }
        //case 5
        if (t.pos != 0 && !needChange)
        {
            node newnode;
            newnode.state = t.state;
            newnode.pos = t.pos - 1;
            newnode.depth = t.depth + 1;
            int check = newnode.pos * 1000000 + newnode.state;
            if (!used[check])
            {
                used[check] = true;
                q.push(newnode);
            }
        }
        //case 6
        if (t.pos != 5 && !needChange)
        {
            node newnode;
            newnode.state = t.state;
            newnode.pos = t.pos + 1;
            newnode.depth = t.depth + 1;
            int check = newnode.pos * 1000000 + newnode.state;
            if (!used[check])
            {
                used[check] = true;
                q.push(newnode);
            }
        }
    }
}

int main()
{
    memset(used, 0, sizeof(used));
    memset(inresult, 0, sizeof(inresult));
    cin >> n1 >> n2;
    if (n1 == n2)
    {
        cout << 0 << endl;
        return 0;
    }
    while (!q.empty())
        q.pop();
    node init;
    init.state = n1;
    init.depth = 0;
    init.pos = 0;
    q.push(init);
    used[n1] = true;
    mMax = 0;
    mMin = 10;
    int tt = n2;
    while (tt)
    {
        int ttt = tt % 10;
        inresult[ttt] = true;
        if (ttt > mMax)
            mMax = ttt;
        if (ttt < mMin)
            mMin = ttt;
        tt /= 10;
    }
    if (n2 < 100000)
        inresult[0] = true;
    bfs();
    cout << result << endl;
    return 0;
}
