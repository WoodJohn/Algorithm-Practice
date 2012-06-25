#include <iostream>

using namespace std;

int main()
{
    int n;
    int x, y;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        if (x - y == 2)
        {
            cout << (y % 2 == 0 ? (y + 1) * 2 : (y + 1) * 2 - 1) << endl;
        }
        else if (x == y)
        {
            cout << (y % 2 == 0 ? y * 2 : y * 2 - 1) << endl;
        }
        else
            cout << "No Number" << endl;
    }
    return 0;
}
