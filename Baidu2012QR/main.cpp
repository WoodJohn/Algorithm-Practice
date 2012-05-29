#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char s[100005];

int main()
{
    int cnt = 0;
    char res[100005];
    while (cin >> s)
    {
        if (s[0] == '#')
            break;
        cnt++;
        int start;
        int ress, rese;
        int mMax = 0;
        int l = strlen(s);
        start = 0;
        while (start < l)
        {
            int pos = start + 1;
            while (pos < l)
            {
                if (s[pos] == s[start])
                    break;
                pos++;
            }
            if (pos == l)
            {
                start++;
                continue;
            }
            int a = start, b = pos;
            while (a < pos)
            {
                if (s[a] != s[b])
                    break;
                a++;
                b++;
            }
            int cc;
            if (a == pos)
                cc = 1;
            else
            {
                cc = 0;
            }
            bool check = cc > 0;
            if (!check)
            {
                start++;
                continue;
            }
            int aa, bb;
            while (check)
            {
                cc++;
                aa = start;
                bb = b;
                while (aa < a)
                {
                    if (s[aa] == s[bb])
                    {
                        aa++;
                        bb++;
                    }
                    else
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                    b = bb;
            }
            if (cc >= mMax)
            {
                if (cc > mMax)
                {
                    mMax = cc;
                    ress = start;
                    rese = b - 1;
                }
                else
                {
                    int pp;
                    int pp2 = ress;
                    for (pp = start; pp < b; pp++)
                    {
                        if (s[pp] > s[pp2])
                            break;
                        pp2++;
                    }
                    if (pp == b)
                    {
                        ress = start;
                        rese = b - 1;
                    }
                }
            }
            start = b;
        }
        cout << "Case " << cnt << ": ";
        for (int j = ress; j <= rese; j++)
        {
            cout << s[j];
        }
        cout << endl;
    }
}
