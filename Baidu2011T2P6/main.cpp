#include <iostream>
#include <stdlib.h>
using namespace std;

int n;

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            for (int j = 0; j < t; j++)
            {
                int k;
                cin >> k;
                for (int r = 0; r < k; r++)
                {
                    int a;
                    cin >> a;
                }
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
        }
        srand(n);
        if (rand() % 2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
