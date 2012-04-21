/*
POJ 1816
字符串的模式匹配
给出一组带有单字通配符？和任意长度通配符*的字符串模式，对于给出的一系列word，求它们能匹配上的所有模式
trie树 + DFS
要点：
1.建树。trie树的建立比较简单
2.搜索策略。对于当前字符和？的搜索都比较简单。对于*则要枚举其长度来搜索，需要注意：
    1）由于*可以匹配空串，因此需要从当前位置（而不是+1）开始搜索
    2）即使当前位置已经到达目标word的结尾，也不要停止！这是因为还可能匹配到末尾是*的模式（如a可以匹配a*和a**）
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

struct node
{
    node *next[28];
    vector<int> ids;
    node()
    {
        ids.clear();
        for (int i = 0; i < 28; i++)
        {
            next[i] = NULL;
        }
    }
};

struct pair
{
    int n1;
    int n2;
};

int m, n, i;
vector<int> result[105];
node *root;

inline int char2num(char c)
{
    if (c == '?')
        return 26;
    if (c == '*')
        return 27;
    return c - 'a';
}

void insert(node *r, char *pattern, int id)
{
    int j;
    node *curNode = r;
    int len = strlen(pattern);
    for (j = 0; j < len; j++)
    {
        int num = char2num(pattern[j]);
        if (curNode->next[num] == NULL)
            curNode->next[num] = new node();
        curNode = curNode->next[num];
    }
    curNode->ids.push_back(id);
}

void addNode2Result(node *curNode, int index)
{
    int j;
    for (j = 0; j < curNode->ids.size(); j++)
    {
        result[index].push_back(curNode->ids[j]);
    }
}

void dfs(node *curNode, int curPos, char *word)
{
    int len = strlen(word);
    if (len == curPos)
    {
        if (len < curPos)
            return;
        if (curNode->ids.size() != 0)
            addNode2Result(curNode, i);
    }
    if (len > curPos)
    {
        int num = char2num(word[curPos]);
        if (curNode->next[num])
        {
            dfs(curNode->next[num], curPos + 1, word);
        }
        if (curNode->next[26])
        {
            dfs(curNode->next[26], curPos + 1, word);
        }
    }
    if (curNode->next[27])
    {
        int j;
        for (j = curPos; j <= len; j++)
        {
            dfs(curNode->next[27], j, word);
        }
    }
}

int main()
{
    char str[25];
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        result[i].clear();
    }
    root = new node();
    for (i = 0; i < n; i++)
    {
        scanf("%s", str);
        insert(root, str, i);
    }
    int j;
    for (i = 0; i < m; i++)
    {
        scanf("%s", str);
        dfs(root, 0, str);
        if (result[i].size() > 0)
        {
            sort(result[i].begin(), result[i].end(), less<int>());
            for (j = 0; j < result[i].size() - 1; j++)
            {
                if (result[i][j] != result[i][j + 1])
                    cout << result[i][j] << ' ';
            }
            cout << result[i][result[i].size() - 1] << endl;
        }
        else
            cout << "Not match" << endl;
    }
    return 0;
}
