#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a, b, c;
    int t, i;
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        printf("Case %d: ", i);
        cin >> a >> b >> c;
        if (a <= 20 && b <= 20 && c <= 20)
            cout << "good" << endl;
        else
            cout << "bad" << endl;
    }
    return 0;
}
