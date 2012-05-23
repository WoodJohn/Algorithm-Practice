#include <iostream>
#include <string>
#include <set>
using namespace std;

class HowEasy
{
public:
    int pointVal(string s)
    {
        int pos = 0;
        int len = s.length();
        string tmp;
        int nw = 0;
        int lw = 0;
        while (pos < len)
        {
            int tpos = pos;
            while (tpos < len && s[tpos] != ' ')
                tpos++;
            tmp = s.substr(pos, tpos - pos);
            bool check = false;
            int i;
            for (i = 0; i < tmp.length(); i++)
            {
                if (i == tmp.length() - 1 && tmp[i] == '.')
                {
                    check = true;
                    continue;
                }
                if (!(tmp[i] <= 'Z' && tmp[i] >= 'A' || tmp[i] <= 'z' && tmp[i] >= 'a'))
                    break;
            }
            if (i == tmp.length() && i != 0)
            {
                nw++;
                if (check)
                {
                    lw += tmp.length() - 1;
                    if (i == 1)
                        nw--;
                }
                else
                    lw += tmp.length();
            }
            pos = tpos + 1;
        }
        int p;
        if (nw == 0)
            p = 0;
        else
            p = lw / nw;
        if (p <= 3)
            return 250;
        if (p >= 6)
            return 1000;
        return 500;
    }
};

class SquareDigits
{
public:
    SquareDigits()
    {
        for (int i = 0; i < 20001; i++)
            g[i].clear();
    }
    int smallestResult(int a)
    {
        int t = 0;
        while (1)
        {
            set<int> tt = se(t);
            if (tt.find(a) != tt.end())
                return t;
            t++;
        }
    }
private:
    int s(int x)
    {
        int a = x;
        int ret = 0;
        while (a)
        {
            int b = a % 10;
            ret += b * b;
            a /= 10;
        }
        return ret;
    }
    set<int> se(int a)
    {
        if (!g[a].empty())
            return g[a];
        set<int> ret;
        int tmp = s(a);
        while (ret.find(tmp) == ret.end())
        {
            ret.insert(tmp);
            tmp = s(tmp);
        }
        g[a] = ret;
        return ret;
    }
    set<int> g[20001];
};

int main()
{
    HowEasy hw;
    cout << hw.pointVal(" . . . . . . . . . . . abcdefg") << endl;
    SquareDigits s;
    for (int i = 0; i < 200; i++)
    cout << i << ' ' << s.smallestResult(i) << endl;
    return 0;
}
