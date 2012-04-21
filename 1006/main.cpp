#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int p, e, i, d;
    int cnt = 1;
    while (scanf("%d%d%d%d", &p, &e, &i, &d))
    {
        if (p == -1)
            break;
        int cap = i % 33;
        while (cap <= d)
            cap += 33;
        while ((cap - e) % 28 != 0)
            cap += 33;
        while ((cap - p) % 23 != 0)
            cap += 33 * 28;
        printf("Case %d: the next triple peak occurs in %d days.\n", cnt++, cap - d);
    }
    return 0;
}
