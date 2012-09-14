#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        int num[1005];
        for (int j = 0; j < n; j++)
        {
            cin >> num[j];
        }
        int cnt = 0;
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (num[j] > num[k])
                    cnt++;
            }
        }
        printf("Scenario #%d:\n", i);
        cout << cnt << endl << endl;
    }
    return 0;
}
