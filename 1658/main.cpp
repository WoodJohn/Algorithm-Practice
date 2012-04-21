#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int input[5];
    while (t --)
    {
        memset(input, 0, 5 * sizeof(int));
        cin >> input[0] >> input[1] >> input[2] >> input[3];
        if (2 * input[2] == input[3] + input[1])
        {
            cout << input[0] << ' ' << input[1] << ' ' << input[2] << ' ' << input[3] << ' ' << 2 * input[3] - input[2] << endl;
        }
        else
        {
            cout << input[0] << ' ' << input[1] << ' ' << input[2] << ' ' << input[3] << ' ' << input[3] * input[3] / input[2] << endl;
        }
    }
    return 0;
}
