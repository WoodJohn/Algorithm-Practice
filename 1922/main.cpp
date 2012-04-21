#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }
        int min = 99999999;
        for (int i = 0; i < n; i ++)
        {
            int v,t;
            scanf("%d\t%d", &v, &t);
            if (t < 0)
            {
                continue;
            }
            int temp = ceil(4.5 * 3600.0 / float(v) + t);
            if (temp < min)
            {
                min = temp;
            }
        }
        printf("%d\n", min);
    }
    return 0;
}
