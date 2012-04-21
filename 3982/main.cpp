#include <iostream>
#include <string>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

string add(string a, string b)
{
    int len = max(a.size(), b.size());
    string result = "";
    for (int i = 0; i < len; i++)
    {
        result += "0";
    }
    if (a.size() < len)
    {
        int la = a.size();
        for (int i = 0; i < len - la; i++)
        {
            a = "0" + a;
        }
    }
    if (b.size() < len)
    {
        int lb = b.size();
        for (int i = 0; i < len - lb; i++)
        {
            b = "0" + b;
        }
    }
    bool toadd = false;
    for (int i = len - 1; i >= 0; i--)
    {
        result[i] += a[i] - '0' + b[i] - '0';
        if (result[i] > '9')
        {
            result[i] -= 10;
            if (i > 0)
                result[i - 1]++;
            else
                toadd = true;
        }
    }
    if (toadd)
        result = "1" + result;
    return result;
}

int main()
{
    string a[100];
    while (cin >> a[0] >> a[1] >> a[2])
    {
        for (int i = 3; i <= 99; i++)
        {
            a[i] = add(add(a[i - 3], a[i - 2]), a[i - 1]);
            //cout << a[i] << endl;
        }
        cout << a[99] << endl;
    }
    return 0;
}
