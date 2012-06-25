#include <iostream>

using namespace std;

int tri[7] = {1, 3, 9, 27, 81, 243, 729};

struct node
{
    int l;
    char **g;
    node(int a = 0) : l(a)
    {
        int i;
        for (i = 0; i < tri[a - 1]; i++)
            g[i] = new char[tri[a - 1]];

    }
};

node *data[7];

node calc(int a)
{
    node t;
    if (data[a - 1] != NULL)
        return *(data[a - 1]);
    if (a == 1)
    {
        t = node(1);
        t.g[0][0] = 'X';
        data[0]
        return t;
    }
    t = node(a);
    node sub = calc(a - 1);
    return t;
}

void out(node t)
{
    int r = tri[t.l - 1];
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            cout << t.g[i][j];
        }
        cout << endl;
    }
    cout << "-" << endl;
}

int main()
{
    int n;
    for (int i = 0; i < 7; i++)
        data[i] = NULL;
    while (cin >> n)
    {
        if (n == -1)
            break;
        out(calc(n));
    }
    return 0;
}
