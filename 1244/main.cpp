#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct point
{
    double x, y;
};

vector<point> a[26];

double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool test(int aa)
{
    if (a[aa].size() < 3)
        return false;
    double d1 = dis(a[aa][0], a[aa][1]);
    double d2 = dis(a[aa][0], a[aa][2]);
    double d3 = dis(a[aa][1], a[aa][2]);
    if (abs(d1 - d2) < 1e-8 && abs(d2 - d3) < 1e-8 && abs(d1 - d3) < 1e-8)
        return true;
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int i;
        for (i = 0; i < 26; i++)
        {
            a[i].clear();
        }
        char s[80];
        cin >> s;
        int j;
        int l = 0;
        while (n - l)
        {
            int start = l * (l + 1) / 2;
            int end = (l + 1) * (l + 2) / 2;
            for (i = start; i < end; i++)
            {
                point p;
                p.x = 2 * (i - start) - (end - start - 1);
                p.y = l * sqrt(3);
                a[s[i] - 'a'].push_back(p);
            }
            l++;
        }
        bool check = false;
        for (i = 0; i < 26; i++)
        {
            if (test(i))
            {
                check = true;
                cout << char('a' + i);
            }
        }
        if (!check)
            cout << "LOOOOOOOOSER!";
        cout << endl;
    }
    return 0;
}
