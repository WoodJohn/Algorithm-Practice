#include <iostream>
#include <cmath>

using namespace std;

int cnt[100002];

bool prime(int n)
{
    for (int i = 2; i <= int(sqrt(n)); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cnt[0] = cnt[1] = cnt[2] = 0;
    cnt[3] = 1;
    for (int i = 3; i < 100001; i++)
    {
        if (prime(i))
            cnt[i + 1] = cnt[i] + 1;
        else
            cnt[i + 1] = cnt[i];
    }
    int a, b;
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
            break;
        cout << cnt[b + 1] - cnt[a] << endl;
    }
    return 0;
}
