#include <iostream>

using namespace std;

int n;
int fs[1005];
int ms[1005];
bool check;

struct node
{
    node *l;
    node *r;
    node()
    {
        l = NULL;
        r = NULL;
    }
    int v;
};

node *root;

int seek(int a, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (ms[i] == a)
            return i;
    }
    return -1;
}

void buildTree(node *r, int p, int lsize, int rsize, int lfstart, int rfstart)
{
    if (!check)
        return;
    if (lsize < 0 || rsize < 0 || lfstart > rfstart)
    {
        check = false;
        return;
    }
    r->v = ms[p];
    if (lsize > 0)
    {
        r->l = new node();
        int pos = seek(fs[lfstart], p - lsize, p - 1);
        buildTree(r->l, pos, lsize - p + pos, p - pos - 1, lfstart + 1, lfstart + 1 + lsize - p + pos);
    }
    if (rsize > 0)
    {
        r->r = new node();
        int pos = seek(fs[rfstart], p + 1, p + rsize);
        buildTree(r->r, pos, pos - p - 1, p + rsize - pos, rfstart + 1, rfstart + pos - p);
    }
}

void bvisit(node *r)
{
    if (r->l != NULL)
        bvisit(r->l);
    if (r->r != NULL)
        bvisit(r->r);
    cout << r->v << ' ';
}

int main()
{
    while (cin >> n)
    {
        check = true;
        for (int i = 0; i < n; i++)
        {
            cin >> fs[i];
        }
        int pos;
        for (int i = 0; i < n; i++)
        {
            cin >> ms[i];
            if (ms[i] == fs[0])
                pos = i;
        }
        root = new node();
        buildTree(root, pos, pos, n - pos - 1, 1, pos + 1);
        if (!check)
            cout << "No" << endl;
        else
        {
            bvisit(root);
            cout << endl;
        }
    }
    return 0;
}
