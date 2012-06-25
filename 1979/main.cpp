#include <iostream>
#include <string.h>
using namespace std;

int c, r, num;
char g[30][30];
bool used[30][30];

void dfs(int x, int y)
{
    if (g[x][y] == '#' || used[x][y])
        return;
    num++;
    used[x][y] = true;
    if (x < r - 1)
        dfs(x + 1, y);
    if (x > 0)
        dfs(x - 1, y);
    if (y < c - 1)
        dfs(x, y + 1);
    if (y > 0)
        dfs(x, y - 1);
}

int main()
{
    while (cin >> c >> r)
    {
        if (c == r && c == 0)
            break;
        int i;
        int x, y;
        memset(used, false, sizeof(used));
        num = 0;
        for (i = 0; i < r; i++)
        {
            cin >> g[i];
            int j;
            for (j = 0; j < c; j++)
            {
                if (g[i][j] == '@')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        dfs(x, y);
        cout << num << endl;
    }
    return 0;
}
