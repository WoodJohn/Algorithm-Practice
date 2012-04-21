#include <map>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

int cmp(const void *a, const void *b)
{
    char *p = (char *)a;
    char *q = (char *)b;
    return strcmp(p, q);
}

char species[10001][31];

map<string, int> maps;

int main()
{
    char s[31];
    int count = 0;
    int scount = 0;
    while (gets(s) != NULL)
    {
        string str = s;
        count ++;
        map<string, int>::iterator i = maps.find(str);
        if (i == maps.end())
        {
            maps.insert(pair<string, int>(str, 1));
            strcpy(species[scount ++], s);
        }
        else
        {
            i->second ++;
        }
    }
    qsort(species, scount, 31 * sizeof(char), cmp);
    for (int i = 0; i < scount; i ++)
    {
        strcpy(s, species[i]);
        string str = s;
        printf("%s %.4f\n", s, 100 * double((maps.find(str))->second) / double(count));
    }
    return 0;
}
