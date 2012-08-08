#include <iostream>

using namespace std;

int count(int a)
{
    if (a < 10)
        return a;
    if (a < 100)
    {
        return (a - 9) * 2 + 9;
    }
    if (a < 1000)
    {
        return 189 + (a - 99) * 3;
    }
    if (a < 10000)
    {
        return 2889 + (a - 999) * 4;
    }
    return 38889 + (a - 9999) * 5;
}

int getDigit(int d)
{
    int t = d;
    if (t < 10)
        return t;
    t -= 9;
    if (t <= 180)
    {
        if (t % 2)
            return t / 20 + 1;
        return (t / 2 + 9) % 10;
    }
    t -= 180;
    if (t <= 2700)
    {
        if (t % 3 == 0)
            return (t / 3 + 9) % 10;
        else if (t % 3 == 1)
            return t / 300 + 1;
        else if (t % 3 == 2)
            return (t / 30) % 10;
    }
    t -= 2700;
    if (t <= 36000)
    {
        if (t % 4 == 0)
            return (t / 4 + 9) % 10;
        else if (t % 4 == 1)
            return t / 4000 + 1;
        else if (t % 4 == 2)
            return (t / 400) % 10;
        else if (t % 4 == 3)
            return (t / 40) % 10;
    }
    t -= 36000;
    if (t % 5 == 0)
        return (t / 5) % 10;
    if (t % 5 == 1)
        return t / 50000 + 1;
    if (t % 5 == 2)
        return (t / 5000) % 10;
    if (t % 5 == 3)
        return (t / 500) % 10;
    return (t / 50) % 10;
}

int main()
{
    int t, a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        int n = 1;
        int d = count(n);
        while (a > d)
        {
            a -= d;
            n++;
            d = count(n);
        }
        cout << getDigit(a) << endl;
    }
    return 0;
}
