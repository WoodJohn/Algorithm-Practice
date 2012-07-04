#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

bool isPrime(int a)
{
    int i;
    for (i = 2; i <= sqrt(a / 1.0); i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            break;
        int i;
        for (i = 3; i <= n / 2; i += 2)
        {
            if (isPrime(i) && isPrime(n - i))
            {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }
        if (i > n / 2)
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
