/*
POJ 1816
�ַ�����ģʽƥ��
����һ����е���ͨ����������ⳤ��ͨ���*���ַ���ģʽ�����ڸ�����һϵ��word����������ƥ���ϵ�����ģʽ
trie�� + DFS
Ҫ�㣺
1.������trie���Ľ����Ƚϼ�
2.�������ԡ����ڵ�ǰ�ַ��ͣ����������Ƚϼ򵥡�����*��Ҫö���䳤������������Ҫע�⣺
    1������*����ƥ��մ��������Ҫ�ӵ�ǰλ�ã�������+1����ʼ����
    2����ʹ��ǰλ���Ѿ�����Ŀ��word�Ľ�β��Ҳ��Ҫֹͣ��������Ϊ������ƥ�䵽ĩβ��*��ģʽ����a����ƥ��a*��a**��
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
