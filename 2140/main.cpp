#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n <<= 1;
    int k;
    int sum = 0;
    int m = int(sqrt(n));
    for (k = 0; k < m; k++)
    {
        if (n % (k + 1) == 0 && (n / (k + 1) - k) > 0 && (n / (k + 1) - k) % 2 == 0)
            sum++;
    }
    cout << sum << endl;
    return 0;
}
