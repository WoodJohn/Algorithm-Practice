#include <iostream>

using namespace std;

int n;
int lp, sp;

void init()
{
    cin >> n;
    int i;
    int a[101];
    int minN, minP, maxN, maxP;
    minN = 99999;
    maxN = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > maxN)
        {
            maxN = a[i];
            maxP = i;
        }
        if (a[i] <= minN)
        {
            minN = a[i];
            minP = i;
        }
    }
    lp = maxP;
    sp = minP;
}

int calc()
{
    if (lp == sp)
    {
        return 0;
    }
    if (lp < sp)
    {
        return lp + n - sp - 1;
    }
    if (lp > sp)
    {
        return lp + n - sp - 2;
    }
}

int main()
{
    init();
    cout << calc() << endl;
    return 0;
}
