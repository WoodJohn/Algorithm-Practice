#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        int a,b;
        cin >> a >> b;
        if (a < b || ((a - b) % 2 != 0))
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << (a + b) / 2 << ' ' << (a - b) / 2 << endl;
        }
    }
    return 0;
}
