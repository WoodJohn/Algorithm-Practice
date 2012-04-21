/*
POJ 3630
��̬Trie��
���ⲻ�ѣ�������һ���ܺõ�Trie����չ������Ϊ���ڸ�����һ�����֣����Ƿ��������һ������һ����ǰ׺��
��򵥵İ취�ǿ��ź������Աȣ�O(NlogN + N) = O(NlogN)��������̫����ʵ��1000ms AC -_-!������˿���Trie��
�㷨���£�
1.����Ҫ����
2.����һ���µ����봮����������ʱ��
    1����Ϊ��һ����������������
    2�����������ݽṹ�ж�ÿ�������ӽڵ������������֮ǰ����·���ϵ�ÿһ������ӽڵ����������0����ǰ�����û���ӽڵ㣬���ʾ��ǰ����
        �Ĵ���֮ǰ�����ĳ����Ϊǰ׺
    3�������2���Ĳ������������·����ÿһ�����ӽڵ���������0�����ʾ��ǰ���봮ΪĳЩ����ǰ׺
�ö�̬Trie�����ֳ�ʱ����˸��þ�̬�������洢��㣬ע���½����ʱ�ĳ�ʼ�����ɡ��õ��Ľ�ѵ��new�����Ƿǳ������ġ���
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct node
{
    node *next[10];
    int cnt;
    node()
    {
        cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            next[i] = NULL;
        }
    }
}trie[1 << 16];

int t, n, nodecnt;

bool check;

void insert(char *s, int pos)
{
    node *curNode = &trie[0];
    int i;
    int len = strlen(s);
    bool flag = true;
    for (i = 0; i < len; i++)
    {
        int index = s[i] - '0';
        if (curNode->next[index] == NULL)
        {
            if (curNode->cnt == 0 && pos > 0 && flag)
            {
                check = false;
                return;
            }
            flag = false;
            curNode->next[index] = &trie[nodecnt];
            trie[nodecnt].cnt = 0;
            memset(trie[nodecnt].next, NULL, sizeof(trie[nodecnt].next));
            nodecnt++;
            curNode->cnt++;
        }
        curNode = curNode->next[index];
    }
    if (flag)
        check = false;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        check = true;
        scanf("%d", &n);
        trie[0].cnt = 0;
        int i;
        memset(trie[0].next, NULL, sizeof(trie[0].next));
        nodecnt = 1;
        for (i = 0; i < n; i++)
        {
            char str[12];
            scanf("%s", str);
            if (check)
                insert(str, i);
        }
        if (!check)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
