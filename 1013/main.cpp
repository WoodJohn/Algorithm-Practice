#include <iostream>
#include <string>
using namespace std;

int cnt;
string l[5], r[5], res[5];

bool check(int a, bool light)
{
    bool c = false;
    for (int i = 0; i < 3; i++)
    {
        if (l[i].find(char('A' + a)) != -1)
        {
            c = true;
            if ((light && res[i] != "down") || (!light && res[i] != "up"))
                return false;
        }
        else if (r[i].find(char('A' + a)) != -1)
        {
            c = true;
            if ((light && res[i] != "up") || (!light && res[i] != "down"))
                return false;
        }
        else if (res[i] != "even")
            return false;
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
            cin >> l[i] >> r[i] >> res[i];
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (check(i, j == 0))
                {
                    cout << char('A' + i) << " is the counterfeit coin and it is " << ((j == 0) ? "light." : "heavy.") << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
