#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool reven[101];
bool ceven[101];
int n;
int m[101][101];

int main()
{
    while (cin >> n)
    {
        if (!n)
            break;
        memset(reven, true, sizeof(reven));
        memset(ceven, true, sizeof(ceven));
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> m[i][j];
                if (m[i][j])
                {
                    reven[i] = !reven[i];
                    ceven[j] = !ceven[j];
                }
            }
        }
        int rcnt, ccnt;
        rcnt = 0;
        ccnt = 0;
        int r, c;
        for (i = 0; i < n; i++)
        {
            if (!reven[i])
            {
                rcnt++;
                r = i;
            }
            if (!ceven[i])
            {
                ccnt++;
                c = i;
            }
        }
        if (rcnt + ccnt == 0)
            cout << "OK" << endl;
        else if (rcnt == 1 && ccnt == 1)
        {
            printf("Change bit (%d,%d)\n", r + 1, c + 1);
        }
        else
            cout << "Corrupt" << endl;
    }
    return 0;
}
