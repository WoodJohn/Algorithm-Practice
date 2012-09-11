#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#define N 100007
using namespace std;

struct node
{
    int v;
    int c;
    node()
    {
        c = 1;
    }
};

int n;
bool check;

int inline key(int a)
{
    return a % N;
}

int find(int a, vector<node> ht[])
{
    if (check)
        return -1;
    int k = key(a);
    for (int i = 0; i < ht[k].size(); ++i)
    {
        if (ht[k][i].v == a)
        {
            ++ht[k][i].c;
            if (ht[k][i].c > n / 2)
            {
                printf("%d\n", ht[k][i].v);
                check = true;
            }
            return i;
        }
    }
    return -1;
}

void insert(int a, vector<node> ht[])
{
    if (check)
        return;
    int k = key(a);
    int i = find(a, ht);
    if (i == -1)
    {
        node t;
        t.v = a;
        ht[k].push_back(t);
    }
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        check = false;
        vector<node> ht[N];
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            if (n == 1)
            {
                printf("%d\n", a);
                check = true;
            }
            else
                insert(a, ht);
        }
        if (!check)
            printf("-1\n");
    }
    return 0;
}
