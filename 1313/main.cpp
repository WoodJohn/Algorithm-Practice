#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int p = (n - 1) / 4 + 1;
        int i;
        cout << "Printing order for " << n << " pages:" << endl;
        bool check;
        if (n == 1)
        {
            cout << "Sheet 1, front: Blank, 1" << endl;
            continue;
        }
        for (i = 1; i <= p; i++)
        {
            cout << "Sheet " << i << ", front: ";
            check = 4 * p - 2 * (i - 1) > n;
            if (check)
                cout << "Blank";
            else
                cout << 4 * p - 2 * (i - 1);
            cout << ", ";
            cout << 2 * (i - 1) + 1 << endl;
            cout << "Sheet " << i << ", back : ";
            cout << 2 * (i - 1) + 2;
            cout << ", ";
            check = 4 * p - 2 * (i - 1) - 1 > n;
            if (check)
                cout << "Blank" << endl;
            else
                cout << 4 * p - 2 * (i - 1) - 1 << endl;
        }
    }
    return 0;
}
