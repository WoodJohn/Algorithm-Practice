#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

int cmp(const void *a, const void *b)
{
    int p = *((int *)a);
    int q = *((int *)b);
    return q - p;
}

int main()
{
    int num[101];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &num[i]);
    }
    qsort(num, n, sizeof(int), cmp);
    float result = float(num[0]);
    for (int j = 1; j < n; j ++)
    {
        result = 2 * sqrt(result * float(num[j]));
    }
    printf("%.3f\n", result);
    return 0;
}
