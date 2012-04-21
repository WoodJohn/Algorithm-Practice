/*
Trie树基本题型
要点：
1.判定公共尾部而不是头部，因此每组数据需要从后往前插入
2.二维字符指针传参的问题（重要！）
    1）如果参数类型是char**，那么是无法通过[]来获取指定串的
    2）如果变量类型是char*[]，那么需要自行初始化每个指针，否则默认是NULL
    3）综上，本题采用的方式是变量定义为char[][]，函数参数类型为char (*s)[];
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
