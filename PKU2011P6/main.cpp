#include <stdio.h>
const int init[2] = {2,6};

int r[2];

void arraypower(int result[2], int n, int m)
{
    int tresult[2] = {2, 6};
    int temp[2][2] = {{0, -1},{1, 4}};
    int ttemp[2][2];
    while (n)
    {
        long long tt;
        if (n & 1)
        {
            tt = (long long)result[0] * (long long)temp[0][0] + (long long)result[1] * (long long)temp[1][0];;
            tresult[0] = tt % m;
            if (tresult[0] < 0)
                tresult[0] += m;
            tt = (long long)result[0] * (long long)temp[0][1] + (long long)result[1] * (long long)temp[1][1];
            tresult[1] = tt % m;
            if (tresult[1] < 0)
                tresult[0] += m;
            result[0] = tresult[0] % m;
            result[1] = tresult[1] % m;
        }

        tt = (long long)temp[0][0] * (long long)temp[0][0] + (long long)temp[0][1] * (long long)temp[1][0];
        ttemp[0][0] = tt % m;;
        if (ttemp[0][0] < 0)
            ttemp[0][0] += m;
        tt = (long long)temp[0][0] * (long long)temp[0][1] + (long long)temp[0][1] * (long long)temp[1][1];
        ttemp[0][1] = tt % m;
        if (ttemp[0][1] < 0)
            ttemp[0][1] += m;
        tt = (long long)temp[1][0] * (long long)temp[0][0] + (long long)temp[1][1] * (long long)temp[1][0];
        ttemp[1][0] = tt % m;
        if (ttemp[1][0] < 0)
            ttemp[1][0] += m;
        tt = (long long)temp[1][0] * (long long)temp[0][1] + (long long)temp[1][1] * (long long)temp[1][1];
        ttemp[1][1] = tt % m;
        if (ttemp[1][1] < 0)
            ttemp[1][1] += m;
        temp[0][0] = ttemp[0][0] % m;
        temp[0][1] = ttemp[0][1] % m;
        temp[1][0] = ttemp[1][0] % m;
        temp[1][1] = ttemp[1][1] % m;

        n >>= 1;
    }
}

int main()
{
    int t,k;
    int n;
    scanf("%d", &t);
    k = 1;
    while (t --)
    {
        scanf("%d", &n);
        if (n == 1)
        {
            printf("Case %d: 1\n", k ++);
            continue;
        }
        r[0] = init[0];
        r[1] = init[1];
        arraypower(r, n - 1, 1000000007);
        printf("Case %d: %d\n", k ++, r[0]);
    }
    return 0;
}
