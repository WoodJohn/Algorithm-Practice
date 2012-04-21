#include <iostream>
#include <string.h>
using namespace std;

int h, n, t[25], d[25], f[25], time;
int best[25];
int beststay[25];
int stay[25];

int cmax(int c[], int last);

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        cin >> h;
        int i;
        int sum[25];
        sum[0] = 0;
        for (i = 0; i < n; i++)
        {
            cin >> f[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        for (i = 1; i < n; i++)
        {
            cin >> t[i];
            sum[i] = sum[i - 1] + t[i];
        }
        int mMax = -1;
        for (i = 0; i < n; i++)
        {
            memset(stay, 0, sizeof(stay));
            best[i] = 0;
            int time = h * 12 - sum[i];
            int current[25];
            int j;
            for (j = 0; j < n; j++)
            {
                current[j] = f[j];
            }
            while (time > 0)
            {
                int k = cmax(current, i);
                time--;
                stay[k]++;
                best[i] += current[k];
                current[k] -= d[k];
                if (current[k] < 0)
                    current[k] = 0;
            }
            if (best[i] > mMax)
            {
                mMax = best[i];
                memcpy(beststay, stay, n * sizeof(int));
            }
        }
        for (i = 0; i < n - 1; i++)
        {
            cout << beststay[i] * 5 << ", ";
        }
        cout << beststay[n - 1] * 5 << endl;
        cout << "Number of fish expected: " << mMax << endl << endl;
    }
    return 0;
}

int cmax(int c[], int last)
{
    int i;
    int mMax = 0;
    int maxi = 0;
    for (i = 0; i <= last; i++)
    {
        if (c[i] > mMax)
        {
            mMax = c[i];
            maxi = i;
        }
    }
    return maxi;
}
