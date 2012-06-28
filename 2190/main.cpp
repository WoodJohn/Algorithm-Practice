#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[20];
    cin >> s;
    int i;
    int sum = 0;
    int m;
    for (i = 0; i < 10; i++)
    {
        if (s[i] == '?')
            m = i;
        else if (i < 9)
        {
            sum += (s[i] - '0') * (10 - i);
        }
        else
        {
            if (s[i] == 'X')
                sum += 10;
            else
                sum += s[i] - '0';
        }
    }
    if (m < 9)
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            if ((sum + i * (10 - m)) % 11 == 0)
            {
                cout << i << endl;
                break;
            }
        }
        if (i == 10)
            cout << -1 << endl;
    }
    else
    {
        int i;
        for (i = 0; i <= 10; i++)
        {
            if ((sum + i * (10 - m)) % 11 == 0)
            {
                if (i < 10)
                    cout << i << endl;
                else
                    cout << 'X' << endl;
                break;
            }
        }
        if (i == 11)
            cout << -1 << endl;
    }
    return 0;
}
