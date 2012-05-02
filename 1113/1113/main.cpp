//
//  main.cpp
//  1113
//
//  Created by Wang Ruichao on 12-5-2.
//  Copyright (c) 2012年 Netease Youdao. All rights reserved.
//

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
    double angle1 = atan((double)(p.y - lb.y) / (double)(p.x - lb.x));
    double angle2 = atan((double)(q.y - lb.y) / (double)(q.x - lb.x));
    if (angle1 > angle2)
        return 1;
    if (angle1 == angle2)
    {
        double d1 = dis(p, lb);
        double d2 = dis(q, lb);
        if (d1 > d2)
            return 1;
        return -1;
    }
    return -1;
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
    qsort(points + 1, n - 1, sizeof(point), cmp);
    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);
    if (!leftTurn(points[0], points[1], points[2]))
    {
        st.pop();
        st.pop();
        st.push(points[2]);
    }
    int cur = 3;
    while (cur < n)
    {
        point c = points[cur++];
        point top = st.top();
        point sec = getSecond();
        while (!leftTurn(sec, top, c))
        {
            st.pop();
            top = st.top();
            sec = getSecond();
        }
        st.push(c);
    }
    int nodes = st.size();
    double length = 0.0;
    length += (nodes - 2) * PI * l;
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

