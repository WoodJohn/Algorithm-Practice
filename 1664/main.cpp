#include <stdio.h>

int find(int a, int b)
{
    if (a < 0)
        return 0;
    if (a <= 1 || b <= 1)
        return 1;
    return find(a - b, b) + find(a, b - 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", find(a, b));
    }
    return 0;
}
