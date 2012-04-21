#include <stdio.h>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

queue<int> q;
stack<char> st;
int depth[1001];
int pre[1001];
bool used[1001];
char result[1002];
char op[1002];

int in, n, m, k;

int bfs()
{
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        int temp = (t + m) % k;
        if (!used[temp])
        {
            q.push(temp);
            used[temp] = true;
            pre[temp] = t;
            op[temp] = '+';
            depth[temp] = depth[t] + 1;
            if (temp == in)
            {
                return temp;
            }
        }

        temp = (t - m) % k;
        if (temp < 0)
            temp += k;
        if (!used[temp])
        {
            q.push(temp);
            used[temp] = true;
            depth[temp] = depth[t] + 1;
            pre[temp] = t;
            op[temp] = '-';
            if (temp == in)
                return temp;
        }

        temp = (t * m) % k;
        if (!used[temp])
        {
            q.push(temp);
            used[temp] = true;
            depth[temp] = depth[t] + 1;
            pre[temp] = t;
            op[temp] = '*';
            if (temp == in)
                return temp;
        }

        if (depth[t] == 0 || op[t] == '*')
        {
            if (depth[t] == 0)
            {
                temp = (n % m);
                if (temp < 0)
                    temp += m;
                temp %= k;
                if (temp < 0)
                    temp += k;
            }
            else
                temp = 0;
            if (!used[temp])
            {
                q.push(temp);
                used[temp] = true;
                depth[temp] = depth[t] + 1;
                pre[temp] = t;
                op[temp] = '%';
                if (temp == in)
                    return temp;
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d %d %d", &n, &k, &m) != EOF)
    {
        if (n == 0 && k == 0 && m == 0)
            break;
        memset(depth, 0, sizeof(depth));
        memset(used, 0, sizeof(used));
        memset(result, 0, sizeof(result));
        memset(op, 0, sizeof(op));
        memset(pre, 0, sizeof(pre));
        while (!q.empty())
        {
            q.pop();
        }
        while (!st.empty())
        {
            st.pop();
        }
        in = (n + 1) % k;
        if (in < 0)
            in += k;
        int temp = n % k;
        if (temp < 0)
            temp += k;
        q.push(temp);
        used[temp] = true;
        depth[temp] = 0;
        op[temp] = 0;
        int t = bfs();
        if (t == -1)
            printf("0\n");
        else
        {
            printf("%d\n", depth[t]);
            int p = depth[t];
            while (t != temp)
            {
                result[p - 1] = op[t];
                p--;
                t = pre[t];
            }
            printf("%s\n", result);
        }
    }
    return 0;
}
