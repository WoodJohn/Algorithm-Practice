#include <iostream>
#include <string.h>
using namespace std;

char s[500];
char s1[300];
char s2[300];
bool used[300];
bool ans;
int l, l1, l2;

bool dfs(int d, int d1, int d2)
{
    if (d == l && d1 == l1 && d2 == l2)
    {
        return true;
    }
    if (d1 < l1 && s1[d1] == s[d])
    {
        if (dfs(d + 1, d1 + 1, d2))
            return true;
    }
    if (d2 < l2 && s2[d2] == s[d])
    {
        if (dfs(d + 1, d1, d2 + 1))
            return true;
    }
    return false;
}

#include <fstream>

int main()
{
    int n;
    cin >> n;
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> s1 >> s2 >> s;
        memset(used, 0, sizeof(used));
        l1 = strlen(s1);
        l2 = strlen(s2);
        l = strlen(s);
        if (l1 + l2 != l || (s[0] != s1[0] && s[0] != s2[0]) || (s[l - 1] != s1[l1 - 1] && s[l - 1] != s2[l2 - 1]))
            cout << "Data set " << i << ": no" << endl;
        else
        {
            ans = dfs(0, 0, 0);
            if (ans)
                cout << "Data set " << i << ": yes" << endl;
            else
                cout << "Data set " << i << ": no" << endl;
        }
    }
    return 0;
}
