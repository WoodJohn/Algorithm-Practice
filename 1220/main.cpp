#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int ret[1001];

int c2n(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 36;
    return -1;
}

char n2c(int n)
{
    if (n < 10)
        return '0' + n;
    if (n < 36)
        return n - 10 + 'A';
    if (n < 62)
        return n - 36 + 'a';
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

void out(int *num)
{
    for (int i = num[0]; i >= 1; i--)
    {
        cout << n2c(num[i]);
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int num[1001];
        num[0] = s.length();
        for (int i = 1; i <= num[0]; i++)
        {
            num[i] = c2n(s[i - 1]);
        }
        cout << a << ' ' << s << endl;
        change(a, b, num);
        cout << b << ' ';
        out(ret);
        cout << endl;
    }
    return 0;
}
