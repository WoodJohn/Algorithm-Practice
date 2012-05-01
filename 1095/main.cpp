#include <iostream>

using namespace std;

int h[20] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};
int s[20];

int numfor(int a)
{
    if (a == 0)
        return 0;
    for (int i = 1; i < 19; i++)
    {
        if (a <= s[i])
        {
            return i;
        }
    }
    return -1;
}

void calc(int a)
{
    int l = 0, r;
    if (a == 0)
        return;
    if (a == 1)
    {
        cout << 'X';
        return;
    }
    int num = numfor(a);
    int t = a - s[num - 1];
    while (1)
    {
        int ll = numfor(l);
        if (t > h[ll] * h[num - 1 - ll])
        {
            t -= h[ll] * h[num - 1 - ll];
            l += h[ll];
        }
        else
        {
            l += (t - 1) / h[num - 1 - ll];
            if (num - 1 == ll)
                r = 0;
            else
            {
                r = t % h[num - 1 - ll];
                if (r == 0)
                    r += h[num - 1 - ll];
                r += s[num - 2 - ll];
            }
            break;
        }
    }

    if (l > 0)
    {
        cout << '(';
        calc(l);
        cout << ')';
    }
    cout << 'X';
    if (r > 0)
    {
        cout << '(';
        calc(r);
        cout << ')';
    }
}

int main()
{
    int i, n;
    s[0] = 0;
    s[1] = 1;
    for (i = 2; i < 19; i++)
    {
        s[i] = s[i - 1] + h[i];
    }
    while (cin >> n)
    {
        if (n == 0)
            break;
        calc(n);
        cout << endl;
    }
}
