#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        float t;
        cin >> t;
        printf("%.2f\n", 16.0 / 3.141592653589 / t / t);
    }
    return 0;
}
