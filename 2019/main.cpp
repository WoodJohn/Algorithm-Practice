#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int v;
    int index;
    node(int val = 0, int i = 0) : v(val), index(i){}
};

struct result
{
    int max;
    int min;
}dp[251][251];

node qmax[251][251];
node qmin[251][251];

int n, b, k;
int num[251][251];

int hmax[251], tmax[251], curmax[251], hmin[251], tmin[251], curmin[251];

int main()
{
    scanf("%d%d%d", &n, &b, &k);
    int i, j;
    for (i = 0; i < n; i++)
    {
        hmax[i] = hmin[i] = 0;
        tmax[i] = tmin[i] = -1;
        curmax[i] = curmin[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &num[i][j]);
            if (j < b)
            {
                while (hmax[i] <= tmax[i] && tmax[i] >= 0 && qmax[i][tmax[i]].v <= num[i][j])
                    tmax[i]--;
                qmax[i][++tmax[i]] = node(num[i][j], j);
                while (hmin[i] <= tmin[i] && tmin[i] >= 0 && qmin[i][tmin[i]].v >= num[i][j])
                    tmin[i]--;
                qmin[i][++tmin[i]] = node(num[i][j], j);
            }
        }
    }
    for (j = 0; j < n - b + 1; j++)
    {
        for (i = 0; i < n - b + 1; i++)
        {
            int p;
            int mMax = 0;
            int mMin = 1000;
            for (p = 0; p < b; p++)
            {
                if (qmax[i + p][hmax[i + p]].v > mMax)
                    mMax = qmax[i + p][hmax[i + p]].v;

                if (qmin[i + p][hmin[i + p]].v < mMin)
                    mMin = qmin[i + p][hmin[i + p]].v;
            }
            dp[i][j].max = mMax;
            dp[i][j].min = mMin;
        }
        for (i = 0; i < n; i++)
        {
            while (hmax[i] <= tmax[i] && qmax[i][hmax[i]].index <= curmax[i])
                hmax[i]++;
            curmax[i]++;
            while (hmax[i] <= tmax[i] && tmax[i] >= 0 && qmax[i][tmax[i]].v <= num[i][j + b])
                tmax[i]--;
            qmax[i][++tmax[i]] = node(num[i][j + b], j + b);

            while (hmin[i] <= tmin[i] && qmin[i][hmin[i]].index <= curmin[i])
                hmin[i]++;
            curmin[i]++;
            while (hmin[i] <= tmin[i] && tmin[i] >= 0 && qmin[i][tmin[i]].v >= num[i][j + b])
                tmin[i]--;
            qmin[i][++tmin[i]] = node(num[i][j + b], j + b);
        }
    }
    while (k--)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        printf("%d\n", dp[p - 1][q - 1].max - dp[p - 1][q - 1].min);
    }
    return 0;
}

