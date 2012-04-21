#include <iostream>

using namespace std;

int main()
{
    int init,c1,c2,c3;
    while (cin >> init >> c1 >> c2 >> c3)
    {
        int sum = 0;
        if (init == 0
            && c1 == 0
            && c2 == 0
            && c3 == 0)
            {
                break;
            }
        sum += 720;
        sum += (init + 40 - c1) % 40 * 9;
        sum += 360;
        sum += (c2 + 40 - c1) % 40 * 9;
        sum += (c2 + 40 - c3) % 40 * 9;
        cout << sum << endl;
    }
    return 0;
}
