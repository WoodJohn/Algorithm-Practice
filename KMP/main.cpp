/*
KMP≤‚ ‘≥Ã–Ú
input £∫
S
P

output £∫
first_pos
*/

#include <iostream>
#include <string.h>
using namespace std;

int *next(char *s)
{
    int i, k;
    int len = strlen(s);
    int *N = new int[len + 1];
//    N[0] = 0;
//    for (i = 1; i < len; i++)
//    {
//        k = N[i - 1];
//        while (s[k] != s[i] && k > 0)
//        {
//            k = N[k];
//        }
//        if (s[k] == s[i])
//            k++;
//        N[i] = k;
//    }
    int j = 0; N[1] = 0;
    k = 1;
    while(k < len)
    {
        if (j == 0 || s[k] == s[j])
        {
            ++k; ++j;
            if (s[k] == s[j])
                N[k] = N[j];
            else
                N[k] = j;
        }
        else j = N[j];
    }
    return N;
}

int kmp(char *s, char *p)
{
    int slen = strlen(s);
    int plen = strlen(p);
    int *N = next(p);
    int i, j;
    j = 0;
    for (i = 0; i < slen; i++)
    {
        while (s[i] != p[j] && j > 0)
        {
            j = N[j];
        }
        if (s[i] == p[j])
            j++;
        if (j == plen)
            return i - j + 1;
    }
    return -1;
}

int main()
{
    char s[256], p[256];
    while (cin >> s >> p)
    {
        cout << kmp(s, p) << endl;
//        int *N = next(p);
//        for (int i = 1; i <= strlen(p); i++)
//            cout << N[i];
//        cout << endl;
    }
    return 0;
}
