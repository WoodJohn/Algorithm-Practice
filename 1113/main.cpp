#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#define PI 3.141592653589
using namespace std;

struct point
{
    int x, y;
    point()
    {
    }
    point(int a, int b)
    {
        x = a;
        y = b;
    }
}points[1005];

point lb;
stack<point> st;

point getSecond()
{
    point tmp = st.top();
    st.pop();
    point ret = st.top();
    st.push(tmp);
    return ret;
}

double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int cmp(const void *a, const void *b)
{
    point p = *((point *)a);
    point q = *((point *)b);
    if (p.x == lb.x && p.y == lb.y)
        return 1;
    if (q.x == lb.x && q.y == lb.y)
        return -1;
    if (p.x == lb.x)
    {
        if (q.x == lb.x)
            return dis(p, lb) > dis(q, lb) ? 1 : -1;
        double angle = atan((double)(q.y - lb.y) / (double)(q.x - lb.x));
        if (angle >= 0)
            return 1;
        return -1;
    }
    if (q.x == lb.x)
    {
        double angle = atan((double)(p.y - lb.y) / (double)(p.x - lb.x));
        if (angle >= 0)
            return -1;
        return 1;
    }
    double angle1 = atan((double)(p.y - lb.y) / (double)(p.x - lb.x));
    double angle2 = atan((double)(q.y - lb.y) / (double)(q.x - lb.x));
    if (angle1 == angle2)
    {
        double d1 = dis(p, lb);
        double d2 = dis(q, lb);
        if (d1 > d2)
            return 1;
        return -1;
    }
    if (angle1 * angle2 > 0)
    {
        return angle1 > angle2 ? 1 : -1;
    }
    if (angle1 * angle2 == 0)
        return angle1 != 0.0 ? 1 : -1;
    return angle1 < 0 ? 1 : -1;
}

bool leftTurn(point p0, point p1, point p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y) > 0;
}

int main(int argc, const char * argv[])
{
    int n, l;
    cin >> n >> l;
    int i;
    int pos = -1;
    lb = point(99999, 99999);
    for (i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
        if (points[i].y <= lb.y)
        {
            if (points[i].y < lb.y || points[i].x < lb.x)
            {
                lb = points[i];
                pos = i;
            }
        }
    }
    point tt = points[0];
    points[0] = lb;
    points[pos] = tt;
    qsort(points, n, sizeof(point), cmp);
    st.push(lb);
    st.push(points[0]);
    st.push(points[1]);
    int cur = 2;
    while (cur < n - 1)
    {
        point c = points[cur++];
        point top = st.top();
        point sec = getSecond();
        while (!leftTurn(sec, top, c))
        {
            st.pop();
            if (st.size() == 1)
                break;
            top = st.top();
            sec = getSecond();
        }
        st.push(c);
    }
    double length = 0.0;
    length += 2 * PI * l;
    point start = st.top();
    point cc = st.top();
    st.pop();
    while (!st.empty())
    {
        point tmp = st.top();
        length += dis(cc, tmp);
        cc = tmp;
        st.pop();
    }
    length += dis(start, cc);
    cout << (int)(length + 0.5) << endl;
    return 0;
}

