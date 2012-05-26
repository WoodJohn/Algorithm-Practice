#include <iostream>
#include <string>
using namespace std;

string add(string a, string b)
{
    int la = a.length();
    int lb = b.length();
    string sa = a;
    string sb = b;
    string ret = "";
    int i;
    int lm = la > lb ? la : lb;
    for (i = 0; i < lm; i++)
    {
        ret += "0";
    }
    if (la < lb)
    {
        for (i = 0; i < lb - la; i++)
            sa = "0" + sa;
    }
    else
    {
        for (i = 0; i < la - lb; i++)
            sb = "0" + sb;
    }
    for (i = lm - 1; i >= 0; i--)
    {
        ret[i] += sa[i] - '0' + sb[i] - '0';
        if (ret[i] > '9' && i > 0)
        {
            ret[i] -= 10;
            ret[i - 1]++;
        }
        else if (i == 0 && ret[i] > '9')
        {
            ret[i] -= 10;
            ret = "1" + ret;
        }
    }
    return ret;
}

int main()
{
    string s;
    string sum = "0";
    while (cin >> s)
    {
        if (s == "0")
        {
            cout << sum << endl;
            break;
        }
        sum = add(sum, s);
    }
    return 0;
}
