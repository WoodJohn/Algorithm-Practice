#include <iostream>

using namespace std;

struct rect
{
    int x1;
    int y1;
    int x2;
    int y2;
};

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

rect calc(rect r1, rect r2)
{
    rect ret;
    ret.x1 = ret.x2 = ret.y1 = ret.y2 = 0;
    if (r1.x1 > r1.x2)
        swap(r1.x1, r1.x2)
    if (r1.y1 > r1.y2)
        swap(r1.y1, r1.y2);
    if (r2.x1 > r2.x2)
        swap(r2.x1, r2.x2);
    if (r2.y1 > r2.y2)
        swap(r2.y1, r2.y2);
    if (r1.x2 > r2.x1 && r1.x1 < r2.x2)
    {
        ret.x1 = r1.x1 < r2.x1 ? r2.x1 : r1.x1;
        ret.x2 = r1.x2 < r2.x2 ? r1.x2 : r2.r2;
        if (r1.y2 > r2.y1 && r1.y1 < r2.y2)
        {
            ret.y1 = r1.y1 < r2.y1 ? r2.y1 : r1.y1;
            ret.y2 = r1.y2 < r2.y2 ? r1.y2 : r2.y2;
        }
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        while (n--)
        {
            rect cur;
            cur.x1 = cur.x2 = cur.y1 = cur.y2 = 0;
            rect res;
            int x1, y1, x2, y2;
            while (cin >> x1 >> y1 >> x2 >> y2)
            {
                rect r;
                r.x1 = x1;
                r.x2 = x2;
                r.y1 = y1;
                r.y2 = y2;
                res = calc(cur, r);
            }
            int w = res.x2 - res.x1 > 0 ? res.x2 - res.x1 : res.x1 - res.x2;
            int h = res.y2 - res.y1 > 0 ? res.y2 - res.y1 : res.y1 - res.y2;
            cout << w * h << endl;
        }
    }
    return 0;
}
