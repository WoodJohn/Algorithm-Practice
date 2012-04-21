#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int t, n;
vector<int> edges[10001];
int p[10001];
int depth[10001];

void buildtree(int root)
{
    for (int i = 0; i < edges[root].size(); i++)
    {
        int temp = edges[root][i];
        depth[temp] = depth[root] + 1;
        buildtree(temp);
    }
}

int lca(int a, int b)
{
    int ta = a;
    int tb = b;
    while (depth[ta] > depth[tb])
    {
        ta = p[ta];
    }
    while (depth[tb] > depth[ta])
    {
        tb = p[tb];
    }
    while (ta != tb)
    {
        ta = p[ta];
        tb = p[tb];
    }
    return ta;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            edges[i].clear();
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            edges[a].push_back(b);
            p[b] = a;
        }
        int root;
        for (int i = 1; i <= n; i++)
        {
            if (p[i] == 0)
            {
                root = i;
                break;
            }
        }
        depth[root] = 0;
        buildtree(root);
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));

    }
    return 0;
}
