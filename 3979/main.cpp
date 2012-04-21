#include <stdio.h>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int gcd(int a, int b)
{
    int mMax = a;
    int mMin = b;
    if (a < b)
    {
        mMax = b;
        mMin = a;
    }
    if (mMax % mMin == 0)
        return mMin;
    return gcd(mMin, mMax % mMin);
}

int main()
{
    int a, b, c, d;
    char o;
    while (scanf("%d/%d%c%d/%d", &a, &b, &o, &c, &d) != EOF)
    {
        int lcm = b * d / gcd(b, d);
        a *= (lcm / b);
        c *= (lcm / d);
        int result;
        if (o == '+')
        {
            result = a + c;
        }
        else
        {
            result = a - c;
        }
        bool minus = (result < 0);
        if (result == 0)
        {
            printf("0\n");
            continue;
        }
        if (minus)
            result = -result;
        int gg = gcd(result, lcm);
        result /= gg;
        lcm /= gg;
        if (minus)
            printf("-");
        if (result % lcm == 0)
            printf("%d\n", result / lcm);
        else
            printf("%d/%d\n", result, lcm);
    }
    return 0;
}
