#include <iostream>
#include <stdio.h>

using namespace std;

double result[100000];

int main()
{
    result[0] = 0.5;
    for (int i = 1; i < 100000; i ++)
    {
        result[i] = result[i - 1] + 1.0 / (double)((i + 1) * 2);
    }
    int n;
    cout << "Cards  Overhang" << endl;
    while (cin >> n)
    {
        printf("%5d%10.3f\n", n, result[n - 1]);
    }
    return 0;
}
