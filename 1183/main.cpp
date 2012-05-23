#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    long long a;
    cin >> a;
    for (m = a; m >= 1; m--)
    {
        if ((a * a + 1) % m == 0)
        {
            n = (a * a + 1) / m;
            break;
        }
    }
    cout << a + a + m + n << endl;
    return 0;
}
