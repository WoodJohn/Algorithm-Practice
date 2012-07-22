#include <iostream>
#include <string.h>
#include <stdio.h>
#define N 505
using namespace std;

char fibs[N][205];
int cnt;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

bool lt(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    if (la != lb)
        return la < lb;
    for (int i = 0; i < la; i++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return true;
}

bool gt(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    if (la != lb)
        return la > lb;
    for (int i = 0; i < la; i++)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return false;
}

char *sum(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    int l = max(la, lb) + 1;
    int ma = max(la, lb);
    int mi = la + lb - ma;
    char *ret = new char[l];
    for (int i = 0; i < l; i++)
        ret[i] = '0';
    for (int i = 0; i < ma; i++)
    {
        if (i < mi)
        {
            ret[l - i - 1] += a[la - i - 1] - '0' + b[lb - i - 1] - '0';
            if (ret[l - i - 1] > '9')
            {
                ret[l - i - 1] -= 10;
                ret[l - i - 2]++;
            }
        }
        else if (la == ma)
        {
            ret[l - i - 1] += a[la - i - 1] - '0';
            if (ret[l - i - 1] > '9')
            {
                ret[l - i - 1] -= 10;
                ret[l - i - 2]++;
            }
        }
        else
        {
            ret[l - i - 1] += b[lb - i - 1] - '0';
            if (ret[l - i - 1] > '9')
            {
                ret[l - i - 1] -= 10;
                ret[l - i]++;
            }
        }
    }
    ret[l] = '\0';
    if (ret[0] == '0')
        return ret + 1;
    return ret;
}

void calc()
{
    strcpy(fibs[cnt++], "1");
    strcpy(fibs[cnt++], "2");
    for (int i = 2; i < N; i++)
    {
        strcpy(fibs[i], sum(fibs[i - 1], fibs[i - 2]));
        cnt++;
    }
}

int main()
{
    char a[105], b[105];
    cnt = 0;
    calc();
    while (scanf("%s%s", a, b))
    {
        if (a[0] == '0' && b[0] == '0')
            break;
        for (int i = 0; i < cnt; i++)
        {
            if (lt(a, fibs[i]))
            {
                int j;
                for (j = i; j < cnt; j++)
                {
                    if (gt(fibs[j], b))
                    {
                        cout << j - i << endl;
                        break;
                    }
                }
                if (j == cnt)
                    cout << 0 << endl;
                break;
            }
        }
    }
    return 0;
}
