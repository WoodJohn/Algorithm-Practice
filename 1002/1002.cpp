/*
POJ 1002
STL Map ¥Ê¥¢”≥…‰
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

map<int ,int> mapping;
char code[] = "ABCDEFGHIJKLMNOPRSTUVWXY";
char value[] = "222333444555666777888999";

int main()
{
    int n;
    scanf("%d", &n);
    while (n --)
    {
        char s[200];
        scanf("%s", s);
        int number = 0;
        for (int i = 0 ; i < strlen(s) ; i ++)
        {
            if (s[i] == '-')
                continue;
            else if (s[i] >= '0' && s[i] <= '9')
            {
                number = number * 10 + s[i] - '0';
            }
            else
            {
                int pos = strchr(code, s[i]) - code;
                number = number * 10 + value[pos] - '0';
            }
        }
        map<int, int>::iterator i;
        i = mapping.find(number);
        if (i != mapping.end())
        {
            i->second = i->second + 1;
        }
        else
        {
            mapping.insert(pair<int, int>(number, 1));
        }
    }
    int check = 0;
    map<int, int>::iterator i;
    for (i = mapping.begin(); i != mapping.end(); i ++)
    if (i->second > 1)
    {
        check ++;
        printf("%03d-%04d %d\n", i->first / 10000, i->first % 10000, i->second);
    }
    if (check == 0)
        printf("No duplicates.\n");
    return 0;
}
