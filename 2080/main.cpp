#include <iostream>
#include <stdio.h>
using namespace std;

char day[7][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int a)
{
    if (a % 400 == 0)
        return true;
    if (a % 4 == 0)
    {
        if (a % 100 == 0)
            return false;
        return true;
    }
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == -1)
            break;
        int d = (n + 6) % 7;
        int nextrun = 2000;
        int cury = 2000;
        while (1)
        {
            int ytg = nextrun - cury;
            if (n >= ytg * 365)
            {
                n -= ytg * 365;
                cury = nextrun;
                nextrun += 4;
                while (!check(nextrun))
                    nextrun += 4;
            }
            else
            {
                cury += n / 365;
                n %= 365;
                break;
            }
            if (n >= 366)
            {
                n -= 366;
                cury++;
            }
            else
                break;
        }
        month[1] = check(cury) ? 29 : 28;
        int m = 1;
        while (n >= month[m - 1])
        {
            n -= month[m - 1];
            m++;
        }
        printf("%4d-%02d-%02d %s\n", cury, m, n + 1, day[d]);
    }
    return 0;
}
