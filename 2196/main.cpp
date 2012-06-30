#include <iostream>

using namespace std;

int sum(int a, int base)
{
    int ret = 0;
    int t = a;
    while (t)
    {
        ret += t % base;
        t /= base;
    }
    return ret;
}

int main()
{
    int i;
    for (i = 2992; i < 10000; i++)
    {
        if (sum(i, 10) == sum(i, 12) && sum(i, 10) == sum(i, 16))
            cout << i << endl;
    }
    return 0;
}
