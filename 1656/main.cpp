#include <iostream>
#include <string.h>
using namespace std;

int a[101][101];
const int N = 100;

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int a, int b, int v)
{
    int x, y;
    for (x = a; x <= N; x += lowbit(x))
    {
        for (y = b; y <= N; y += lowbit(y))
        {
            a[x][y] += v;
        }
    }
}

int sum(int a, int b)
{
    int x, y;
    int s = 0;
    for (x = a; x >= 0; x -= lowbit(x))
    {
        for (y = b; y >= 0; y -= lowbit(y))
        {
            s += a[x][y];
        }
    }
    return s;
}

int get(int a, int b, int l)
{
    int s1 = sum(a + l - 1, b + l - 1);
    int s2 = sum(a - 1, b - 1);
    int s3 = sum(a - 1, b + l - 1);
    int s4 = sum(a + l - 1, b - 1);
    return s1 - s3 - s4 + s2;
}

int main()
{
    char s[10];
    int a, b, l;
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    while (n--)
    {
        cin >> s >> a >> b >> l;
        if (strcmp(s, "TEST") == 0)
        {

        }
    }
    return 0;
}
