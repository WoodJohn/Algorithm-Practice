#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool used[21][21];
int n,m;
int sr, sc, gr, gc;
char data[21][21];
int k[5];
int dr[5];
int dc[5];
bool done;
vector<int> toopen;

void floodfill(int r, int c)
{
    if (done || r < 1 || c < 1 || r > n || c > m || used[r][c])
        return;
    if (data[r][c] == 'G')
    {
        done = true;
        return;
    }
    if (data[r][c] == 'X')
        return;
    if (data[r][c] >= 'A' && data[r][c] <= 'E')
    {
        if (k[data[r][c] - 'A'] > 0)
        {
            toopen.push_back(data[r][c] - 'A');
            return;
        }
        else
        {
            k[data[r][c] - 'A']--;
        }
    }
    if (data[r][c] >= 'a' && data[r][c] <= 'e')
        k[data[r][c] - 'a']--;
    used[r][c] = true;
    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

bool canopen()
{
    for (int i = 0; i < toopen.size(); i++)
    {
        if (k[toopen[i]] == 0)
            return true;
    }
    return false;
}

int main()
{
    while (scanf("%d %d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        memset(used, 0, sizeof(used));
        memset(k, 0, sizeof(k));
        done = false;
        toopen.clear();
        for (int i = 1; i <= n; i++)
        {
            char s[21];
            scanf("%s", s);
            for (int j = 0; j < m; j++)
            {
                data[i][j + 1] = s[j];
                if (s[j] == 'S')
                {
                    sr = i;
                    sc = j + 1;
                }
                else if (s[j] >= 'a' && s[j] <= 'e')
                    k[s[j] - 'a']++;
                else if (s[j] >= 'A' && s[j] <= 'E')
                {
                    int t = s[j] - 'A';
                    dr[t] = i;
                    dc[t] = j + 1;
                }
            }
        }
        floodfill(sr, sc);
        while (!done && canopen())
        {
            for (int i = 0; i < toopen.size(); i++)
            {
                if (k[toopen[i]] == 0)
                {
                    floodfill(dr[toopen[i]], dc[toopen[i]]);
                }
            }
        }
        if (done)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
