#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[15];
bool used[14];

char result[15];

int len;

int cmp(const void *a, const void *b)
{
    char p = *((char *)a);
    char q = *((char *)b);
    char m,n;
    m = p >= 'a' ? (p - 'a' + 'A') : p;
    n = q >= 'a' ? (q - 'a' + 'A') : q;
    if (m == n)
        return p - q;
    return m - n;
}

void dfs(int a)
{
    if (a == len)
    {
        printf("%s\n", result);
        return;
    }
    for (int i = 0; i < len; i ++)
    {
        if (used[i])
            continue;
        result[a] = input[i];
        used[i] = true;
        dfs(a + 1);
        used[i] = false;
        while (input[i] == input[i + 1] && i < len - 1)
            i ++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n --)
    {
        scanf("%s", input);
        len = strlen(input);
        qsort(input, len, sizeof(char), cmp);
        memset(used, 0, sizeof(used));
        memset(result, 0, sizeof(result));
        dfs(0);
    }
    return 0;
}
