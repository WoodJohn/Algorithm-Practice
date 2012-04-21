#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n;

vector<int> v;

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        v.clear();
        while (n--)
        {
            int a;
            cin >> a;
            if (v.empty() || v[v.size() - 1] != a)
                v.push_back(a);
        }
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << '$' << endl;
    }
    return 0;
}
