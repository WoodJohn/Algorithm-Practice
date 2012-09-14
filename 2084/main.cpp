#include <iostream>
#include <string.h>
using namespace std;

char dp[105][200];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

char *add(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    int lm = max(la, lb);
    char *ts = new char[lm + 1];
    for (int i = 0; i < lm + 1; i++)
        ts[i] = '0';
    for (int i = 0; i < lm; i++)
    {
        int t = 0;
        if (i < la)
            t += a[la - 1 - i] - '0';
        if (i < lb)
            t += b[lb - 1 - i] - '0';
        ts[lm - i] += t;
        if (ts[lm - i] > '9')
        {
            ts[lm - i] -= 10;
            ts[lm - i - 1]++;
        }
    }
    if (ts[0] == '0')
    {
        for (int i = 0; i < lm; i++)
            ts[i] = ts[i + 1];
        ts[lm] = '\0';
    }
    ts[lm + 1] = '\0';
    return ts;
}

char *mul(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    char *ts = new char[la + lb];
    for (int i = 0; i < la + lb; i++)
        ts[i] = '0';
    for (int i = la - 1; i >= 0; i--)
    {
        for (int j = lb - 1; j >= 0; j--)
        {
            int t = (a[i] - '0') * (b[j] - '0');
            ts[i + j + 1] += t % 10;
            ts[i + j] += t / 10;
            if (ts[i + j + 1] > '9')
            {
                ts[i + j + 1] -= 10;
                ts[i + j]++;
            }
        }
    }
    if (ts[0] == '0')
    {
        for (int i = 0; i < la + lb - 1; i++)
            ts[i] = ts[i + 1];
        ts[la + lb - 1] = '\0';
    }
    ts[la + lb] = '\0';
    return ts;
}

char* calc(int a)
{
    if (a == 0)
        return "1";
    if (a == 1)
        return "1";
    if (strcmp(dp[a], "0") != 0)
        return dp[a];
    char ret[200] = "0";
    for (int i = 0; i < a; i++)
    {
        strcpy(ret, add(ret, mul(calc(i), calc(a - i - 1))));
    }
    strcpy(dp[a], ret);
    return dp[a];
}

int main()
{
    for (int i = 0; i < 105; i++)
        strcpy(dp[i], "0");
    strcpy(dp[0], "1");;
    strcpy(dp[1], "1");;
    int n;
    while (cin >> n)
    {
        if (n == -1)
            break;
        cout << calc(n) << endl;
        //cout << add("978", "255") << endl;
    }
    return 0;
}
