#include <iostream>

using namespace std;

int main()
{
    int n;
    int cun, chi, yu;
    cin >> n;
    cun = n / 3;
    yu = n % 3;
    if (yu > 1)
        cun++;
    chi = cun / 12;
    cun %= 12;
    cout << chi << ' ' << cun << endl;
    return 0;
}
