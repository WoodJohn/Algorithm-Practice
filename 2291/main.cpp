#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int num[1005];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> num[i];
        sort(num, num + n, less<int>());
        int mMax = 0;
        for (int i = 0; i < n; i++)
        {
            int t = num[i] * (n - i);
            if (t > mMax)
                mMax = t;
        }
        cout << mMax << endl;
    }
    return 0;
}
