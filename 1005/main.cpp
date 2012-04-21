/*
POJ 1005
Բ��Ϊ��0,0���İ�Բ�������ʱ��������������ʲôʱ�򸲸�ָ������
*/

#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    float pi = acos(-1.0);
    for (int i = 1; i <= n; i ++)
    {
        float a,b;
        scanf("%f %f", &a, &b);
        float r = sqrt(a * a + b * b);
        float s = pi * r * r / 2;
        printf("Property %d: This property will begin eroding in year %d.\n", i, int(s / 50) + 1);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
