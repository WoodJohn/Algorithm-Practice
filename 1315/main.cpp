#include <iostream>

using namespace std;

int n;
char str[10][10];

bool check(int a)
{
    int i;
    for (i = 0; i < n * n; i++)
    {
        if ((1 << (n * n - i - 1)) & a)
        {
            if (str[i / n][i % n] == 'X')
                return false;
            int j;
            for (j = i / n + 1; j < n; j++)
            {
                if (str[j][i % n] == 'X')
                    break;
                if ((1 << (n * n - j * n - i % n - 1)) & a)
                    return false;
            }
            for (j = i % n + 1; j < n; j++)
            {
                if (str[i / n][j] == 'X')
                    break;
                if ((1 << (n * n - 1 - i / n * n - j)) & a)
                    return false;
            }
        }
    }
    return true;
}

int calc(int a)
{
    int i;
    int sum = 0;
    for (i = 0; i < n * n; i++)
    {
        if ((1 << i) & a)
            sum++;
    }
    return sum;
}

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        int i;
        int mMax = 0;
        for (i = 0; i < n; i++)
        {
            cin >> str[i];
        }
        int num = 1 << (n * n);
        for (i = 0; i < num; i++)
        {
            if (check(i))
            {
                int t = calc(i);
                if (t > mMax)
                    mMax = t;
            }
        }
        cout << mMax << endl;
    }
    return 0;
}
