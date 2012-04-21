#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int move[8][2] = {{2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}};
bool visited[90001];
int br, bc, er, ec;
queue<int> q;
int depth[90001];
int n;
int l;
int t;

void bfs()
{
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if (t == er * l + ec)
            break;
        for (int i = 0; i < 8; i++)
        {
            int row = t / l;
            int col = t % l;
            row += move[i][0];
            col += move[i][1];
            int temp = row * l + col;
            if (row < 0 || col < 0 || row >= l || col >= l || visited[temp])
                continue;
            else
            {
                q.push(temp);
                visited[temp] = true;
                depth[temp] = depth[t] + 1;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    while (n --)
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            q.pop();
        }
        scanf("%d", &l);
        scanf("%d %d", &br, &bc);
        scanf("%d %d", &er, &ec);
        memset(visited, 0, sizeof(visited));
        memset(depth, 0, sizeof(depth));
        q.push(br * l + bc);
        visited[br * l + bc] = true;
        bfs();
        printf("%d\n", depth[t]);
    }
    return 0;
}
