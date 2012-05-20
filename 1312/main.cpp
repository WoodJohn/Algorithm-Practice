#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int ret[1001];

int c2n(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
//    else if (c > 'A' && c <= 'z')
//        return c - 'a' + 36;
    return -1;
}

void change(int b1, int b2, int *s)
{
    int ss[1001];
    memcpy(ss, s, 1001);
    ret[0] = 0;
    while (ss[0] > 0)
    {
        int pos = 1;
        int cur = 0;
        int res[1001];
        res[0] = 0;
        while (pos <= ss[0])
        {
            cur = cur * b1 + ss[pos];
            res[res[0] + 1] = cur / b2;
            res[0]++;
            cur %= b2;
            pos++;
        }
        ret[ret[0] + 1] = cur;
        ret[0]++;
        int cnt = 0;
        ss[0] = cnt;
        int k = 1;
        while (res[k] == 0 && k <= res[0])
            k++;
        for (int i = k; i <= res[0]; i++)
        {
            ss[cnt + 1] = res[i];
            cnt++;
        }
        ss[0] = cnt;
    }
}

void out(int *num, int b)
{
    if (b == 10)
    {
        for (int i = num[0]; i >= 1; i--)
        {
            cout << num[i];
            if (i > 1 && i % 3 == 1)
                cout << ',';
        }
        cout << endl;
    }
    else
    {
        for (int i = num[0]; i >= 1; i--)
        {
            cout << char(num[i] + 'a' - 1);
        }
    }
}

int main()
{
    string a;
    while (cin >> a)
    {
        if (a == "*")
            break;
        char c = a[0];
        int num[1001];
        num[0] = a.length();
        for (int i = 1; i <= num[0]; i++)
        {
            num[i] = c2n(a[i - 1]);
        }
        if (c >= '0' && c <= '9')
        {
            change(10, 26, num);
            out(ret, 26);
            for (int i = 0; i < 22 - ret[0]; i++)
            {
                cout << ' ';
            }
            for (int i = 0; i < a.length(); i++)
            {
                cout << a[i];
                if (i < a.length() - 1 && (a.length() - i) % 3 == 1)
                    cout << ',';
            }
            cout << endl;
        }
        else
        {
            cout << a;
            for (int i = 0; i < 22 - a.length(); i++)
            {
                cout << ' ';
            }
            change(26, 10, num);
            out(ret, 10);
        }
    }
    return 0;
}
