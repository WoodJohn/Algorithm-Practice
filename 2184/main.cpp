#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#define OFFSET 100000
using namespace std;

struct cow
{
    int s;
    int f;
}c[105];

bool cmp(cow a, cow b)
{
    return a.s + a.f > b.s + b.f;
}

int dp[2 * OFFSET + 5]; //dp[i]表示其中TS值为i时另一个的最大值，非常巧妙。由于i可能为负值，需要加上一个offset
set<int> v;
int mMax;

void calc(int a)
{
    cow cc = c[a];
    set<int>::iterator i;
    vector<int> tmp;
    bool used[2 * OFFSET + 5] = {false};
    for (i = v.begin(); i != v.end(); i++)
    {
        int t = *i;
        if (!used[t + OFFSET] && dp[t + cc.s + OFFSET] < dp[t + OFFSET] + cc.f)
        {
            used[t + cc.s + OFFSET] = true;
            dp[t + cc.s + OFFSET] = dp[t + OFFSET] + cc.f;
            if (t + cc.s >= 0 && dp[t + cc.s + OFFSET]>= 0 && dp[t + cc.s + OFFSET] + t + cc.s > mMax)
                mMax = dp[t + cc.s + OFFSET] + t + cc.s;
            if (v.find(t + cc.s) == v.end())
                tmp.push_back(t + cc.s);
        }
    }
    int j;
    for (j = 0; j < tmp.size(); j++)
        v.insert(tmp[j]);
    if (cc.f > dp[cc.s + OFFSET])
    {
        dp[cc.s + OFFSET] = cc.f;
        if (cc.s >= 0 && dp[cc.s + OFFSET] >= 0 && dp[cc.s + OFFSET] + cc.s > mMax)
            mMax = dp[cc.s + OFFSET] + cc.s;
        if (v.find(cc.s) == v.end())
            v.insert(cc.s);
    }
}

int main()
{
    int n;
    cin >> n;
    int i;
    for (i = 0; i < 2 * OFFSET + 5; i++)
        dp[i] = -OFFSET;
    v.clear();
    mMax = 0;
    for (i = 0; i < n; i++)
    {
        cin >> c[i].s >> c[i].f;
        calc(i);
    }
//    set<int>::iterator it;
//    ofstream fout;
//    fout.open("out.txt", ios::out);
//    for (it = v.begin(); it != v.end(); it++)
//    {
//        fout << *it << ' ' << dp[*it + OFFSET] << endl;
//    }
    cout << mMax << endl;
    return 0;
}
