#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int inline min(int a, int b)
{
    return a < b ? a : b;
}

int pre[10005];
int sum;
int n, total;

struct node
{
    int v;
    int index;
    node *l, *r;
    node()
    {
        l = r = NULL;
    }
};

node *nodes[10005];

vector<int> results[10005];

bool cmp(vector<int> a, vector<int> b)
{
    int la = a.size();
    int lb = b.size();
    int l = min(a.size(), b.size());
    for (int i = 0; i < l; i++)
    {
        if (a[la - i - 1] < b[lb - i - 1])
            return true;
        else if (a[la - i - 1] > b[lb - i - 1])
            return false;
    }
    if (la == l)
        return true;
    return false;
}

void dfs(node *r, int s)
{
    if (r->l == NULL && r->r == NULL && s == sum)
    {
        int t = r->index;
        while (t != 0)
        {
            results[total].push_back(t);
            t = pre[t];
        }
        total++;
    }
    else
    {
//        if (s >= sum)
//            return;
        if (r->l)
        {
            pre[r->l->index] = r->index;
            dfs(r->l, s + r->l->v);
        }
        if (r->r)
        {
            pre[r->r->index] = r->index;
            dfs(r->r, s + r->r->v);
        }
    }
 }

int main()
{
    while (scanf("%d%d", &n, &sum) != EOF)
    {
        for (int i = 0; i <= n; i++)
        {
            nodes[i] = new node();
            nodes[i]->index = i;
            results[i].clear();
        }
        total = 0;
        for (int i = 0; i < n; i++)
        {
            int v, a, b;
            scanf("%d%d%d", &v, &a, &b);
            nodes[i + 1]->v = v;
            if (a != -1)
                nodes[i + 1]->l = nodes[a];
            if (b != -1)
                nodes[i + 1]->r = nodes[b];
        }
        pre[1] = 0;
        dfs(nodes[1], nodes[1]->v);
        printf("result:\n");
        if (total > 0)
            sort(results, results + total, cmp);
        for (int i = 0; i < total; i++)
        {
            printf("A path is found:");
            for (int j = 0; j < results[i].size(); j++)
            {
                printf(" %d", results[i][results[i].size() - 1 - j]);
            }
            printf("\n");
        }
    }
    return 0;
}
