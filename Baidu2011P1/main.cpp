#include <stdio.h>
#include <stdlib.h>
using namespace std;

int cmp(const void *a, const void *b)
{
    int p = *((int *)a);
    int q = *((int *)b);
    return p - q;
}

int n, m;
int app[100001];

int main()
{
    scanf("%d %d", &n, &m);
    int appsum = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &app[i]);
        appsum += app[i];
    }
    int sum = 0;
    qsort(app, m, sizeof(int), cmp);
    for (int i = 0; i < m; i++)
    {
        if (app[i] == 1)
                continue;
        appsum -= 2;
        sum += appsum + 1;
    }
    printf("%d\n", sum);
    return 0;
}
