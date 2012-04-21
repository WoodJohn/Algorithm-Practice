#include <iostream>
#include <stdio.h>
using namespace std;

double calc(int n1, int n2, int n3, int n4)
{

}

int main()
{
    int t, i;
    int n1, n2, n3, n4;
    double pos;
    for (i = 1; i <= t; i++)
    {
        cin >> n1 >> n2 >> n3 >> n4;
        if (n1 + n2 + n3 + n4 > 54)
            pos = -1.0;
        else if (n1 + n2 + n3 + m4 == 0)
            pos = 0.0;
        else
        {
            int e1 = n1 > 13 ? n1 - 13 : 0;
            int e2 = n2 > 13 ? n2 - 13 : 0;
            int e3 = n3 > 13 ? n3 - 13 : 0;
            int e4 = n4 > 13 ? n4 - 13 : 0;
            if (e1 + e2 + e3 + e4 > 2)
                pos = -1.0;
            else
            {
                pos = calc(n1, n2, n3, n4);
            }
        }
        printf("Case %d: %.3f\n", i, pos);
    }
    return 0;
}
