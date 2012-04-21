#include <iostream>

using namespace std;

int vp, vd, c, f, t;

int main()
{
    cin >> vp >> vd >> t >> f >> c;
    int cnt = 0;
    if (vp < vd)
    {
        double cur = vp * t;
        while (cur < c)
        {
            double h = (double)cur / (vd - vp);
            cur += vp * h;
            if (c - cur > 0.00001)
            {
                cnt++;
                cur += vp * (h + f);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
