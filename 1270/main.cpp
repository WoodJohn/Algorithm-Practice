#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

char input[102];

vector<int> graph[27];
vector<char> cache;
bool used[27];
int refcount[27];
char result[22];

void dfs(int a)
{
    if (a == cache.size())
    {
        result[a] = '\0';
        printf("%s\n", result);
        return;
    }
    int s = cache.size();
    for (int i = 0 ; i < s; i ++)
    {
        if (used[cache[i] - 'a'])
            continue;
        char c = cache[i];
        if (refcount[c - 'a'] == 0)
        {
            used[c - 'a'] = true;
            for (int j = 0; j < graph[c - 'a'].size(); j ++)
            {
                refcount[graph[c - 'a'][j]] --;
            }
            result[a] = c;
            dfs(a + 1);
            used[c - 'a'] = false;
            for (int j = 0; j < graph[c - 'a'].size(); j ++)
            {
                refcount[graph[c - 'a'][j]] ++;
            }
        }
    }
}

int main()
{
    while (gets(input))
    {
        memset(used, 0, sizeof(used));
        memset(refcount, 0, sizeof(refcount));
        cache.clear();
        int l = strlen(input);
        for (int i = 0; i < l; i += 2)
        {
            graph[input[i] - 'a'].clear();
            cache.push_back(input[i]);
        }
        sort(cache.begin(), cache.end(), less<int>());
        gets(input);
        l = strlen(input);
        for (int i = 0; i < l; i += 4)
        {
            char a = *(input + i);
            char b = *(input + i + 2);
            graph[a - 'a'].push_back(b - 'a');
            refcount[b - 'a'] ++;
        }
        dfs(0);
        printf("\n");
    }
    return 0;
}
