#include <iostream>
#include <set>
#include <string.h>
using namespace std;

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
    SquareDigits s;
    for (int i = 0; i < 200; i++)
    cout << i << ' ' << s.smallestResult(i) << endl;
    return 0;
}
