#include <iostream>

using namespace std;

int k, l, m, n, d;

int main()
{
    cin >> k >> l >> m >> n >> d;
    int i;
    int cnt = 0;
    for (i = 1; i <= d; i++)
    {
        if (i % k == 0)
        {
            cnt++;
            continue;
        }
        if (i % l == 0)
        {
            cnt++;
            continue;
        }
        if (i % m == 0)
        {
            cnt++;
            continue;
        }
        if (i % n == 0)
        {
            cnt++;
            continue;
        }
    }
    cout << cnt << endl;
    return 0;
}
