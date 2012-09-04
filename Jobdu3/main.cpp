#include <iostream>
#include <stdio.h>
#define INF 999999999
using namespace std;

int n;
int num[1000005];

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        int mMin = INF;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            if (num[i] < mMin)
                mMin = num[i];
        }
        printf("%d\n", mMin);
    }
    return 0;
}
