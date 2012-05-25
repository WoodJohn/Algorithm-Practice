#include <iostream>

using namespace std;

int calc(int a, int base)
{
    int b = 1;
    int t = a;
    int sum = 0;
    while (t)
    {
        sum += (t % 10) * b;
        b *= base;
        t /= 10;
    }
    return sum;
}

bool check(int a, int base)
{
    int t = a;
    while (t)
    {
        if (t % 10 >= base)
            return false;
        t /= 10;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p, q, r;
        cin >> p >> q >> r;
        int b;
        for (b = 2; b < 17; b++)
        {
            if (check(p, b) && check(q, b) && check(r, b) && calc(p, b) * calc(q, b) == calc(r, b))
            {
                cout << b << endl;
                break;
            }
        }
        if (b == 17)
            cout << 0 << endl;
    }
    return 0;
}
