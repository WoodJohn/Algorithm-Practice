#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[40000];
    while (cin >> s)
    {
        int m = 0;
        int i, sum = 0;
        int l = strlen(s);
        for (i = 0; i < l; i++)
        {
            int t;
            if (s[i] >= '0' && s[i] <= '9')
                t = s[i] - '0';
            if (s[i] >= 'A' && s[i] <= 'Z')
                t = s[i] - 'A' + 10;
            if (s[i] >= 'a' && s[i] <= 'z')
                t = s[i] - 'a' + 36;
            if (t > m)
                m = t;
            sum += t;
        }
        if (m == 0)
            m = 1;
        for (i = m + 1; i < 63; i++)
        {
            if (sum % (i - 1) == 0)
            {
                cout << i << endl;
                break;
            }
        }
        if (i == 63)
            cout << "such number is impossible!" << endl;
    }
    return 0;
}
