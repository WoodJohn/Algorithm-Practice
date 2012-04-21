#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct nn
{
    int x;
    int y;
};

int m, n;
bool vwall[201][201];
bool hwall[201][201];
bool vdoor[201][201];
bool hdoor[201][201];
bool used[201][201];
int depth[201][201];
queue<nn> q;
int startX, startY;

void bfs()
{
    bool check = false;
    while (!q.empty())
    {
        nn t = q.front();
        q.pop();
        if (t.x == 0 && t.y == 0)
        {
            check = true;
        }
        if (t.x > 0)
        {
            if (vdoor[t.x][t.y])
                {
                    if (used[t.x - 1][t.y])
                    {
                        if (depth[t.x][t.y] + 1 < depth[t.x - 1][t.y])
                        {
                            nn temp;
                            temp.x = t.x - 1;
                            temp.y = t.y;
                            depth[temp.x][temp.y] = depth[t.x][t.y] + 1;
                            q.push(temp);
                        }
                    }
                    else
                    {
                        used[t.x - 1][t.y] = true;
                        nn temp;
                        temp.x = t.x - 1;
                        temp.y = t.y;
                        depth[temp.x][temp.y] = depth[t.x][t.y] + 1;
                        q.push(temp);
                    }
                }
            else if (!vwall[t.x][t.y])
            {
                if (used[t.x - 1][t.y])
                {
                    if (depth[t.x][t.y] < depth[t.x - 1][t.y])
                    {
                        nn temp;
                        temp.x = t.x - 1;
                        temp.y = t.y;
                        depth[temp.x][temp.y] = depth[t.x][t.y];
                        q.push(temp);
                    }
                }
                else
                {
                    used[t.x - 1][t.y] = true;
                    nn temp;
                    temp.x = t.x - 1;
                    temp.y = t.y;
                    depth[temp.x][temp.y] = depth[t.x][t.y];
                    q.push(temp);
                }
            }
        }

        if (t.x < 199)
        {
            if (vdoor[t.x + 1][t.y])
                {
                    if (used[t.x + 1][t.y])
                    {
                        if (depth[t.x][t.y] + 1 < depth[t.x + 1][t.y])
                        {
                            nn temp;
                            temp.x = t.x + 1;
                            temp.y = t.y;
                            depth[temp.x][temp.y] = depth[t.x][t.y] + 1;
                            q.push(temp);
                        }
                    }
                    else
                    {
                        used[t.x + 1][t.y] = true;
                        nn temp;
                        temp.x = t.x + 1;
                        temp.y = t.y;
                        depth[temp.x][temp.y] = depth[t.x][t.y] + 1;
                        q.push(temp);
                    }
                }
            else if (!vwall[t.x + 1][t.y])
            {
                if (used[t.x + 1][t.y])
                {
                    if (depth[t.x][t.y] < depth[t.x + 1][t.y])
                    {
                        nn temp;
                        temp.x = t.x + 1;
                        temp.y = t.y;
                        depth[temp.x][temp.y] = depth[t.x][t.y];
                        q.push(temp);
                    }
                }
                else
                {
                    used[t.x + 1][t.y] = true;
                    nn temp;
                    temp.x = t.x + 1;
                    temp.y = t.y;
                    depth[temp.x][temp.y] = depth[t.x][t.y];
                    q.push(temp);
                }
            }
        }

        if (t.y > 0)
        {
            if (hdoor[t.x][t.y])
                {
                    if (used[t.x][t.y - 1])
                    {
                        if (depth[t.x][t.y] + 1 < depth[t.x][t.y - 1])
                        {
                            nn temp;
                            temp.x = t.x;
                            temp.y = t.y - 1;
                            depth[temp.x][temp.y] = depth[t.x][t.y] + 1;
                            q.push(temp);
                        }
                    }
                    else
                    {
                        used[t.x][t.y - 1] = true;
                        nn temp;
                        temp.x = t.x;
                        temp.y = t.y - 1;
                        depth[temp.x][temp.y] = depth[t.x][t.y] + 1;
                        q.push(temp);
                    }
                }
            else if (!hwall[t.x][t.y])
            {
                if (used[t.x][t.y - 1])
                {
                    if (depth[t.x][t.y] < depth[t.x][t.y - 1])
                    {
                        nn temp;
                        temp.x = t.x;
                        temp.y = t.y - 1;
                        depth[temp.x][temp.y] = depth[t.x][t.y];
                        q.push(temp);
                    }
                }
                else
                {
                    used[t.x][t.y - 1] = true;
                    nn temp;
                    temp.x = t.x;
                    temp.y = t.y - 1;
                    depth[temp.x][temp.y] = depth[t.x][t.y];
                    q.push(temp);
                }
            }
        }

        if (t.y < 199)
        {
            if (hdoor[t.x][t.y + 1])
                {
                    if (used[t.x][t.y + 1])
                    {
                        if (depth[t.x][t.y] + 1 < depth[t.x][t.y + 1])
                        {
                            nn temp;
                            temp.x = t.x;
                            temp.y = t.y + 1;
                            depth[temp.x][temp.y] = depth[t.x][t.y] + 1;
                            q.push(temp);
                        }
                    }
                    else
                    {
                        used[t.x][t.y + 1] = true;
                        nn temp;
                        temp.x = t.x;
                        temp.y = t.y + 1;
                        depth[temp.x][temp.y] = depth[t.x][t.y] + 1;
                        q.push(temp);
                    }
                }
            else if (!hwall[t.x][t.y + 1])
            {
                if (used[t.x][t.y + 1])
                {
                    if (depth[t.x][t.y] < depth[t.x][t.y + 1])
                    {
                        nn temp;
                        temp.x = t.x;
                        temp.y = t.y + 1;
                        depth[temp.x][temp.y] = depth[t.x][t.y];
                        q.push(temp);
                    }
                }
                else
                {
                    used[t.x][t.y + 1] = true;
                    nn temp;
                    temp.x = t.x;
                    temp.y = t.y + 1;
                    depth[temp.x][temp.y] = depth[t.x][t.y];
                    q.push(temp);
                }
            }
        }
    }

    if (!check)
        cout << -1 << endl;
    else
        cout << depth[0][0] << endl;
}

int main()
{
    while (cin >> m >> n)
    {
        if (m == -1 && n == -1)
            break;
        while (!q.empty())
        {
            q.pop();
        }
        memset(vwall, 0, sizeof(vwall));
        memset(hwall, 0, sizeof(hwall));
        memset(vdoor, 0, sizeof(vdoor));
        memset(hdoor, 0, sizeof(hdoor));
        memset(depth, 0, sizeof(depth));
        memset(used, 0, sizeof(used));
        while (m--)
        {
            int x, y, d, t;
            cin >> x >> y >> d >> t;
            if (d == 0)
            {
                for (int i = x; i < x + t; i++)
                {
                    hwall[i][y] = true;
                }
            }
            else
            {
                for (int i = y; i < y + t; i++)
                {
                    vwall[x][i] = true;
                }
            }
        }
        while (n--)
        {
            int x, y, d;
            cin >> x >> y >> d;
            if (d == 0)
            {
                hdoor[x][y] = true;
            }
            else
            {
                vdoor[x][y] = true;
            }
        }
        float a, b;
        cin >> a >> b;
        if (a > 199 || a < 1 || b > 199 || b < 1)
            cout << 0 << endl;
        else
        {
            nn temp;
            temp.x = (int)a;
            temp.y = (int)b;
            q.push(temp);
            depth[temp.x][temp.y] = 0;
            bfs();
        }
    }
    return 0;
}
