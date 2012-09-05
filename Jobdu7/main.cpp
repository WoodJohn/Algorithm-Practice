#include <iostream>
#include <string.h>
using namespace std;

char dp[75][200];

int inline max(int a, int b)
{
    return a > b ? a : b;
}

char *add(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    int lm = max(la, lb) + 1;
    char *ret = new char[lm];
    for (int i = 0; i < lm; i++)
        ret[i] = '0';
    for (int i = 0; i < lm - 1; i++)
    {
        if (la > i)
            ret[lm - i - 1] += a[la - i - 1] - '0';
        if (lb > i)
            ret[lm - i - 1] += b[lb - i - 1] - '0';
        if (ret[lm - i - 1] > '9')
        {
            ret[lm - i - 1] -= 10;
            ret[lm - i - 2]++;
        }
    }
    if (ret[0] == '0')
    {
        for (int i = 0; i < lm - 1; i++)
        {
            ret[i] = ret[i + 1];
        }
        ret[lm - 1] = '\0';
    }
    else
        ret[lm] = '\0';
    return ret;
}

char *f(int a)
{
    if (a == 1)
        return "1";
    if (a == 2)
        return "2";
    if (strcmp(dp[a], "0"))
        return dp[a];
    strcpy(dp[a], add(f(a - 1), f(a - 2)));
    return dp[a];
}

int main()
{
    int n;
    for (int i = 0; i < 71; i++)
    {
        strcpy(dp[i], "0");
    }
    strcpy(dp[1], "1");
    strcpy(dp[2], "2");
    while (cin >> n)
        cout << f(n) << endl;
    return 0;
}
