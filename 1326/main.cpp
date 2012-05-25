#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "#")
            break;
        int sum = 0;
        while (s != "0")
        {
            char c;
            int a;
            cin >> s >> a >> c >> s;
            if (c == 'F')
                sum += 2 * a;
            else if (c == 'B')
                sum += int(1.5 * a + 0.5);
            else if (a <= 500)
                sum += 500;
            else
                sum += a;
        }
        cout << sum << endl;
    }
    return 0;
}
