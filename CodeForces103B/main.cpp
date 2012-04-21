#include <iostream>
#include <math.h>
using namespace std;

struct point
{
    int x;
    int y;
    int r;
}h[1001];

int n;
int lbx;
int lby;
int rtx;
int rty;
int res;


void init()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    lbx = a < c ? a : c;
    rtx = a + c - lbx;
    lby = b < d ? b : d;
    rty = b + d - lby;
    cin >> n;
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> h[i].x >> h[i].y >> h[i].r;
    }
    res = (rtx - lbx + 1) * 2 + (rty - lby - 1) * 2;
}

double dis(int x1, int x2, int y1, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void calc()
{
    int i, j, k;
    for (i = lbx; i <= rtx; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (dis(i, h[k].x, lby, h[k].y) <= h[k].r)
            {
                res--;
                break;
            }
        }

        for (k = 0; k < n; k++)
        {
            if (dis(i, h[k].x, rty, h[k].y) <= h[k].r)
            {
                res--;
                break;
            }
        }
    }
    for (i = lby + 1; i < rty; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (dis(lbx, h[k].x, i, h[k].y) <= h[k].r)
            {
                res--;
                break;
            }
        }
        for (k = 0; k < n; k++)
        {
            if (dis(rtx, h[k].x, i, h[k].y) <= h[k].r)
            {
                res--;
                break;
            }
        }
    }
}

int main()
{
    init();
    calc();
    cout << res << endl;
    return 0;
}
