#include <stdio.h>
#include <algorithm>
#include <functional>
#include <string.h>

#define INF 99999

using namespace std;

char cur[6];
char words[101][6];
char minword[6];
int mincount;
int n;

int indexof(char *s, char c)
{
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
}

int calc(char *a, char *b)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            char aa = a[i];
            char bb = a[j];
            int pos1 = indexof(b, aa);
            int pos2 = indexof(b, bb);
            if (pos1 > pos2)
                count ++;
        }
    }
    return count;
}

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        mincount = INF;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", words[i]);
        }
        strcpy(cur, "ABCDE");
        do
        {
            int t = 0;
            for (int i = 0; i < n; i++)
            {
                t += calc(cur, words[i]);
            }
            if (t < mincount)
            {
                mincount = t;
                strcpy(minword, cur);
            }
        }
        while (next_permutation(cur, cur + 5, less<int>()));
        printf("%s is the median ranking with value %d.\n", minword, mincount);
    }
    return 0;
}
