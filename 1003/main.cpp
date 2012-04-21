/*
POJ 1003
��һ������ֵf����ʹ1/2+1/3+1/4+...+1/n > ��n
*/

#include <iostream>

using namespace std;

int main()
{
    float a;
    while (cin >> a)
    {
        if (a == 0.0)
        {
            break;
        }
        float result = 0.0;
        int i;
        for (i = 2; ; i ++)
        {
            result += 1.0 / i;
            if (result >= a)
            {
                cout << i - 1 << " card(s)" << endl;
                break;
            }
        }
    }
    return 0;
}
