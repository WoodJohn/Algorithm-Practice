#include <iostream>
#include <string.h>
using namespace std;

char s[100005], t[100005];

bool test()
{
    int i, j;
    i = j = 0;
    int l1, l2;
    l1 = strlen(s);
    l2 = strlen(t);
    while (1)
    {
        while (j < l2)
        {
            if (t[j] == s[i])
            {
                i++;
                if (i == l1)
                    return true;
            }
            j++;
        }
        return false;
    }
}

int main()
{
    while (cin >> s >> t)
        cout << (test() ? "Yes" : "No") << endl;
    return 0;
}
