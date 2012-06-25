#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159265359;

inline double max(double a, double b)
{
    return a > b ? a : b;
}

double calcsin(double a, bool xg)
{
    double r = asin(a);
    if (r >= 0)
    {
        if (xg)
            return r;
        else
            return PI - r;
    }
    else
    {
        if (xg)
            return 2 * PI + r;
        else
            return PI - r;
    }
}

double calc(int x1, int y1, int x2, int y2)
{
    double r1 = calcsin(double(y1) / sqrt(x1 * x1 + y1 * y1), x1 > 0);
    double r2 = calcsin(double(y2) / sqrt(x2 * x2 + y2 * y2), x2 > 0);
    double r = r1 - r2;
    if (r < 0)
        r = -r;
    if (r > PI)
        r = 2 * PI - r;
    return r;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, x1, y1, x2, y2, x3, y3;
        cin >> r >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if ((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0) || (x3 == 0 && y3 == 0))
        {
            cout << "No" << endl;
            continue;
        }
        double r1 = calc(x1, y1, x2, y2);
        double r2 = calc(x1, y1, x3, y3);
        double r3 = calc(x2, y2, x3, y3);
        double maxR = max(max(r1, r2), r3);
        if (maxR - 2.0 * PI / 3.0 > 1e-7)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
