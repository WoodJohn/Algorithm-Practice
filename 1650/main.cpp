#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double p;
    int l;
    cin >> p >> l;
    int i;
    double mMin = 99999.0;
    int r1 = 1, r2 = 1;
    for (i = 1; i <= l; i++)
    {
        double q = p * i;
        int t;
        if (q - (int)(q) >= 0.5)
            t = (int)(q + 0.5);
        else
            t = (int)q;
        if (t < 1)
            t = 1;
        if (t > l)
            t = l;
        q = t / double(i);
        if (abs(q - p) < mMin)
        {
            mMin = abs(q - p);
            r1 = t;
            r2 = i;
        }
    }
    cout << r1 << ' ' << r2 << endl;
    return 0;
}
