#include <iostream>
#include <algorithm>
using namespace std;

int n;
int data[100002];

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> data[i];
    }
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        int mMax = 0;
        int hMax = 0;
        int iMax = 0;
        int tMax = 0;
        for (int j = i + 1; j <= i + data[i]; j++)
        {
            if (j > n)
            {
                if (tMax < data[i])
                {
                    iMax = n + 1;
                    mMax = 0;
                }
                break;
            }
            if (data[j] > tMax && data[j] >= data[i])
            {
                iMax = j;
                tMax = data[j];
            }
            if (data[j] + j >= mMax && tMax < data[i])
            {
                if (data[j] + j == mMax)
                {
                    if (data[j] > hMax)
                    {
                        hMax = data[j];
                        iMax = j;
                    }
                }
                else
                {
                    mMax = data[j] + j;
                    hMax = data[j];
                    iMax = j;
                }
            }
        }
        if (data[iMax] > data[i])
            sum += data[iMax] - data[i];
        i = iMax - 1;
    }
    cout << sum << endl;
    return 0;
}
