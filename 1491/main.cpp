#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    int m = a > b ? a : b;
    int n = a + b - m;
    if (n == 1)
        return 1;
    int tmp;
    while (1)
    {
        if (m % n == 0)
            return n;
        m = m % n;
        tmp = n;
        n = m;
        m = tmp;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int num[55];
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        int j;
        int cnt = 0;
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (gcd(num[i], num[j]) == 1)
                    cnt++;
            }
        }
        if (cnt == 0)
            cout << "No estimate for this data set." << endl;
        else
            printf("%.6f\n", sqrt(6 * n * (n - 1) / 2.0 / cnt));
    }
    return 0;
}

