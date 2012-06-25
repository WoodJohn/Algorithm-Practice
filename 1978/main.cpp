#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n, r;
    while (cin >> n >> r)
    {
        if (n == r && n == 0)
            break;
        int num[55], i;
        for (i = 1; i <= n; i++)
        {
            num[i] = n - i + 1;
        }
        while (r--)
        {
            int p, c;
            cin >> p >> c;
            int temp[55];
            memcpy(temp, num + 1, (p - 1) * sizeof(int));
            memcpy(num + 1, num + p, c * sizeof(int));
            memcpy(num + c + 1, temp, (p - 1) * sizeof(int));
        }
        cout << num[1] << endl;
    }
    return 0;
}
