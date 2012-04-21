#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<int, int> m;

int main()
{
    bool ji, ou;
    int n;
    int cnt = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cnt++;
        ji = true;
        ou = true;
        int a, b;
        m.clear();
        map<int, int>::iterator it;
        while (n--)
        {
            cin >> a >> b;
            it = m.find(b);
            if (it == m.end())
                m.insert(pair<int, int>(b, a));
            else
                it->second += a;
        }
        for (it = m.begin(); it != m.end(); it++)
        {
            int a, b;
            b = it->first;
            a = it->second;
            if (b % 2 == 0 && a != 0)
                ji = false;
            else if (b % 2 != 0 && a != 0)
                ou = false;
        }
        printf("Case #%d: ", cnt);
        if (ji && ou)
            cout << "Particular Function" << endl;
        else if (ji && !ou)
            cout << "Odd Function" << endl;
        else if (!ji && ou)
            cout << "Even Function" << endl;
        else
            cout << "Ordinary Function" << endl;
    }
    return 0;
}
