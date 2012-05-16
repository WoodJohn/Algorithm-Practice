#include <iostream>
#include <vector>
using namespace std;

int findmax(vector<int> num)
{
    int i;
    int mMax = 0;
    int maxi = 0;
    for (i = 0; i < num.size(); i++)
    {
        if (num[i] > mMax)
        {
            mMax = num[i];
            maxi = i;
        }
    }
    return maxi;
}

int findmin(vector<int> num)
{
    int i;
    int mMin = 99999;
    int mini = 0;
    for (i = 0; i < num.size(); i++)
    {
        if (num[i] < mMin)
        {
            mMin = num[i];
            mini = i;
        }
    }
    return mini;
}

int main()
{
    int m, n;
    int cnt = 0;
    while (cin >> m)
    {
        if (cnt > 0)
            cout << endl;
        cnt++;
        vector<int> list, r, num;
        list.clear();
        r.clear();
        num.clear();
        cin >> n;
        int i;
        for (i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            list.push_back(a);
        }
        int p = 1;
        char c;
        while (cin >> c)
        {
            if (c == 'a')
            {
                int b;
                cin >> b;
                num.push_back(b);
            }
            if (c == 'p')
            {
                cin >> p;
            }
            if (c == 'r')
            {
                if (num.empty())
                {
                    r.push_back(-1);
                }
                else
                {
                    int pos;
                    if (p == 1)
                    {
                        pos = findmin(num);
                    }
                    else
                    {
                        pos = findmax(num);
                    }
                    r.push_back(num[pos]);
                    num.erase(num.begin() + pos);
                }
            }
            if (c == 'e')
            {
                for (i = 0; i < list.size(); i++)
                {
                    cout << r[list[i] - 1] << endl;
                }
                break;
            }
        }
    }
    return 0;
}
