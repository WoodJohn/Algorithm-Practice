/*
POJ 1137
BFS + ״̬�洢 + ·���洢��λ���㣩
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <string.h>
#include <stack>
#include <algorithm>

using namespace std;

bool used[10240];

struct node
{
    int state;
    int depth;
    node *parent;
};

int r, d, s;
queue<node *> q; //��Ҫ��ָ����ΪqueueԪ�ص����ͣ�������ܻ���Ϊϵͳ���Զ��ͷŶ����¸��ڵ�ָ�����
vector<int> graph[11];
vector<int> ss[11];
stack<int> result;

int findDiffBit(int src, int dst)
{
    int ts = src;
    int td = dst;
    int bit = 1;
    int num = 1;
    while ((ts & num) == (td & num))
    {
        bit++;
        num = (int)pow(2, bit - 1);
    }
    return bit;
}

void printresult(node *t)
{
    node *tt = t;
    while (tt->parent != NULL)
    {
        result.push(tt->state);
        tt = tt->parent;
    }
    result.push(tt->state);
    int cur = result.top();
    int curState = cur / 10;
    int curRoom = cur % 10 + 1;
    result.pop();
    while (!result.empty())
    {
        int nextState = result.top() / 10;
        int nextRoom = result.top() % 10 + 1;
        if (nextRoom == curRoom)
        {
            int bit = findDiffBit(nextState, curState);
            if (nextState > curState)
            {
                cout << "- Switch on light in room " << bit << "." << endl;
            }
            else
            {
                cout << "- Switch off light in room " << bit << "." << endl;
            }
        }
        else
        {
            cout << "- Move to room " << nextRoom << "." << endl;
        }
        curState = nextState;
        curRoom = nextRoom;
        result.pop();
    }
}

bool testLight(int ls, int room)
{
    int bit = (int)pow(2.0, room - 1);
    return (ls & bit);
}

int onoff(int ls, int room)
{
    int bit = (int)pow(2.0, room - 1);
    return (ls ^ bit);
}

void bfs()
{
    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        int lightstate = t->state / 10;
        int curRoom = (t->state % 10) + 1;
        if (lightstate == (int)pow(2, r - 1) && curRoom == r)
        {
            cout << "The problem can be solved in " << t->depth << " steps:" << endl;
            printresult(t);
            return;
        }
        for (int i = 0; i < graph[curRoom].size(); i++)
        {
            if (testLight(lightstate, graph[curRoom][i]))
            {
                int newstate = lightstate * 10 + graph[curRoom][i] - 1;
                if (!used[newstate])
                {
                    node *newnode = new node;
                    newnode->state = newstate;
                    newnode->depth = t->depth + 1;
                    newnode->parent = t;
                    used[newstate] = true;
                    q.push(newnode);
                }
            }
        }
        for (int i = 0; i < ss[curRoom].size(); i++)
        {
            if (ss[curRoom][i] == curRoom)
                continue;
            int newstate = onoff(lightstate, ss[curRoom][i]) * 10 + curRoom - 1;
            {
                if (!used[newstate])
                {
                    node *newnode = new node;
                    newnode->state = newstate;
                    newnode->depth = t->depth + 1;
                    newnode->parent = t;
                    used[newstate] = true;
                    q.push(newnode);
                }
            }
        }
    }
    cout << "The problem cannot be solved." << endl;
}

int main()
{
    int cnt = 1;
    while (cin >> r >> d >> s)
    {
        if (r == 0 && d == 0 && s == 0)
            break;
        memset(used, 0 , sizeof(used));
        for (int i = 0; i < 11; i++)
        {
            graph[i].clear();
            ss[i].clear();
        }
        while (!q.empty())
            q.pop();
        while (d--)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while (s--)
        {
            int a, b;
            cin >> a >> b;
            ss[a].push_back(b);
        }
        for (int i = 0; i < 11; i++) //��Ҫ���򣡷���������ԡ������Ȼû��SPJ���Ҳ���
        {
            if (ss[i].size() > 0)
            {
                sort(ss[i].begin(), ss[i].end(), less<int>());
            }
        }
        cout << "Villa #" << cnt << endl;
        cnt++;
        node *init = new node;
        init->state = 1 * 10 + 0;
        init->depth = 0;
        init->parent = NULL;
        used[1 * 10 + 0] = true;
        q.push(init);
        bfs();
        cout << endl;
    }
    return 0;
}
