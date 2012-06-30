#include <iostream>
#include <stdio.h>
using namespace std;

inline int lowbit(int x)
{
    return x & (-x);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d %d\n", n - lowbit(n) + 1, n + lowbit(n) - 1);
    }
    return 0;
}
