#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == -1)
            break;
        int mMax = 0, mMin = 99999;
        string maxn, minn;
        while (n--)
        {
            int a, b, c;
            string s;
            cin >> a >> b >> c >> s;
            int v = a * b * c;
            if (v > mMax)
            {
                mMax = v;
                maxn = s;
            }
            if (v < mMin)
            {
                mMin = v;
                minn = s;
            }
        }
        cout << maxn << " took clay from " << minn << '.' << endl;
    }
    return 0;
}
