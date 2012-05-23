#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

bool used[21];
int num[21];
vector<int> res1;
vector<int> res2;
int n1, n2, n;
bool check;
ofstream fout;

void dfs(int c1, int c2, int s1, int s2, int p1, int p2)
{
    if (check)
        return;
    if (c1 == n1)
    {
        if (c2 == n2)
        {
            if (s1 == s2)
            {
                int p;
                for (p = 0; p < res1.size() - 1; p++)
                {
                    fout << res1[p] << ' ';
                }
                fout << res1[res1.size() - 1] << endl;
                for (p = 0; p < res2.size() - 1; p++)
                {
                    fout << res2[p] << ' ';
                }
                fout << res2[res2.size() - 1] << endl;
                check = true;
            }
            return;
        }
        int i;
        for (i = p2 + 1; i < n; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                res2.push_back(num[i]);
                dfs(c1, c2 + 1, s1, s2 + num[i], p1, i);
                used[i] = false;
                res2.pop_back();
            }
        }
    }
    else
    {
        int i;
        for (i = p1 + 1; i < n; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                res1.push_back(num[i]);
                dfs(c1 + 1, c2 , s1 + num[i], s2, i + 1, p2);
                used[i] = false;
                res1.pop_back();
            }
        }
    }
}

int main()
{
    fout.open("out.out", ios::out);
    int t, k;
    cin >> t;
    for (k = 1; k <= t; k++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        check = false;
        fout << "Case #" << k << ":" << endl;
        for (n1 = 1; n1 <= n / 2; n1++)
        {
            if (check)
                break;
            for (n2 = n1; n2 <= n - n1; n2++)
            {
                if (check)
                    break;
                memset(used, false, sizeof(used));
                res1.clear();
                res2.clear();
                dfs(0, 0, 0, 0, -1, -1);
            }
        }
        if (!check)
            fout << "impossible" << endl;
    }
    return 0;
}
