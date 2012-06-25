#include <iostream>
using namespace std;

int main()
{
    int n, q;
    while (cin >> n >> q)
    {
        if (n == q && n == 0)
            break;
        int num[105] = {0};
        int mMax = 0;
        int maxi = 0;
        while (n--)
        {
            int a;
            cin >> a;
            while (a--)
            {
                int b;
                cin >> b;
                num[b]++;
                if (num[b] >= q && (num[b] > mMax || (num[b] == mMax && b < maxi)))
                {
                    mMax = num[b];
                    maxi = b;
                }
            }
        }
        if (mMax > 0)
            cout << maxi << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
