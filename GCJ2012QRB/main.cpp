#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("out.out", ios::out);
    int n;
    cin >> n;
    getchar();
    int i;
    for (i = 1; i <= n; i++)
    {
        int t, s, p;
        int score[101];
        cin >> t >> s >> p;
        int nn = 3 * p - 2;
        if (nn < 0)
            nn = 0;
        int ns = 3 * p - 4;
        if (ns < 0)
            ns = 2;
        int j;
        int tn, ts;
        tn = ts = 0;
        for (j = 0; j < t; j++)
        {
            cin >> score[j];
            if (score[j] >= nn)
                tn++;
            if (score[j] >= ns)
                ts++;
        }
        int result;
        if (ns <= nn)
        {
            if (ts - tn < s)
                result = ts;
            else
                result = tn + s;
        }
        else
        {
            result = tn;
        }
        fout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}
