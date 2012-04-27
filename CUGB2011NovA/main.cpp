#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        double a, b;
        a = b = 0.0;
        while (n--)
        {
            int c, d;
            cin >> c >> d;
            a += 200.0 / c;
            b += 200.0 / d;
        }
        if (a > b)
            cout << "B" << endl;
        else
            cout << "A" << endl;
    }
    return 0;
}
