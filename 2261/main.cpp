#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string name[16];
double p[16][16];
double pt[4][16];

bool near(int a, int b, int base)
{
    int m1 = a % base;
    int m2 = b % base;
    return ((m1 < base / 2 && m2 < base / 2) || (m1 >= base / 2 && m2 >= base / 2));
}

int main()
{
    int i, j;
    for (i = 0; i < 16; i++)
    {
        cin >> name[i];
    }
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
        {
            int a;
            cin >> a;
            p[i][j] = a / 100.0;
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 16; j++)
        {
            if (i == 0)
            {
                if (j % 2)
                    pt[i][j] = p[j][j - 1];
                else
                    pt[i][j] = p[j][j + 1];
            }
            else
            {
                int k = 1 << (i + 1);
                int t = 0;
                while (t <= j)
                    t += k;
                t -= k;
                int c;
                double sum = 0;
                for (c = t; c < t + k; c++)
                {
                    if (near(c, j, k))
                        continue;
                    sum += pt[i - 1][j] * p[j][c] * pt[i - 1][c];
                }
                pt[i][j] = sum;
            }
        }
    }
    for (i = 0; i < 16; i++)
    {
        cout << name[i];
        for (j = 0; j < 11 - name[i].length(); j++)
            cout << ' ';
        printf("p=%.2lf%%\n", pt[3][i] * 100.0);
    }
    return 0;
}
