#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char matrix[105][105];
int n;

struct point
{
    int x;
    int y;
};

point getNext(int x, int y, int loop)
{
    point ret;
    if (loop % 2)
    {
        if (x == loop)
        {
            if (y < n - loop - 1)
            {
                ret.x = x;
                ret.y = y + 1;
                return ret;
            }
            else
            {
                ret.x = x + 1;
                ret.y = y;
                return ret;
            }
        }
        else if (y == loop)
        {
            ret.x = x - 1;
            ret.y = y;
            return ret;
        }
        else if (y == n - loop - 1)
        {
            if (x < n - loop - 1)
            {
                ret.x = x + 1;
                ret.y = y;
                return ret;
            }
            else
            {
                ret.x = x;
                ret.y = y - 1;
                return ret;
            }
        }
        else
        {
            ret.x = x;
            ret.y = y - 1;
            return ret;
        }
    }
    else
    {
        if (x == loop)
        {
            if (y > loop)
            {
                ret.x = x;
                ret.y = y - 1;
                return ret;
            }
            else
            {
                ret.x = x + 1;
                ret.y = y;
                return ret;
            }
        }
        else if (y == loop)
        {
            if (x < n - loop - 1)
            {
                ret.x = x + 1;
                ret.y = y;
                return ret;
            }
            else
            {
                ret.x = x;
                ret.y = y + 1;
                return ret;
            }
        }
        else if (y == n - loop - 1)
        {
            ret.x = x - 1;
            ret.y = y;
            return ret;
        }
        else
        {
            ret.x = x;
            ret.y = y + 1;
            return ret;
        }
    }
}

void init(char s[])
{
    int cnt = 0;
    int alpha = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cnt < strlen(s))
            {
                matrix[i][j] = s[cnt++];
                if (matrix[i][j] >= 'a' && matrix[i][j] <= 'z')
                    matrix[i][j] -= 32;
            }
            else
            {
                matrix[i][j] = 'A' + alpha;
                alpha = (alpha + 1) % 26;
            }
        }
    }
}

void shake()
{
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        if (i % 2)
        {
            char temp = matrix[n - 1][i];
            for (j = n - 1; j > 0; j--)
                matrix[j][i] = matrix[j - 1][i];
            matrix[0][i] = temp;
        }
        else
        {
            char temp = matrix[0][i];
            for (j = 0; j < n - 1; j++)
                matrix[j][i] = matrix[j + 1][i];
            matrix[n - 1][i] = temp;
        }
    }
}

void rattle()
{
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        if (i % 2)
        {
            char temp = matrix[i][0];
            for (j = 0; j < n - 1; j++)
                matrix[i][j] = matrix[i][j + 1];
            matrix[i][n - 1] = temp;
        }
        else
        {
            char temp = matrix[i][n - 1];
            for (j = n - 1; j > 0; j--)
                matrix[i][j] = matrix[i][j - 1];
            matrix[i][0] = temp;
        }
    }
}

void roll()
{
    int i;
    for (i = 0; i < (n + 1) / 2; i++)
    {
        if (i == n - i - 1)
            return;
        char temp = matrix[i][i];
        point next = getNext(i, i, i);
        int x = i;
        int y = i;
        int nx = next.x;
        int ny = next.y;
        while (!(nx == i && ny == i))
        {
            matrix[x][y] = matrix[nx][ny];
            x = nx;
            y = ny;
            next = getNext(x, y, i);
            nx = next.x;
            ny = next.y;
        }
        matrix[x][y] = temp;
    }
}

int main()
{
    char k[85], s[10005];
    while (cin >> k)
    {
        n = (k[0] - '0') * 10 + (k[1] - '0');
        if (n == 0)
            n = 100;
        getchar();
        cin.getline(s, 10005);
        init(s);
        for (int i = 2; i < strlen(k); i++)
        {
            if (k[i] == 'S')
                shake();
            if (k[i] == 'R')
                rattle();
            if (k[i] == 'L')
                roll();
        }
        for (int i = 0; i < n; i++)
            cout << matrix[i];
        cout << endl;
    }
    return 0;
}
