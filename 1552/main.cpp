#include <iostream>

using namespace std;

int main()
{
    int num[16];
    while (cin >> num[0])
    {
        if (num[0] == -1)
        {
            break;
        }
        int i = 1;
        int count = 0;
        int n;
        while (cin >> n)
        {
            if (n == 0)
            {
                break;
            }
            num[i ++] = n;
        }
        for (int j = 0; j < i - 1; j ++)
        {
            for (int k = j + 1; k < i; k ++)
            {
                if (num[j] == 2 * num[k] || num[j] * 2 == num[k])
                {
                    count ++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
