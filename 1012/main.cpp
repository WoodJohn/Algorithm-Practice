#include <stdio.h>
#include <string.h>
using namespace std;

int used[28];
int n;

int f(int a, int k)
{
    if (a == 1)
        return 0;
    int t = f(a - 1, k);
    if (t == -1)
        return -1;
    if (a > n)
    {
        if (k - 1 < a - n)
            return -1;
    }
    return (t + k) % a;
}

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            int t = f(2 * n, i);
            if (t != -1)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
