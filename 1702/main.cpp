#include <iostream>
#include <vector>
using namespace std;

int tri[20] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[20] = {0};
        int cnt = 0;
        while (n)
        {
            a[cnt++] = n % 3;
            n /= 3;
        }
        int i;
        int tmp = cnt;
        for (i = 0; i < tmp; i++)
        {
            if (a[i] > 1)
            {
                a[i] -= 3;
                a[i + 1]++;
                if (i == tmp - 1)
                    cnt++;
            }
        }
        vector<int> a1, a2;
        for (i = 0; i < cnt; i++)
        {
            if (a[i] > 0)
                a1.push_back(tri[i]);
            else if (a[i] < 0)
                a2.push_back(tri[i]);
        }
        for (i = 0; i < a2.size(); i++)
        {
            cout << a2[i];
            if (i < a2.size() - 1)
                cout << ',';
        }
        if (a2.size() == 0)
            cout << "empty";
        cout << ' ';
        for (i = 0; i < a1.size(); i++)
        {
            cout << a1[i];
            if (i < a1.size() - 1)
                cout << ',';
        }
        cout << endl;
    }
    return 0;
}
