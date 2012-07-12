#include <iostream>
#include <string.h>
using namespace std;

char Haab[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char Tzolkin[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int m2m(char *m)
{
    for (int i = 0; i < 19; i++)
    {
        if (strcmp(m, Haab[i]) == 0)
            return i;
    }
    return -1;
}

int main()
{
    char day[10];
    char month[10];
    int year;
    int n;
    cin >> n;
    cout << n << endl;
    while (n--)
    {
        cin >> day >> month >> year;
        int d = 0;
        int pos = 0;
        while (day[pos] != '.')
            d = d * 10 + day[pos++] - '0';
        int m = m2m(month);
        int sum = year * 365 + m * 20 + d;
        int ty = sum / 260;
        sum %= 260;
        int tm = sum % 20;
        d = sum % 13 + 1;
        cout << d << ' ' << Tzolkin[tm] << ' ' << ty << endl;
    }
    return 0;
}
