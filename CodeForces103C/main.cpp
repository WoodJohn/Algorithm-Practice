#include <iostream>
#include <string.h>
using namespace std;

char s[100005];
char p[100005];

void init()
{
    cin >> s >> p;
}

int calc()
{
    int slen = strlen(s);
    int plen = strlen(p);
    if (slen < plen)
        return 0;
    int i, j;
    int gap = slen - plen;
    int cnt = 0;
    int pc[26] = {0};
    int sc[26] = {0};
    for (i = 0; i < plen; i++)
    {
        pc[p[i] - 'a']++;
        if (s[i] != '?')
            sc[s[i] - 'a']++;
    }
    for (i = 0; i < gap + 1; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (sc[j] > pc[j])
                break;
        }
        if (j == 26)
            cnt++;
        if (s[i] != '?')
            sc[s[i] - 'a']--;
        if (s[i + plen] != '?')
            sc[s[i + plen] - 'a']++;
    }
    return cnt;
}

int main()
{
    init();
    cout << calc() << endl;
    return 0;
}
