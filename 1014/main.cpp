#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool can[120005];
bool dp[7][90];

int main()
{
    int num[90];
    int t[7];
    int times = 0;
    int cnt;
    bool check;
    int sum;
    while (1)
    {
        check = false;
        sum = 0;
        ++times;
        cnt = 0;
        for (int i = 1; i < 7; ++i)
        {
            cin >> t[i];
            sum += t[i] * i;
            if (t[i] > 0)
                check = true;
        }
        if (!check)
            break;
        printf("Collection #%d:\n", times);
        if (sum % 2)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        memset(can, false, sizeof(can));
        for (int i = 1; i < 7; ++i)
        {
            for (int j = 1; j <= t[i]; j <<= 1)
            {
                num[cnt++] = j * i;
                t[i] -= j;
            }
            if (t[i] > 0)
            {
                num[cnt++] = t[i] * i;
            }
        }
        can[0] = true;
        for (int i = 0; i < cnt; ++i)
        {
            for (int j = sum; j >= 0; --j)
            {
                if (can[j])
                    can[j + num[i]] = true;
            }
        }
        if (can[sum / 2])
        {
            printf("Can be divided.\n\n");
        }
        else
        {
            printf("Can't be divided.\n\n");
        }
    }
    return 0;
}
