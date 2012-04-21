#include <stdio.h>
#include <math.h>

using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 3; i <= n; i ++)
    {
        int a = (int)pow(i * i * i / 3, 1.0/3);
        for (int j = 2; j <= a; j ++)
            for (int k = j; k < n; k ++)
                for (int l = k; l < n; l ++)
                {
                    if (i * i * i == j * j * j + k * k * k + l * l * l)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
                }
    }
    return 0;
}
