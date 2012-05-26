#include <iostream>
#include <stdio.h>
using namespace std;

int nn(int a)
{
    if (a == 0)
        return 1;
    return a * nn(a - 1);
}

double calc(int a)
{
    int i;
    double ret = 0.0;
    for (i = 0; i <= a; i++)
    {
        ret += 1.0 / nn(i);
    }
    return ret;
}

int main()
{
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d %.9f\n", i, calc(i));
    }
    return 0;
}
