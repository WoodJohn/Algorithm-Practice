#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int num = 0;
        int sum = 0;
        int i, k;
        for (k = 1; k <= n; k++)
        {
            num = 0;
            for (i = 1; i <= k; i++)
            {
                if (k % i == 0)
                    num++;
            }
            if (num % 2)
                sum++;
        }
        cout << sum << endl;
    }
    return 0;
}
