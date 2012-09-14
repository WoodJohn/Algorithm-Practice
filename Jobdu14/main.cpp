#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, k;

int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
    {
        int num[200005];
        for (int i = 0; i < n / 5; ++i)
        {
            scanf("%d%d%d%d%d", &num[i * 5], &num[i * 5 + 1], &num[i * 5 + 2], &num[i * 5 + 3], &num[i * 5 + 4]);
        }
        int t = n % 5;
        for (int i = 0; i < t; ++i)
        {
            scanf("%d", &num[n - t + i]);
        }
        make_heap(num, num + n, greater<int>());
        for (int i = 0; i < k - 1; i++)
        {
            printf("%d ", num[0]);
            pop_heap(num, num + n - i, greater<int>());
        }
        printf("%d\n", num[0]);
    }
    return 0;
}

