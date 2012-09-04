#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;

int step[10][2] = {{0, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

inline int calc(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - x2 * y1;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char s[1000005];
        cin >> s;
        int l = strlen(s);
        int cx, cy;
        cx = cy = 0;
        long long sum = 0;
        for (int i = 0; i < l - 1; i++)
        {
            int tx = cx + step[s[i] - '0'][0];
            int ty = cy + step[s[i] - '0'][1];
            sum += calc(cx, cy, tx, ty);
            cx = tx;
            cy = ty;
        }
        long long res = fabs(double(sum));
        if (res % 2)
            printf("%I64d.5\n", res / 2);
        else
            printf("%I64d\n", res / 2);
    }
    return 0;
}
