#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int num[10001];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n, cmp);
    printf("%d\n", num[n / 2]);
    return 0;
}
