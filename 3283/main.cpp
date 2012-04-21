/*
Trie����������
Ҫ�㣺
1.�ж�����β��������ͷ�������ÿ��������Ҫ�Ӻ���ǰ����
2.��ά�ַ�ָ�봫�ε����⣨��Ҫ����
    1���������������char**����ô���޷�ͨ��[]����ȡָ������
    2���������������char*[]����ô��Ҫ���г�ʼ��ÿ��ָ�룬����Ĭ����NULL
    3�����ϣ�������õķ�ʽ�Ǳ�������Ϊchar[][]��������������Ϊchar (*s)[];
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct node
{
    node *next[52];
    node()
    {
        for (int i = 0; i < 52; i++)
        {
            next[i] = NULL;
        }
    }
};

int getIndex(char *s)
{
    int ret = 0;
    int len = strlen(s);
    if (s[len - 1] == 'C')
        ret += 0;
    else if (s[len - 1] == 'D')
        ret += 1;
    else if (s[len - 1] == 'H')
        ret += 2;
    else
        ret += 3;
    ret *= 13;
    if (len == 3)
        return ret + 9;
    if (s[0] <= '9' && s[0] >= '2')
        return ret + s[0] - '0' - 1;
    if (s[0] == 'A')
        return ret;
    if (s[0] == 'J')
        return ret + 10;
    if (s[0] == 'Q')
        return ret + 11;
    if (s[0] == 'K')
        return ret + 12;
    return -1;
}

node *root;
int cnt;
int n, m;
char ss[100001][5];

void insert(char (*s)[5], int len)
{
    int i;
    node *curNode = root;
    for (i = len - 1; i >= 0; i--)
    {
        char *str = *(s + i);
        int index = getIndex(str);
        if (curNode->next[index] == NULL)
        {
            curNode->next[index] = new node();
            cnt++;
        }
        curNode = curNode->next[index];
    }
}

int main()
{
    int i;
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        root = new node();
        cnt = 0;
        while (n--)
        {
            scanf("%d", &m);
            for (i = 0; i < m; i++)
            {
                scanf("%s", ss[i]);
            }
            insert(ss, m);
        }
        printf("%d\n", cnt);
    }
    return 0;
}
