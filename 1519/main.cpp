#include <iostream>
#include <string>
using namespace std;

int calc(string s)
{
    int ret = 0;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        ret += s[i] - '0';
    }
    return ret;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "0")
            break;
        int a = calc(s);
        while (a > 9)
        {
            int sum = 0;
            while (a)
            {
                sum += a % 10;
                a /= 10;
            }
            a = sum;
        }
        cout << a << endl;
    }
    return 0;
}
