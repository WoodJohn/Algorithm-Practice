#include <iostream>

int result[10001];

using namespace std;

int len(int n)
{
    int t = n;
    int count = 1;
    while (t != 1)
    {
        if (t % 2)
        {
            t = t * 3 + 1;
        }
        else
        {
            t /= 2;
        }
        count ++;
    }
    return count;
}

int main()
{
    int a,b;
    for (int i = 1; i < 10000; i ++)
    {
        result[i] = len(i);
    }
    while (cin >> a >> b)
    {
        int c,d;
        if (a > b)
        {
            c = b;
            d = a;
        }
        else
        {
            c = a;
            d = b;
        }
        int max = c;
        for (int i = c + 1; i <= d; i ++)
        {
            if (result[i] > result[max])
            {
                max = i;
            }
        }
        cout << a << " " << b << " " << result[max] << endl;
    }
}
