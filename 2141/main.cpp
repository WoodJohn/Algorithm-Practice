#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[30];

int main()
{
    char ss[100];
    cin >> s;
    getchar();
    gets(ss);
    int l = strlen(ss);
    for (int i = 0; i < l; i++)
    {
        if (ss[i] >= 'a' && ss[i] <= 'z')
        {
            ss[i] = s[ss[i] - 'a'];
        }
        else if (ss[i] >= 'A' && ss[i] <= 'Z')
        {
            ss[i] = s[ss[i] - 'A'] - 32;
        }
    }
    cout << ss << endl;
    return 0;
}
