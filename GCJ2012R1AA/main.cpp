#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int a, b;
double p[100005];
double dMin;

int main()
{
    ifstream fin;
    fin.open("A-large.in", ios::in);
    int t, k = 1;
    fin >> t;
    FILE *out = fopen("out.out", "w");
    while (t--)
    {
        fin >> a >> b;
        dMin = b + 2;
        double pp = 1;
        p[0] = 1;
        int i;
        for (i = 1; i <= a; i++)
        {
            fin >> p[i];
        }
        for (i = a; i >= 0; i--)
        {
            pp *= p[a - i];
            double t = (b - a + 2 * i + 1) * pp + (b - a + 2 * i + b + 2) * (1 - pp);
            if (t < dMin)
                dMin = t;
        }
        fprintf(out, "Case #%d: %.6f\n", k, dMin);
        k++;
    }
    return 0;
}
