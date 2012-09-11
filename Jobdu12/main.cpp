#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[15];
bool used[15];
char tmp[15];
int l;

int inline getIndex(char a)
{
    if (a <= 'Z' && a >= 'A')
        return a - 'A';
    else
        return a - 'a' + 26;
}

void dfs(int a)
{
    if (a == l)
    {
        tmp[l] = '\0';
        printf("%s\n", tmp);
        return;
    }
    bool v[53] = {false};
    for (int i = 0; i < l; i++)
    {
        if (!v[getIndex(str[i])] && !used[i])
        {
            v[getIndex(str[i])] = true;
            tmp[a] = str[i];
            used[i] = true;
            dfs(a + 1);
            used[i] = false;
        }
    }
}

int main()
{
    while (scanf("%s", str) != EOF)
    {
        //memset(used, 0, sizeof(used));
        l = strlen(str);
        sort(str, str + l, less<char>());
        dfs(0);
    }
    return 0;
}
