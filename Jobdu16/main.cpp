#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int sum[10] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int a, b;

int inline max(int p, int q)
{
    return p > q ? p : q;
}

int digit(int n)
{
    int ret = 0;
    int t = n;
    while (t)
    {
        ++ret;
        t /= 10;
    }
    return ret;
}

int highdigit(int n)
{
    int t = n;
    while (t)
    {
        if (t < 10)
            return t;
        t /= 10;
    }
    return 0;
}

int calc(int n)
{
    if (n <= 0)
        return 0;
    int ret = 0;
    int d = digit(n);
    int first = highdigit(n);
    int low = n - first * ten[d - 1];
    ret += first * sum[d - 1];
    if (first > 1)
        ret += ten[d - 1];
    else
        ret += low + 1;
    return ret + calc(low);
}

int main()
{
    while (scanf("%d%d", &a, &b) != EOF)
    {
        int s = a + b;
        b = max(a, b);
        a = s - b;
        printf("%d\n", calc(b) - calc(a - 1));
    }
    return 0;
}
