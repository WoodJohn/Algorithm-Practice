#include <iostream>
#include <string>
#include <string.h>
using namespace std;

bool used[26];

int mMax = 0;
int r, c;
string s[21];

void dfs(int x, int y, int cur)
{
    bool check = false;
    used[s[x][y] - 'A'] = true;
    if (x > 0)
    {
        if (!used[s[x - 1][y] - 'A'])
        {
            dfs(x - 1, y, cur + 1);
            used[s[x - 1][y] - 'A'] = false;
            check = true;
        }
    }
    if (y > 0)
    {
        if (!used[s[x][y - 1] - 'A'])
        {
            dfs(x, y - 1, cur + 1);
            used[s[x][y - 1] - 'A'] = false;
            check = true;
        }
    }
    if (x < r - 1)
    {
        if (!used[s[x + 1][y] - 'A'])
        {
            dfs(x + 1, y, cur + 1);
            used[s[x + 1][y] - 'A'] = false;
            check = true;
        }
    }
    if (y < c - 1)
    {
        if (!used[s[x][y + 1] - 'A'])
        {
            dfs(x, y + 1, cur + 1);
            used[s[x][y + 1] - 'A'] = false;
            check = true;
        }
    }
    if (!check)
    {
        if (cur + 1 > mMax)
            mMax = cur + 1;
    }
}

int main()
{
    cin >> r >> c;
    int i;
    for (i = 0; i < r; i++)
    {
        cin >> s[i];
    }
    memset(used, false, sizeof(used));
    dfs(0, 0, 0);
    cout << mMax << endl;
    return 0;
}
