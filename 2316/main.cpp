#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    string s;
    int num[11];
    memset(num, 0, sizeof(num));
    int cnt;
    while (cin >> s)
    {
        for (int i = 0; i < s.length(); i++)
            num[i] = (num[i] + s[i] - '0') % 10;
        cnt = s.length();
    }
    for (int i = 0; i < cnt; i++)
        cout << num[i];
    cout << endl;
    return 0;
}
