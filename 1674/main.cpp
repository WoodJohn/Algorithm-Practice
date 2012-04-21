#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        int num[10001] = {};
        int n;
        int circles = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            cin >> num[i];
        }
        for (int i = 1; i <= n; i ++)
        {
            if (num[i] == 0)
            {
                continue;
            }
            circles ++;
            int tt = num[i];
            num[i] = 0;
            while (num[tt] != 0)
            {
                int temp = num[tt];
                num[tt] = 0;
                tt = temp;
            }
        }
        cout << n - circles << endl;
    }
    return 0;
}
