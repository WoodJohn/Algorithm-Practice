#include <iostream>

using namespace std;

int rev(int n)
{
    int t = n;
    int res = 0;
    while (t > 0)
    {
        res = res * 10 + t % 10;
        t /= 10;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        int a,b;
        cin >> a >> b;
        cout << rev(rev(a) + rev(b)) << endl;
    }
    return 0;
}
