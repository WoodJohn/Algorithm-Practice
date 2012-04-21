/*
POJ 1004
求平均值
*/

#include <stdio.h>

int main()
{
    float a;
    float result = 0;
    for (int i = 0 ; i < 12 ; i ++)
    {
        scanf("%f", &a);
        result += a;
    }
    result /= 12;
    printf("$%.2f\n", result);
    return 0;
}
