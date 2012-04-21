#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

using namespace std;

int cmp(const void *a, const void *b)
{
    int p = *((int *)a);
    int q = *((int *)b);
    return p - q;
}

int data[901];
int cube;

int main()
{
    int m,n;
    int count = 0;
    while (cin >> m >> n)
    {
        if (m == 0 && n == 0)
        {
            break;
        }
        count ++;
        for (int i = 0; i < m; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                cin >> data[i * n + j];
            }
        }
        cin >> cube;
        qsort(data, m * n, sizeof(int), cmp);
        double curH = double(data[0]);
        int curIndex = 0;
        if (cube == 0)
        {
            curIndex = -1;
            curH = 0.0;
        }
        else
        {
            while (cube > 0)
            {
                if (curIndex < m * n - 1 && cube / double(curIndex + 1) / 100.0 > double(data[curIndex + 1] - data[curIndex]))
                {
                    curH = double(data[curIndex + 1]);
                    cube -= (data[curIndex + 1] - data[curIndex]) * 100 * (curIndex + 1);
                    curIndex ++;
                }
                else
                {
                    curH += cube / double(curIndex + 1) / 100.0;
                    break;
                }
            }
        }
        printf("Region %d\n", count);
        printf("Water level is %.2lf meters.\n", curH);
        printf("%.2lf percent of the region is under water.\n\n", (curIndex + 1) * 100 / double(m * n));
    }
    return 0;
}
