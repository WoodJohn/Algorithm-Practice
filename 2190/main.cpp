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
    sum %= 11;
    sum = 11 - sum;
    if (sum == 11)
        sum = 0;
    if (sum % (10 - m))
        cout << -1 << endl;
    else
    {
        if (m == 9 && sum == 10)
        {
            cout << 'X' << endl;
        }
        else
            cout << sum / (10 - m) << endl;
    }
    return 0;
}
