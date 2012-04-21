#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    cout << "Gnomes:" << endl;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b && b > c || a < b && b < c)
        {
            cout << "Ordered" << endl;
        }
        else
        {
            cout << "Unordered" << endl;
        }
    }
    return 0;
}
