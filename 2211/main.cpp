#include <iostream>
#include <stdio.h>
using namespace std;

int com(int a, int b)
{
    int t = b;
    int p = a;
    int ret = 1;
    while (t--)
    {
        ret *= p--;
    }
    return ret;
}

int main()
{
    int n, k;
    int t;
    cin >> t;
    int i;
    for (i = 1; i <= t; i++)
    {
        cin >> n >> k;
        bool used[15] = {false};
        int cur = k;
        int sum = 0;
        while (1)
        {
            int a;
            cin >> a;
            if (cur == 1)
            {
                int j;
                for (j = a; j > 0; j--)
                {
                    if (!used[j])
                        sum++;
                }
                break;
            }
            else
            {
                used[a] = true;
                int j;
                for (j = a - 1; j > 0; j--)
                {
                    if (!used[j])
                        sum += com(n - (k - cur) - 1, cur - 1);
                }
                cur--;
            }
        }
        printf("Variace cislo %d ma poradove cislo %d.\n", i, sum);
    }
    return 0;
}
