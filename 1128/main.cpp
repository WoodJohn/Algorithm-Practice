#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char data[31][31];
char result[10000][27];
char cache[27];
bool have[26];

int sx[26], sy[26], bx[26], by[26];
int count, h, w;
int resultcount;

char list[27];

bool used[26];

int cmp(const void *a, const void *b)
{
    char *p = (char *)a;
    char *q = (char *)b;
    return strcmp(p, q);
}

bool isSquare(int sx, int sy, int bx, int by, char c)
{
    for (int i = sy; i <= by; i ++)
    {
        if (data[i][sx] != c && data[i][sx] != '.')
            return false;
        if (data[i][bx] != c && data[i][bx] != '.')
            return false;
    }
    for (int i = sx; i <= bx; i ++)
    {
        if (data[sy][i] != c && data[sy][i] != '.')
            return false;
        if (data[by][i] != c && data[by][i] != '.')
            return false;
    }
    return true;
}

void find(int a)
{
    char temp[31][31];
    if (a == count)
    {
        strcpy(result[resultcount ++], cache);
        return;
    }
    for (int i = 0; i < count; i ++)
    {
        int c = list[i] - 'A';
        if (used[c])
            continue;
        if (isSquare(sx[c], sy[c], bx[c], by[c], list[i]))
        {
            for (int j = 0; j < h; j ++)
                for (int k = 0; k < w; k ++)
                {
                    temp[j][k] = data[j][k];
                    if (data[j][k] == list[i])
                    {
                        data[j][k] = '.';
                    }
                }
            cache[count - 1 - a] = list[i];
            used[c] = true;
            find(a + 1);
            for (int j = 0; j < h; j ++)
                for (int k = 0; k < w; k ++)
                {
                    data[j][k] = temp[j][k];
                }
            used[c] = false;
        }
    }
}

int main()
{
    while (scanf("%d %d", &h, &w) != EOF)
    {
        count = 0;
        resultcount = 0;
        memset(list, 0, sizeof(list));
        memset(cache, 0, sizeof(cache));
        memset(result, 0, sizeof(result));
        memset(data, 0, sizeof(data));
        for (int i = 0; i < 26; i ++)
        {
            sx[i] = sy[i] = 100;
            bx[i] = by[i] = -1;
            have[i] = false;
            used[i] = false;
        }
        for (int i = 0; i < h; i ++)
        {
            scanf("%s", data[i]);
            for (int j = 0; j < w; j ++)
            {
                if (data[i][j] != '.')
                {
                    if (!have[data[i][j] - 'A'])
                    {
                        list[count ++] = data[i][j];
                        have[data[i][j] - 'A'] = true;
                    }
                    if (i < sy[data[i][j] - 'A'])
                    {
                        sy[data[i][j] - 'A'] = i;
                    }
                    if (j < sx[data[i][j] - 'A'])
                    {
                        sx[data[i][j] - 'A'] = j;
                    }
                    if (i > by[data[i][j] - 'A'])
                    {
                        by[data[i][j] - 'A'] = i;
                    }
                    if (j > bx[data[i][j] - 'A'])
                    {
                        bx[data[i][j] - 'A'] = j;
                    }
                }
            }
        }
        find(0);
        qsort(result, resultcount, 27 * sizeof(char), cmp);
        for (int i = 0; i < resultcount; i ++)
        {
            printf("%s\n", result[i]);
        }
    }
    return 0;
}
