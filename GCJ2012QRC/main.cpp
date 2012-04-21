#include <iostream>
#include <fstream>
#include <string.h>
#include <set>
using namespace std;

int digit(int a);

int mov(int a, int b)
{
    int dig = digit(a);
    int ret = a;
    int t = b;
    int ten = 1;
    while (t)
    {
        ten *= 10;
        t--;
    }
    int last = ret % ten;
    ret /= ten;
    ten = 1;
    t = dig - b;
    while (t)
    {
        ten *= 10;
        t--;
    }
    ret += last * ten;
    return ret;
}

int digit(int a)
{
    int t = a;
    int ret = 0;
    while (t)
    {
        ret++;
        t /= 10;
    }
    return ret;
}

int calc(int a, int b)
{
    int sum = 0;
    int i;
    for (i = a; i < b; i++)
    {
        int dig = digit(i);
        int j;
        set<int> s;
        s.clear();
        for (j = 1; j < dig; j++)
        {
            int t = mov(i, j);
            if (t > i && t <= b)
            {
                if (s.find(t) != s.end())
                    continue;
                s.insert(t);
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    ofstream fout;
    fout.open("out.out", ios::out);
    int n;
    cin >> n;
    getchar();
    int i;
    for (i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        fout << "Case #" << i << ": " << calc(a, b) << endl;
    }
    return 0;
}
