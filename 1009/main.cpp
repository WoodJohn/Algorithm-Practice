#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#define MOD 100003
using namespace std;

inline int key(int a)
{
    return a % MOD;
}

vector <int> ht[MOD];
vector <int> record;
vector <int> result;

bool find(int a)
{
    int k = key(a);
    for (int i = 0; i < ht[k].size(); ++i)
    {
        if (ht[k][i] == a)
            return true;
    }
    return false;
}

void insert(int a)
{
    int k = key(a);
    ht[k].push_back(a);
    record.push_back(a);
}

int width;
int cnt;
int cur;

inline int posToLine(int p)
{
    return p / width;
}

inline int posToCol(int p)
{
    return p % width;
}

inline int coordToPos(int r, int c)
{
    return r * width + c;
}

struct seg
{
    int start;
    int val;
    int len;
}segs[1005];

void calc(int r, int c)
{
    if (r < 0 || c < 0 || c >= width)
        return;
    int p = coordToPos(r, c);
    if (p > segs[cnt - 1].start + segs[cnt - 1].len - 1)
        return;
    if (!find(p))
        insert(p);
}

void handlePoint(int row, int col)
{
    calc(row, col);
    calc(row - 1, col - 1);
    calc(row - 1, col);
    calc(row - 1, col + 1);
    calc(row, col - 1);
    calc(row, col + 1);
    calc(row + 1, col - 1);
    calc(row + 1, col);
    calc(row + 1, col + 1);
}

inline int myabs(int a)
{
    return a > 0 ? a : -a;
}

int getValue(int r, int c)
{
    if (r < 0 || c < 0 || c >= width)
        return -1;
    int p = coordToPos(r, c);
    if (p > segs[cnt - 1].start + segs[cnt - 1].len - 1)
        return -1;
    int l = 0;
    int rr = cnt - 1;
    int m = (l + rr) / 2;
    while (l < rr - 1)
    {
        if (segs[m].start <= p && segs[m].start + segs[m].len - 1 >= p)
            return segs[m].val;
        if (segs[m].start > p)
            rr = m;
        else if (segs[m].start + segs[m].len - 1 < p)
            l = m;
        m = (l + rr) / 2;
    }
    if (segs[l].start <= p && segs[l].start + segs[l].len - 1 >= p)
        return segs[l].val;
    return segs[rr].val;
}

int calcPoint(int p)
{
    int r = posToLine(p);
    int c = posToCol(p);
    int v = getValue(r, c);
    int mMax = 0;
    int v1 = getValue(r - 1, c - 1);
    if (v1 != -1 && myabs(v - v1) > mMax)
        mMax = myabs(v - v1);
    int v2 = getValue(r - 1, c);
    if (v2 != -1 && myabs(v - v2) > mMax)
        mMax = myabs(v - v2);
    int v3 = getValue(r - 1, c + 1);
    if (v3 != -1 && myabs(v - v3) > mMax)
        mMax = myabs(v - v3);
    int v4 = getValue(r, c - 1);
    if (v4 != -1 && myabs(v - v4) > mMax)
        mMax = myabs(v - v4);
    int v5 = getValue(r, c + 1);
    if (v5 != -1 && myabs(v - v5) > mMax)
        mMax = myabs(v - v5);
    int v6 = getValue(r + 1, c - 1);
    if (v6 != -1 && myabs(v - v6) > mMax)
        mMax = myabs(v - v6);
    int v7 = getValue(r + 1, c);
    if (v7 != -1 && myabs(v - v7) > mMax)
        mMax = myabs(v - v7);
    int v8 = getValue(r + 1, c + 1);
    if (v8 != -1 && myabs(v - v8) > mMax)
        mMax = myabs(v - v8);
    return mMax;
}

void solve()
{
    printf("%d\n", width);
    sort(record.begin(), record.end(), less<int>());
    result.clear();
    for (int i = 0; i < record.size(); ++i)
    {
        result.push_back(calcPoint(record[i]));
    }
    int pos = 0;
    while (pos < result.size())
    {
        int ccnt = 0;
        while (pos < result.size() - 1 && result[pos] == result[pos + 1])
        {
            ccnt += record[pos + 1] - record[pos];
            ++pos;
        }
        if (pos < result.size() - 1)
            ccnt += record[pos + 1] - record[pos];
        else
            ccnt += segs[cnt - 1].start + segs[cnt - 1].len - record[pos];
        printf("%d %d\n", result[pos], ccnt);
        ++pos;
    }
    printf("0 0\n");
}

int main()
{
    while (scanf("%d", &width))
    {
        if (width == 0)
            break;
        for (int i = 0; i < MOD; ++i)
            ht[i].clear();
        record.clear();
        cnt = 0;
        cur = 0;
        int a, b;
        while (scanf("%d%d", &a, &b) != EOF)
        {
            if (a == 0 && b == 0)
                break;
            segs[cnt].start = cur;
            cur += b;
            segs[cnt].val = a;
            segs[cnt++].len = b;
        }
        for (int i = 0; i < cnt; ++i)
        {
            int row = posToLine(segs[i].start);
            int col = posToCol(segs[i].start);
            int r = row;
            handlePoint(row, col);
            row = posToLine(segs[i].start + segs[i].len - 1);
            col = posToCol(segs[i].start + segs[i].len - 1);
            handlePoint(row, col);

            handlePoint(r, 0);
            handlePoint(r, width - 1);
            handlePoint(r + 1, 0);

            handlePoint(row, 0);
            handlePoint(row, width - 1);
            handlePoint(row - 1, width - 1);
        }
        solve();
    }
    printf("0\n");
    return 0;
}
