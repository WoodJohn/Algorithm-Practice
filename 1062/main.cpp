#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct item
{
    int lv;
    int price;
}items[102];

vector<int> c[101];
int pp[101][101];
bool used[101];
int n, m, mMax;

void dfs(int a, int maxlv, int minlv, int cur)
{
    item it = items[a];
    int i;
    for (i = 0; i < c[a].size(); i++)
    {
        int t = c[a][i];
        if (!used[t])
        {
            item it2 = items[t];
            if (it2.lv - minlv <= m && maxlv - it2.lv <= m)
            {
                int res = cur + it.price - pp[a][t] - it2.price;
                if (res > mMax)
                    mMax = res;
                int malv = it2.lv > maxlv ? it2.lv : maxlv;
                int milv = it2.lv < minlv ? it2.lv : minlv;
                used[t] = true;
                dfs(t, malv, milv, res);
                used[t] = false;
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    int i;
    memset(used, false, sizeof(used));
    memset(pp, 0, sizeof(pp));
    mMax = 0;
    used[1] = true;
    for (i = 1; i <= n; i++)
    {
        int p, l, x;
        cin >> p >> l >> x;
        items[i].price = p;
        items[i].lv = l;
        int j;
        for (j = 0; j < x; j++)
        {
            int ap, no;
            cin >> no >> ap;
            c[i].push_back(no);
            pp[i][no] = ap;
        }
    }
    dfs(1, items[1].lv, items[1].lv, 0);
    cout << items[1].price - mMax << endl;
    return 0;
}
