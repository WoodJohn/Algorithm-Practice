#include <iostream>
#include <string.h>
using namespace std;

char ret[1005];

bool div(char *s, int a)
{
    int left = 0;
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        left = left * 10 + s[i] - '0';
        ret[i] = char(left / a + '0');
        left %= a;
    }
    int i = 0;
    while (ret[i] == '0')
        i++;
    l = strlen(ret);
    for (int j = 0; j < l - i; j++)
    {
        ret[j] = ret[j + i];
    }
    ret[l - i] = '\0';
    return left == 0;
}

int main()
{
    char s[1005];
    while (cin >> s)
    {
        if (!strcmp(s, "-1"))
            break;
        if (!strcmp(s, "0"))
        {
            cout << "10" << endl;
            continue;
        }
        if (!strcmp(s, "1"))
        {
            cout << "11" << endl;
            continue;
        }
        char res[5005];
        int cnt = 0;
        while (1)
        {
            int i;
            for (i = 9; i >= 2; i--)
            {
                if (div(s, i))
                {
                    strcpy(s, ret);
                    res[cnt++] = char(i + '0');
                    break;
                }
            }
            if (i == 1)
            {
                cout << "There is no such number." << endl;
                break;
            }
            else if (strlen(s) == 1)
            {
                res[cnt++] = s[0];
                res[cnt] = '\0';
                for (int j = 0; j < cnt; j++)
                {
                    cout << res[cnt - j - 1];
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
