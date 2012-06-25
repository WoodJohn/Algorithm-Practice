#include <iostream>
#include <stdio.h>
using namespace std;

long long det(long long a11, long long a12, long long a13, long long a21, long long a22, long long a23, long long a31, long long a32, long long a33)
{
    return a11 * (a22 * a33 - a23 * a32) - a12 * (a21 * a33 - a23 * a31) + a13 * (a21 * a32 - a22 * a31);
}

double test(double a)
{
    if (a > -0.0005 && a < 0.0005)
        return 0;
    return a;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a11, a12, a13, a21, a22, a23, a31, a32, a33, b1, b2, b3;
        cin >> a11 >> a12 >> a13 >> b1 >> a21 >> a22 >> a23 >> b2 >> a31 >> a32 >> a33 >> b3;
        long long d = det(a11, a12, a13, a21, a22, a23, a31, a32, a33);
        long long d1 = det(b1, a12, a13, b2, a22, a23, b3, a32, a33);
        long long d2 = det(a11, b1, a13, a21, b2, a23, a31, b3, a33);
        long long d3 = det(a11, a12, b1, a21, a22, b2, a31, a32, b3);
        printf("%I64d %I64d %I64d %I64d\n", d1, d2, d3, d);
        if (d == 0)
            printf("No unique solution\n");
        else
        {
            double r1 = test(double(d1) / d);
            double r2 = test(double(d2) / d);
            double r3 = test(double(d3) / d);

            printf("Unique solution: %.3lf %.3lf %.3lf\n",  r1, r2, r3);
        }
        printf("\n");
    }
    return 0;
}
