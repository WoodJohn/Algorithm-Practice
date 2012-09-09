#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int v;
    node *l;
    node *r;
    node()
    {
        l = r = NULL;
    }
};

node *root;
int n;
int pos;
int num[10005];
bool check;

void insert(int v, node *t)
{
    if (v < t->v)
    {
        if (t->l == NULL)
        {
            t->l = new node();
            t->l->v = v;
        }
        else
            insert(v, t->l);
    }
    else
    {
        if (t->r == NULL)
        {
            t->r = new node();
            t->r->v = v;
        }
        else
            insert(v, t->r);
    }
}

void bt(node *r)
{
    if (!check)
        return;
    if (r->l)
        bt(r->l);
    if (r->r)
        bt(r->r);
    if (num[pos] != r->v)
        check = false;
    pos++;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        check = true;
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        root = new node();
        root->v = num[n - 1];
        for (int i = n - 2; i >= 0; i--)
            insert(num[i], root);
        pos = 0;
        bt(root);
        if (check)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
