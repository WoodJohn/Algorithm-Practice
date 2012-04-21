#include <iostream>
#include <string>

using namespace std;

string str[101];

string rev(string a)
{
    string res = a;
    int len = res.size();
    for (int i = 0; i < len / 2; i ++)
    {
        char c = res[i];
        res[i] = res[len - i - 1];
        res[len - i - 1] = c;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i ++)
        {
            cin >> str[i];
        }
        int max = 0;
        int j,k,l;
        int size = str[0].size();
        for (j = 0; j < size; j ++)
        {
            for (k = j; k < size; k ++)
            {
                string s = str[0].substr(j, k - j + 1);
                for (l = 1; l < n; l ++)
                {
                    if (str[l].find(s) == string::npos && str[l].find(rev(s)) == string::npos)
                    {
                        break;
                    }
                }
                if (l == n && k - j + 1 > max)
                {
                    max = k - j + 1;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}
