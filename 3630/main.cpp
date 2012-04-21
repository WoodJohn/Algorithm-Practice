/*
POJ 3630
静态Trie树
本题不难，但是是一道很好的Trie数扩展。题意为对于给定的一组数字，问是否存在其中一个是另一个的前缀。
最简单的办法是快排后两两对比（O(NlogN + N) = O(NlogN)），但是太慢（实测1000ms AC -_-!），因此考虑Trie树
算法如下：
1.不需要排序
2.对于一个新的输入串，插入树中时：
    1）若为第一个串，则正常插入
    2）否则，在数据结构中对每个结点的子节点个数计数。若之前插入路径上的每一个点的子节点个数都大于0而当前插入点没有子节点，则表示当前插入
        的串以之前插入的某个串为前缀
    3）若完成2）的插入后发现所经过路径的每一个点子节点数都大于0，则表示当前插入串为某些串的前缀
用动态Trie树发现超时，因此改用静态树组来存储结点，注意新建结点时的初始化即可。得到的教训：new函数是非常缓慢的。。
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
