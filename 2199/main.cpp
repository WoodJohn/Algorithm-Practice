#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

struct node
{
    int m;
    double r;
}data[13];

int last, n;
double total;

double check(double a)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += data[i].r * pow(a, last - data[i].m + 1);
    }
    return sum;
}

double calc()
{
    double r = 1.0;
    double l = 0.0;
    double mid;
    while (r > l)
    {
        mid = (r + l) / 2;
        double t = check(1 + mid);
        if (abs(t - total) < 1e-9)
            return mid;
        else if (t > total)
            r = mid;
        else
            l = mid;
    }
    return 0;
}

int main()
{
    int cnt = 1;
    while (cin >> n)
    {
        if (n == -1)
            break;
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> data[i].m >> data[i].r;
        }
        cin >> last >> total;
        printf("Case %d: %.5lf\n\n", cnt++, calc());
    }
    return 0;
}
