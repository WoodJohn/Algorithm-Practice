#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p[21], w[21];
        memset(p, 0, sizeof(p));
        memset(w, 0, sizeof(w));
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        w[0] = 1;
        for (i = 1; i < n; i++)
        {
            int cnt = 0;
            if (p[i] != p[i - 1])
            {
                w[i] = 1;
            }
            else
            {
                int t = i;
                while (p[t] == p[t - 1] && t > 0)
                {
                    cnt++;
                    t--;
                }
                if (t == 0 && p[t] == p[t - 1])
                    w[i] = w[i - 1] + 1;
                else
                {
                    int sum = cnt;
                    while (sum > 0 && t > 0)
                    {
                        sum -= p[t] - p[t - 1];
                        t--;
                    }
                    if (t == 0)
                        w[i] =
                }
            }
        }
        for (i = 0; i < n - 1; i++)
        {
            cout << w[i] << ' ';
        }
        cout << w[n - 1] << endl;
    }
    return 0;
}
