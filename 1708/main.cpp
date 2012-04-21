/*
POJ 1708
BFS + ״̬�洢������汾����vectorʵ�ֵģ�719msAC���Լ������е�������������STL��Ч�����⣬
��������ά�����д��һ�£����ָ����ˣ��ڴ滹���˺ܶࡣ��������STL����ͦ����ġ���������Լ�
ʵ��һ��queue���һЩ�ɡ�
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct node
{
    int one;
    int two;
    int depth;
};

bool used[101][101];
queue<node> q;
int ccolor[101];
int v[101][10002][2];
int n, l, k, d, m;

void bfs()
{
    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        if (t.one == d || t.two == d)
        {
            cout << "YES" << endl << t.depth << endl;
            return;
        }
        for (int i = 1; i <= v[t.one][0][0]; i++)
        {
            if (v[t.one][i][1] == ccolor[t.two] && !used[v[t.one][i][0]][t.two] && t.two != v[t.one][i][0])
            {
                node temp;
                temp.one = v[t.one][i][0];
                temp.two = t.two;
                temp.depth = t.depth + 1;
                q.push(temp);
                used[v[t.one][i][0]][t.two] = true;
            }
        }
        for (int i = 1; i <= v[t.two][0][0]; i++)
        {
            if (v[t.two][i][1] == ccolor[t.one] && !used[t.one][v[t.two][i][0]] && t.one != v[t.two][i][0])
            {
                node temp;
                temp.one = t.one;
                temp.two = v[t.two][i][0];
                temp.depth = t.depth + 1;
                q.push(temp);
                used[t.one][v[t.two][i][0]] = true;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    memset(used, 0, sizeof(used));
    cin >> n >> l >> k >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> ccolor[i + 1];
    }
    for (int i = 0; i < 101; i++)
    {
        v[i][0][0] = 0;
    }
    while (!q.empty())
        q.pop();
    cin >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a][0][0]++;
        v[a][v[a][0][0]][0] = b;
        v[a][v[a][0][0]][1] = c;
    }
    node init;
    init.one = l;
    init.two = k;
    init.depth = 0;
    q.push(init);
    bfs();
    return 0;
}
