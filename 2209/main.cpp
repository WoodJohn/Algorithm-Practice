#include <iostream>

using namespace std;

int intpow(int a, int b)
{
    int ret = a;
    for (int i = 1; i < b; i++)
        ret *= a;
    return ret;
}

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    int i;
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int t = intpow(a, m);
        if (t > 0)
            sum += t;
    }
    cout << sum << endl;
    return 0;
}
