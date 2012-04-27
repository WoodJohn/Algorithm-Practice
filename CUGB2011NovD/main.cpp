#include <iostream>

using namespace std;

int main()
{
    int hw;
    int vw;
    int vh1, vh2;
    int t;
    cin >> t;
    int i;
    for (i = 0; i < t; i++)
    {
        int h;
        cin >> h;
        vh1 = (h - 3) / 2;
        vh2 = h - 3 - vh1;
        vw = h / 6 + 1;
        hw = vh2;
        int j;
        for (j = 0; j < vw; j++)
        {
            cout << ' ';
        }
        for (j = 0; j < hw; j++)
        {
            cout << '6';
        }
        cout << endl;
        for (j = 0; j < vh1; j++)
        {
            int k;
            for (k = 0; k < vw; k++)
            {
                cout << '6';
            }
            cout << endl;
        }
        for (j = 0; j < vw; j++)
        {
            cout << ' ';
        }
        for (j = 0; j < hw; j++)
        {
            cout << '6';
        }
        cout << endl;
        for (j = 0; j < vh2; j++)
        {
            int k;
            for (k = 0; k < vw; k++)
            {
                cout << '6';
            }
            for (k = 0; k < hw; k++)
            {
                cout << ' ';
            }
            for (k = 0; k < vw; k++)
            {
                cout << '6';
            }
            cout << endl;
        }
        for (j = 0; j < vw; j++)
        {
            cout << ' ';
        }
        for (j = 0; j < hw; j++)
        {
            cout << '6';
        }
        cout << endl;
        if (i < t - 1)
            cout << endl;
    }
    return 0;
}
