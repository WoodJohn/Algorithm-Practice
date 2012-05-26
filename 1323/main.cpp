#include <iostream>
#include <string.h>
#include <algorithm>

#define OTHER 0
#define SELF 1
#define USED 2

using namespace std;

int status[1000];

int main()
{
    int n, m;
    int cnt = 1;
    while (cin >> m >> n)
    {
        if (m == n && m == 0)
            break;
        int i;
        int num[55];
        memset(status, OTHER, sizeof(status));
        for (i = 0; i < n; i++)
        {
            cin >> num[i];
            status[num[i]] = SELF;
        }
        sort(num, num + n, greater<int>());
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            int t = num[i] + 1;
            while (t <= m * n)
            {
                if (status[t] == OTHER)
                {
                    status[t] = USED;
                    break;
                }
                t++;
            }
            if (t == m * n + 1)
                sum++;
        }
        cout << "Case " << cnt++ << ": "<< sum << endl;
    }
    return 0;
}
