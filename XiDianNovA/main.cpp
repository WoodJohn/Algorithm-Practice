#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[256];
    while (cin >> s)
    {
        int len = strlen(s);
        int i;
        int cnt = 0;
        bool check = true;
        if (len % 2)
        {
            check = false;
        }
        else
        {
            for (i = 0; i < len; i++)
            {
                if (s[i] == '(')
                    cnt++;
                else if (cnt == 0)
                {
                    check = false;
                    break;
                }
                else
                    cnt--;
            }
            if (cnt > 0)
                check = false;
        }
        cout << ((check) ? "YES" : "NO") << endl;
    }
    return 0;
}
