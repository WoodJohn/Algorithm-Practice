#include <iostream>
#include <string.h>
using namespace std;

bool v[105][105];
bool used[105];
int t, p;

bool check(int a, int b)
{
    for (int i = 1; i <= t; i++)
    {
        if (v[a][i] != v[b][i])
            return false;
    }
    return true;
}

int main()
{
    memset(v, false, sizeof(v));
    memset(used, false, sizeof(used));
    cin >> p >> t;
    int a, b;
    while (cin >> a >> b)
    {
        v[a][b] = true;
    }
    int sum = p;
    for (int i = 1; i < p; i++)
    {
        for (int j = i + 1; j <= p; j++)
        {
            if (!used[j] && check(i, j))
            {
                sum--;
                used[j] = true;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
