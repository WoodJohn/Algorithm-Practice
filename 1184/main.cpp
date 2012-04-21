/*
POJ 1184
BFS+强剪枝
很强的剪枝。注意到改变数值的操作其实只有Up和Down两种，因此得到一个强剪枝：如果当前状态中光标位置上的数不在
最终目标里，则该步只选择Up或者Down操作。这是因为对于不在目标里的数，一定是需要修改其数值的，而只有Up和Down
才可以对其修改，即即使当步不进行Up和Down操作，在后来的某步中还是需要进行Up和Down。加上该强剪枝后94msAC
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
