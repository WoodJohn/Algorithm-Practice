#include <iostream>
#include <string>

using namespace std;

int myabs(int n)
{
    return n > 0 ? n : -n;
}

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
        string p1, p2;
        int r1, r2, r3;
        string s;
        cin >> p1 >> p2;
        r1 = max(myabs(p1[0] - p2[0]), myabs(p1[1] - p2[1]));
        if (p1 != p2)
        {
            r2 = (p1[0] == p2[0] || p1[1] == p2[1] || myabs(p1[0] - p2[0]) == myabs(p1[1] - p2[1])) ? 1 : 2;
            r3 = (p1[0] == p2[0] || p1[1] == p2[1]) ? 1 : 2;
            if (myabs(p1[0] - p2[0] + p1[1] - p2[1]) % 2 == 1)
            {
                s = "Inf";
            }
            else if (myabs(p1[0] - p2[0]) == myabs(p1[1] - p2[1]))
            {
                s = "1";
            }
            else
            {
                s = "2";
            }
        }
        else
        {
            r2 = 0;
            r3 = 0;
            s = "0";
        }
        cout << r1 << ' ' << r2 << ' ' << r3 << ' ' << s << endl;
    }
    return 0;
}
