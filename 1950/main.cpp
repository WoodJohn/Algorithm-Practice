#include <stdio.h>

using namespace std;

int n;

char result[15];
int count;

void printresult()
{
    count ++;
    if (count >= 21)
        return;
    for (int i = 1; i < n; i ++)
    {
        printf("%d %c ", i, result[i - 1]);
    }
    printf("%d\n", n);
}

void dfs(int pos, int lastop, int lastval, int sum)
{
    if (pos == n)
    {
        if (sum == 0)
            printresult();
        return;
    }
    for (int i = 0; i < 3; i ++)
    {
        if (i == 0)
        {
            result[pos - 1] = '+';
            dfs(pos + 1, 0, pos + 1, sum + pos + 1);
        }
        if (i == 1)
        {
            result[pos - 1] = '-';
            dfs(pos + 1, 1, pos + 1, sum - pos - 1);
        }
        if (i == 2)
        {
            result[pos - 1] = '.';
            int v = lastval;
            int s = sum;
            if (lastop == 0)
            {
                s -= v;
            }
            else
            {
                s += v;
            }
            if (pos >= 9)
            {
                v = v * 100 + pos + 1;
            }
            else
            {
                v = v * 10 + pos + 1;
            }
            if (lastop == 0)
            {
                s += v;
            }
            else
            {
                s -= v;
            }
            dfs(pos + 1, lastop, v, s);
        }
    }
}


int main()
{
    scanf("%d", &n);
    result[n - 1] = '\0';
    dfs(1, 0, 1, 1);
    printf("%d\n", count);
    return 0;
}
