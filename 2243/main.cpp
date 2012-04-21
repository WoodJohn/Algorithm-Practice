#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char b[3], e[3];

int move[8][2] = {{2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}};
bool visited[65];
int br, bc, er, ec;
queue<int> q;
int depth[65];
int t;

void bfs()
{
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if (t == er * 8 + ec)
            break;
        for (int i = 0; i < 8; i++)
        {
            int row = t / 8;
            int col = t % 8;
            row += move[i][0];
            col += move[i][1];
            int temp = row * 8 + col;
            if (row < 0 || col < 0 || row >= 8 || col >= 8 || visited[temp])
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
    while (scanf("%s %s", b, e) != EOF)
    {
        while(!q.empty())
        {
            q.pop();
        }
        br = b[0] - 'a';
        bc = b[1] - '1';
        er = e[0] - 'a';
        ec = e[1] - '1';
        memset(visited, 0, sizeof(visited));
        memset(depth, 0, sizeof(depth));
        q.push(br * 8 + bc);
        visited[br * 8 + bc] = true;
        bfs();
        printf("To get from %s to %s takes %d knight moves.\n", b, e, depth[t]);
    }
    return 0;
}
