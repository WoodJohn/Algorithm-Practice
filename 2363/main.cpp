#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            cout << "0" << endl;
            continue;
        }
        int sum = 0;
        int mMin = 999999999;
        int triroot = ceil(pow(n, 1.0 / 3));
        for (int i = triroot; i > 0; i--)
        {
            if (n % i == 0)
            {
                int j = n / i;
                for (int k = sqrt(j / 1.0); k > 0; k--)
                {
                    if (j % k == 0)
                    {
                        int t = j / k;
                        sum = 2 * (i * k + i * t + t * k);
                        if (sum < mMin)
                            mMin = sum;
                    }
                }
            }
        }
        cout << mMin << endl;
    }
    return 0;
}
