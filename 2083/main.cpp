#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int tri[7] = {1, 3, 9, 27, 81, 243, 729};

struct node
{
    int l;
    char **g;
    node(int a = 0) : l(a)
    {
        int i, j;
        g = new char*[tri[a - 1]];
        for (i = 0; i < tri[a - 1]; i++)
            g[i] = new char[tri[a - 1]];
        for (i = 0; i < tri[a - 1]; i++)
        {
            for (j = 0; j < tri[a - 1]; j++)
            {
                g[i][j] = ' ';
            }
        }
    }
}data[7];

bool ava[7];

node calc(int a)
{
    node t;
    if (ava[a - 1])
        return data[a - 1];
    if (a == 1)
    {
        t = node(1);
        t.g[0][0] = 'X';
        data[0] = t;
        ava[0] = true;
        return t;
    }
    t = node(a);
    node sub = calc(a - 1);
    int i, j;
    for (i = 0; i < tri[a - 2]; i++)
    {
        for (j = 0; j < tri[a - 2]; j++)
        {
            t.g[i][j] =
            t.g[i + 2 * tri[a - 2]][j] =
            t.g[i][j + 2 * tri[a - 2]] =
            t.g[i + tri[a - 2]][j + tri[a - 2]] =
            t.g[i + 2 * tri[a - 2]][j + 2 * tri[a - 2]] = sub.g[i][j];
        }
    }
    data[a - 1] = t;
    ava[a - 1] = true;
    return t;
}

void out(node t)
{
//    ofstream fout;
//    fout.open("out.txt", ios::out);
    int r = tri[t.l - 1];
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%c", t.g[i][j]);
        }
        printf("\n");
    }
    printf("-\n");
}

int main()
{
    int n;
    memset(ava, false, sizeof(ava));
    while (cin >> n)
    {
        if (n == -1)
            break;
        out(calc(n));
    }
    return 0;
}
