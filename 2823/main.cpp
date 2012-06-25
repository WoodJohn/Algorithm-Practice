#include <iostream>
#include <stdio.h>
#define N 1000005
using namespace std;

struct node
{
    int v;
    int i;
    node(int val = 0, int index = 0) : v(val) , i(index)
    {
    }
};

node qmax[N];
node qmin[N];
int num[N];
int hmax, hmin, tmax, tmin, curmax, curmin;

int main()
{
    int n, k;
    hmax = hmin = curmax = curmin = 0;
    tmax = tmin = -1;
    scanf("%d%d", &n, &k);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (i = 0; i < k; i++)
    {
        while (hmax <= tmax && qmax[tmax].v <= num[i])
            tmax--;
        qmax[++tmax] = node(num[i], i);

        while (hmin <= tmin && qmin[tmin].v >= num[i])
            tmin--;
        qmin[++tmin] = node(num[i], i);
    }
    printf("%d", qmin[hmin].v);
    for (i = 0; i < n - k; i++)
    {
        printf(" ");
        while (hmin <= tmin && qmin[hmin].i <= curmin)
            hmin++;
        curmin++;
        while (hmin <= tmin && qmin[tmin].v >= num[i + k])
            tmin--;
        qmin[++tmin] = node(num[i + k], i + k);
        printf("%d", qmin[hmin].v);
    }
    printf("\n%d", qmax[hmax].v);
    for (i = 0; i < n - k; i++)
    {
        printf(" ");
        while (hmax <= tmax && qmax[hmax].i <= curmax)
            hmax++;
        curmax++;
        while (hmax <= tmax && qmax[tmax].v <= num[i + k])
            tmax--;
        qmax[++tmax] = node(num[i + k], i + k);
        printf("%d", qmax[hmax].v);
    }
    printf("\n");
    return 0;
}
