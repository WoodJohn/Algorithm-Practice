#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct result
{
    int l;
    int per;
}results[1000001];
int rlen;
char s[1000001];
int len;

int cmp(const void *a, const void *b)
{
    result p = *((result *)a);
    result q = *((result *)b);
    return p.l - q.l;
}

void preprocess(int *N, int l)
{
    N[1] = 0;
    for (int i = 2; i <= l; i++)
    {
        int k = N[i - 1];
        while (k > 0 && s[k] != s[i - 1])
            k = N[k];
        if (s[k] == s[i - 1])
            k++;
        else
            k = 0;
        N[i] = k;
    }
}

void calc()
{
    memset(results, 0, sizeof(results));
    rlen = 0;
    int *N = new int[len + 1];
    preprocess(N, len);
    for (int i = 2; i <= len; i++)
    {
        if (N[i] > 0 && i % (i - N[i]) == 0)
        {
            results[rlen].l = i;
            results[rlen].per = i / (i - N[i]);
            rlen++;
        }
    }
}

int main()
{
    int cnt = 0;
    while (scanf("%d", &len))
    {
        if (len == 0)
            break;
        cnt++;
        scanf("%s", s);
        calc();
        printf("Test case #%d\n", cnt);
        qsort(results, rlen, sizeof(result), cmp);
        for (int i = 0; i < rlen; i++)
        {
            printf("%d %d\n", results[i].l, results[i].per);
        }
        printf("\n");
    }
    return 0;
}
