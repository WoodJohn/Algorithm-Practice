#include <iostream>
#include <string.h>
using namespace std;

char s[5][5];
char cur[5][5];
int total;

int mMin;

inline void turn(char &c)
{
    if (c == 'b')
        c = 'w';
    else
        c = 'b';
}

void change(int r, int c)
{
    total++;
    turn(cur[r][c]);
    if (c > 0)
        turn(cur[r][c - 1]);
    if (c < 3)
        turn(cur[r][c + 1]);
    if (r < 3)
        turn(cur[r + 1][c]);
}

void dfs(int n, char goal)
{
    int i;
    if (n >= 16)
        return;
    int a = (n & (1 << 3)) ? 1 : 0;
    int b = (n & (1 << 2)) ? 1 : 0;
    int c = (n & (1 << 1)) ? 1 : 0;
    int d = (n & (1 << 0)) ? 1 : 0;
    memcpy(cur, s, sizeof(s));
    total = 0;
    for (i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            if (a == 1)
            {
                change(i, 0);
            }
            if (b == 1)
            {
                change(i, 1);
            }
            if (c == 1)
            {
                change(i, 2);
            }
            if (d == 1)
            {
                change(i, 3);
            }
        }
        else
        {
            if (cur[i - 1][0] != goal)
                change(i, 0);
            if (cur[i - 1][1] != goal)
                change(i, 1);
            if (cur[i - 1][2] != goal)
                change(i, 2);
            if (cur[i - 1][3] != goal)
                change(i, 3);
        }
    }
    if (cur[3][0] == goal && cur[3][1] == goal && cur[3][2] == goal && cur[3][3] == goal)
    {
        if (total < mMin)
            mMin = total;
    }
    dfs(n + 1, goal);
}

int main()
{
    int i;
    for (i = 0; i < 4; i++)
        cin >> s[i];
    mMin = 100;
    dfs(0, 'b');
    dfs(0, 'w');
    if (mMin == 100)
        cout << "Impossible" << endl;
    else
        cout << mMin << endl;
}
