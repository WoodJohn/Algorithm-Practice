#include <iostream>

using namespace std;

int main()
{
    int s[6];
    while (cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5])
    {
        if (s[0] + s[1] + s[2] + s[3] + s[4] + s[5] == 0)
            break;
        int cnt = 0;
        int temp;
        cnt += s[5];

        cnt += s[4];
        s[0] -= s[4] * 11;
        if (s[0] < 0)
            s[0] = 0;

        cnt += s[3];
        s[1] -= s[3] * 5;
        if (s[1] < 0)
        {
            s[0] += s[1] * 4;
            if (s[0] < 0)
                s[0] = 0;
            s[1] = 0;
        }

        if (s[2] > 0)
        {
            cnt += (s[2] - 1) / 4 + 1;
            temp = (4 - (s[2] % 4)) % 4;
            if (temp == 1)
            {
                s[1]--;
                if (s[1] < 0)
                {
                    s[0] += s[1] * 4;
                    if (s[0] < 0)
                        s[0] = 0;
                    s[1] = 0;
                }
                s[0] -= 5;
                if (s[0] < 0)
                    s[0] = 0;
            }
            else if (temp == 2)
            {
                s[1] -= 3;
                if (s[1] < 0)
                {
                    s[0] += s[1] * 4;
                    if (s[0] < 0)
                        s[0] = 0;
                    s[1] = 0;
                }
                s[0] -= 6;
                if (s[0] < 0)
                    s[0] = 0;
            }
            else if (temp == 3)
            {
                s[1] -= 5;
                if (s[1] < 0)
                {
                    s[0] += s[1] * 4;
                    if (s[0] < 0)
                        s[0] = 0;
                    s[1] = 0;
                }
                s[0] -= 7;
                if (s[0] < 0)
                    s[0] = 0;
            }
        }

        if (s[1] > 0)
        {
            cnt += (s[1] - 1) / 9 + 1;
            temp = (9 - (s[1] % 9)) % 9;
            s[0] -= temp * 4;
            if (s[0] < 0)
                s[0] = 0;
        }

        if (s[0] > 0)
            cnt += (s[0] - 1) / 36 + 1;

        cout << cnt << endl;
    }
    return 0;
}
