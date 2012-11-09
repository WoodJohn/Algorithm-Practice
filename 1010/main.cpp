#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int num[100];
int count[100];
int maxLen;
int mMax;
int minCount;
int cnt;
int res[100];
bool tie;

void dfs(int cur, int cou, int sum, int len, int m)
{
    if (cnt - cur + len < maxLen)
        return;
    if (sum == 0)
    {
        if (len == maxLen)
        {
            if (cou < minCount)
            {
                tie = false;
                minCount = cou;
                memcpy(res, count, sizeof(count));
            }
            else if (cou == minCount && m > mMax)
            {
                mMax = m;
                tie = false;
                memcpy(res, count, sizeof(count));
            }
            else if (cou == minCount && m == mMax)
            {
                tie = true;
            }
            return;
        }
        if (len > maxLen)
        {
            tie = false;
            maxLen = len;
            minCount = cou;
            mMax = m;
            memcpy(res, count, sizeof(count));
            return;
        }
    }
    else
    {
        for (int i = 0; i <= sum / num[cur]; ++i)
        {
            count[num[cur]] = i;
            int mm = num[cur] > m ? num[cur] : m;
            dfs(cur + 1, cou + i, sum - i * num[cur], len + 1, mm);
        }
    }
}

void output(int a)
{
    if (maxLen == 0)
    {
        printf("%d ---- none\n", a);
    }
    else
    {
        if (tie)
        {
            printf("%d (%d): tie\n", a, maxLen);
        }
        else
        {
            printf("%d (%d): ", a, maxLen);
            int cc = 0;
            bool f = true;
            for (int i = 0; i < 100; ++i)
            {
                if (res[i])
                {
                    cc += res[i];
                    for (int j = 0; j < res[i]; ++j)
                    {
                        if (f)
                        {
                            printf("%d", i);
                            f = false;
                        }
                        else
                        {
                            printf(" %d", i);
                        }
                    }
                    if (cc >= minCount)
                        break;
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    int first;
    while (scanf("%d", &first) != EOF)
    {
        cnt = 0;
        num[cnt++] = first;
        while (first)
        {
            scanf("%d", &first);
            num[cnt++] = first;
        }
        int a = 1000;
        while (a)
        {
            tie = false;
            mMax = 0;
            maxLen = 0;
            memset(count, 0, sizeof(count));
            dfs(0, 0, a, 0, 0);
            output(a);
        }
    }
    return 0;
}
