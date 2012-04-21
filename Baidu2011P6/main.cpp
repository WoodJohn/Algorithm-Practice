#include <stdio.h>
#include <string.h>
using namespace std;

int tree[100001];
int n, m;

int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a % b == 0)
        return b;
    int r = a % b;
    return gcd(b, r);
}

int lowbit(int x)
{
    return x & (-x);
}

void update(int v, int x)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tree[i] += v;
    }
}

int sum(int x)
{
    int r = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        r += tree[i];
    }
    return r;
}

int main()
{
    scanf("%d %d", &n, &m);
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        update(t, i);
    }
    double max = 0;
    int big = 0;
    int small = 0;
    for (int i = m; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            int temp = sum(j + i) - sum(j);
            if (double(temp) / double(i) > max)
            {
                max = double(temp) / double(i);
                big = temp;
                small = i;
            }
        }
    }
    int temp = gcd(big, small);
    if (temp == small)
        printf("%d\n", big / small);
    else
        printf("%d/%d", big / temp, small / temp);
    return 0;
}
