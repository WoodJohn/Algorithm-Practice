#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int num[15];
        int i;
        char s[50];
        int mMin = 99999;
        for (i = 0; i < n; i++)
        {
            getchar();
            gets(s);
            int len = strlen(s);
            int p1 = 0, p2;
            while (s[p1] != ' ' && p1 < len)
                p1++;
            if (p1 == len)
                num[i] = 0;
            else
            {
                p2 = p1 + 1;
                while (s[p2] != 'X')
                    p2++;
                num[i] = p2 - p1;
            }
            if (num[i] < mMin)
                mMin = num[i];
        }
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += num[i] - mMin;
        }
        cout << sum << endl;
    }
    return 0;
}
