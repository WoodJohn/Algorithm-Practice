#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

vector<int> g[1005];
bool check;
bool used[1005];
int n;

void dfs(int start, int a)
{
    if (check)
        return;
    int i;
    for (i = 0; i < g[a].size(); i++)
    {
        if (g[a][i] == start)
            continue;
        if (used[g[a][i]])
        {
            check = true;
            return;
        }
        used[g[a][i]] = true;
        dfs(start, g[a][i]);
    }
}

int main()
{
    int t, i;
    FILE *out = fopen("out.out", "w");
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        memset(g, false, sizeof(g));
        cin >> n;
        int j;
        for (j = 1; j <= n; j++)
        {
            int k;
            cin >> k;
            for (int p = 0; p < k; p++)
            {
                int a;
                cin >> a;
                g[j].push_back(a);
            }
        }
        check = false;
        for (j = 1; j <= n; j++)
        {
            if (check)
                break;
            memset(used, false, sizeof(used));
            dfs(j, j);
        }
        if (!check)
            fprintf(out, "Case #%d: No\n", i);
        else
            fprintf(out, "Case #%d: Yes\n", i);
    }
    return 0;
}
