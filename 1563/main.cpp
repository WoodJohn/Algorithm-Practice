#include <iostream>

using namespace std;

int main()
{
    int h, u, d, f;
    while (cin >> h >> u >> d >> f)
    {
        if (h == u && h == d && h == f && h == 0)
            break;
        int day;
        double cur = 0.0;
        double s = (double)u;
        double ff = s * f / 100.0;
        for (day = 1; ; day++)
        {
            cur += s;
            if (cur > h)
            {
                cout << "success on day " << day << endl;
                break;
            }
            if (s > 0)
                s -= ff;
            if (s <= 0)
                s = 0;
            cur -= d;
            if (cur < 0)
            {
                cout << "failure on day " << day << endl;
                break;
            }
        }
    }
    return 0;
}
