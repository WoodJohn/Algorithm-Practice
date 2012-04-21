#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nn
{
    char word[22];
    int index;
    char prefix[22];
} words[1001];

char result[22];

int cmp(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    return strcmp(p.word, q.word);
}

int cmpi(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    return p.index - q.index;
}

char *prefix(char *a, char *b)
{

    int l = strlen(a);
    int i = 0;
    while (a[i] == b[i] && i < l)
        i ++;
    strncpy(result, a, i);
    result[i] = '\0';
    return result;
}

int main()
{
    char word[22];
    int count = 0;
    while (scanf("%s", word) != EOF)
    {
        if (strlen(word) > 0)
        {
            strcpy(words[count].word, word);
            words[count].index = count;
            count ++;
        }
    }
    qsort(words, count, sizeof(nn), cmp);
    for (int i = 0; i < count; i ++)
    {
        if (i == 0)
        {
            char pre[22];
            strcpy(pre, prefix(words[i].word, words[i + 1].word));
            if (strcmp(pre, words[i].word) == 0)
                strcpy(words[i].prefix, pre);
            else
            {
                int pos = strlen(pre);
                pre[pos] = words[i].word[pos];
                pre[pos + 1] = '\0';
                strcpy(words[i].prefix, pre);
            }
        }
        else if (i < count - 1)
        {
            char pre1[22], pre2[22];
            strcpy(pre1, prefix(words[i - 1].word, words[i].word));
            strcpy(pre2, prefix(words[i].word, words[i + 1].word));
            if (strlen(pre1) > strlen(pre2))
            {
                if (strcmp(pre1, words[i].word) == 0)
                    strcpy(words[i].prefix, pre1);
                else
                {
                    int pos = strlen(pre1);
                    pre1[pos] = words[i].word[pos];
                    pre1[pos + 1] = '\0';
                    strcpy(words[i].prefix, pre1);
                }
            }
            else
            {
                if (strcmp(pre2, words[i].word) == 0)
                    strcpy(words[i].prefix, pre2);
                else
                {
                    int pos = strlen(pre2);
                    pre2[pos] = words[i].word[pos];
                    pre2[pos + 1] = '\0';
                    strcpy(words[i].prefix, pre2);
                }
            }
        }
        else
        {
            char pre[22];
            strcpy(pre, prefix(words[i].word, words[i - 1].word));
            if (strcmp(pre, words[i].word) == 0)
                strcpy(words[i].prefix, pre);
            else
            {
                int pos = strlen(pre);
                pre[pos] = words[i].word[pos];
                pre[pos + 1] = '\0';
                strcpy(words[i].prefix, pre);
            }
        }
    }
    qsort(words, count, sizeof(nn), cmpi);
    for (int i = 0; i < count; i ++)
    {
        printf("%s %s\n", words[i].word, words[i].prefix);
    }
    return 0;
}
