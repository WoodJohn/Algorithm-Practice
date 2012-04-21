#include <stdio.h>
#include <string.h>

using namespace std;

char data[9][9];

int n,k;
bool row[8];
bool col[8];

int sum;

void dfs(int a, int start)
{
    if (a == k + 1)
    {
        sum ++;
        return;
    }
    if (start >= n * n)
    {
        return;
    }
    for (int i = start; i < n * n; i ++)
    {
        int r = i / n;
        int c = i % n;
        if (row[r] || col[c] || data[r][c] == '.')
            continue;
        row[r] = true;
        col[c] = true;
        dfs(a + 1, i + 1);
        row[r] = false;
        col[c] = false;
    }
}

int main()
{
    while (scanf("%d %d", &n, &k))
    {
        if (n == -1 && k == -1)
            break;
        sum = 0;
        memset(data, 0, sizeof(data));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for (int i = 0; i < n; i ++)
        {
            scanf("%s", data[i]);
        }
        dfs(1, 0);
        printf("%d\n", sum);
    }
    return 0;
}
