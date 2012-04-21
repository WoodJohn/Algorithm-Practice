/*
POJ 1182
*/

#include <iostream>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int d, x, y, n, k;
int status[50001];
map<int, set<int>> maps;

int main()
{
    cin >> n >> k;
    int sum = 0;
    memset(status, 0, sizeof(int) * n);
    while (k--)
    {
        cin >> d >> x >> y;
        if (x > n || y > n || (d == 2 && x == y))
        {
            sum++;
            continue;
        }
        if (d == 1)
        {
            set<int> s1, s2;
            if (maps.find(x) != )
            set<int> s1 = maps[x];
            set<int> s2 = maps[y];
            if (s1.find(y) == s1.end())
            set<int>::iterator i;
            for (i = s2.begin(); i != s2.end(); i++)
            {

            }
        }
    }
    return 0;
}
