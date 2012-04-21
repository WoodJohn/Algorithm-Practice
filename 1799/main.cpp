#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++)
    {
        float pi = acos(-1.0);
        float R;
        int n;
        scanf("%f %d", &R, &n);
        printf("Scenario #%d:\n", i);
        if (n == 2)
        {
            printf("%.3f\n\n", R / 2.0);
        }
        else
        {
            float sins = sin(pi / float(n));
            printf("%.3f\n\n", R * sins / (1 + sins));
        }
    }
    return 0;
}
