#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int g[6001][6001] = {0};
int color[6001] = {WHITE};
int d[6001] = {0};
char s[256],t[256];
char word[256];
char words[6001][256];
int count = 0;
int is,it;
bool check1 = false, check2 = false;

bool similar(char* a, char* b)
{
    int t = 0;
    int la = strlen(a);
    for (int i = 0; i < la; i ++)
    {
        if (a[i] != b[i])
        {
            if (t == 0)
                t ++;
            else
                return false;
        }
    }
    if (t == 1) return true;
    return false;
}

int main()
{
    scanf("%s", s);
    scanf("%s", t);
    if (strcmp(s, t) == 0)
    {
        check1 = true;
    }
    int len = strlen(s);
    if (len != strlen(t))
    {
        check2 = true;
    }
    while (scanf("%s", word) != EOF)
    {
        if (strlen(word) == len)
        {
            strcpy(words[count ++], word);
        }
    }
    if (check1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (check2)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < count; i ++)
    {
        for (int j = i + 1; j < count; j ++)
        {
            if (strcmp(s, words[i]) == 0)
                is = i;
            else if (strcmp(words[i], t) == 0)
                it = i;
            if (similar(words[i], words[j]))
            {
                g[i][0] ++;
                g[i][g[i][0]] = j;
                g[j][0] ++;
                g[j][g[j][0]] = i;
            }
        }
    }
    int sum = 1;
    queue<int> q;
    color[is] = GRAY;
    q.push(is);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 1; i <= g[t][0]; i ++)
        {
            int j = g[t][i];
            if (color[j] == WHITE)
            {
                color[j] = GRAY;
                d[j] = d[t] + 1;
                if (j == it)
                {
                    cout << d[j] + 1 << endl;
                    return 0;
                }
                else
                {
                    q.push(j);
                }
            }
        }
        color[t] = BLACK;
    }
    cout << -1 << endl;
    return 0;
}
