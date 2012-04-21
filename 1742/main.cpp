#include <stdio.h>
#include <string.h>

using namespace std;

int c[101];
int a[101];
int n,m;
bool used[100001];
int sum;

void dfs(int x, int s)
{
    if (x == n || a[x] > m || s > m)
        return;
    for (int i = 0; i <= c[x]; i++)
    {
        if (s + i * a[x] > m)
            break;
        if (s + i * a[x] > 0 && !used[s + i * a[x]])
        {
            sum++;
            used[s + i * a[x]] = true;
        }
        dfs(x + 1, s + i * a[x]);
    }
}

int main()
{
    while (scanf("%d %d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        memset(used, 0, sizeof(used));
        sum = 0;
        dfs(0, 0);
        printf("%d\n", sum);
    }
    return 0;
}
