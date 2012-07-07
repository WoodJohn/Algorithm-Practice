#include <iostream>
#include <string.h>
using namespace std;

int n;
char g[35][35];
bool v[35][35];
int sum;

void ff(int x, int y)
{
    v[x][y] = true;
    if (x > 0 && !v[x - 1][y] && g[x - 1][y] == '.')
        ff(x - 1, y);
    if (y > 0 && !v[x][y - 1] && g[x][y - 1] == '.')
        ff(x, y - 1);
    if (x < n - 1 && !v[x + 1][y] && g[x + 1][y] == '.')
        ff(x + 1, y);
    if (y < n - 1 && !v[x][y + 1] && g[x][y + 1] == '.')
        ff(x, y + 1);
}

void calc()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j])
            {
                if (i == 0 || g[i - 1][j] == '#')
                    sum++;
                if (j == 0 || g[i][j - 1] == '#')
                    sum++;
                if (i == n - 1 || g[i + 1][j] == '#')
                    sum++;
                if (j == n - 1 || g[i][j + 1] == '#')
                    sum++;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    memset(v, false, sizeof(v));
    ff(0, 0);
    ff(n - 1, n - 1);
    sum = 0;
    calc();
    cout << (sum - 4) * 9 << endl;
    return 0;
}
