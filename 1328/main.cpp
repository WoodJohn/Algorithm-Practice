#include <iostream>
<<<<<<< HEAD

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
=======
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

struct point
{
    int x;
    int y;
    double lx;
}p[1005];

double dis(point a, point b)
{
    return sqrt((a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x));
}

bool cmp(point a, point b)
{
    return a.lx < b.lx;
}

int n, d;
bool done[1005];
int cur;
int total;

void calc()
{
    for (int i = 0; i < n; i++)
    {
        if (done[i])
            continue;
        total++;
        done[i] = true;
        cur++;
        for (int j = i + 1; j < n; j++)
        {
            if (dis(p[i], p[j]) > d * 2)
                break;
            if (sqrt((p[i].lx - p[j].x) * (p[i].lx - p[j].x) + p[j].y * p[j].y) <= d)
            {
                done[j] = true;
                cur++;
            }
        }
    }
}

int main()
{
    int cs = 0;
    while (cin >> n >> d)
    {
        if (n == 0 && d == 0)
            break;
        cur = 0;
        total = 0;
        memset(done, false, sizeof(done));
        cs++;
        bool ava = true;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
            p[i].lx = p[i].x + sqrt(d * d - p[i].y * p[i].y);
            if (p[i].y > d)
                ava = false;
        }
        if (!ava)
        {
            printf("Case %d: -1\n", cs);
        }
        else
        {
            sort(p, p + n, cmp);
            while (cur < n)
            {
                calc();
            }
            printf("Case %d: %d\n", cs, total);
        }
    }
>>>>>>> a3c4ff7ea09b6dac587189519e02faadc68a6f66
    return 0;
}
