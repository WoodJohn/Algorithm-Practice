#include <iostream>
#include <stdio.h>
using namespace std;

int c[10005];
int y[10005];
int s, n;

int main()
{
    scanf("%d%d", &n, &s);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &c[i], &y[i]);
        int gap = 0;
        int gapi = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (c[i] - c[j] - s * (i - j) > gap)
            {
                gap = c[i] - c[j] - s * (i - j);
                gapi = j;
            }
        }
        if (gapi != -1)
        {
            sum += y[i] * c[gapi] + s * (i - gapi) * y[i];
        }
        else
        {
            sum += c[i] * y[i];
        }
    }
    printf("%I64d\n", sum);
    return 0;
}
