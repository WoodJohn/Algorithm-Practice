/*
POJ 2046
BFS + hash判重
这题会告诉你，STL是有多慢。无论是string还是queue都是如此
*/


#include <iostream>
#include <string.h>
#include <string>
#include <queue>
#include <set>
#include <vector>
#define N 1000007
using namespace std;

struct nn
{
    char s[32];
    int depth;
};

int n;
queue<nn> q;
//set<string> sets;
char ht[N][32];
char FINAL[32];

void print(char *s)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << (int)s[i * 8 + j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

inline int cmp(char *a, char *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            return 1;
    }
    return 0;
}

inline void cpy(char *a, char *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

inline int hashKey(char *s)
{
    int sum = 0;
    for (int i = 0; i < 32; i++)
    {
       sum = sum * 7 + s[i];
    }
    return ((sum & 0x7FFFFFFF) % N);
}

inline bool found(char *s)
{
    int key = hashKey(s);
    while (ht[key][0] != 0 && cmp(ht[key], s, 32) != 0)
    {
        key += 7;
        if (key >= N)
            key %= N;
    }
    if (cmp(ht[key], s, 32) == 0)
        return true;
    return false;
}

inline void insertHT(char *s)
{
    int key = hashKey(s);
    while (ht[key][0] != 0)
    {
        key += 7;
        if (key >= N)
            key %= N;
    }
    cpy(ht[key], s, 32);
}
int count = 0;
inline void bfs()
{
    while (!q.empty())
    {
        nn t = q.front();
        q.pop();
        if (cmp(t.s, FINAL, 32) == 0)
        {
            cout << t.depth << endl;
            return;
        }
//        cout << t.depth << count++ << endl;
//        if (count == 28)
//        {
//            cout << "haha" << endl;
//        }
        int startPos = 0;
        for (int i = 0; i < 4; i++)
        {
            char tt[32];
            cpy(tt, t.s, 32);
            //print(tt);
            int pos;
            for (pos = startPos; tt[pos] != 99; pos ++);
            int posp = pos - 1;
            if (tt[posp] != 99 && tt[posp] % 10 != 7)
            {
                char temp = tt[posp];
                temp++;
                int postemp;
                for (postemp = 0; tt[postemp] != temp; postemp++);
                tt[pos] = tt[postemp];
                tt[postemp] = 99;
               // print(tt);
                if (!found(tt))
                {
                    nn ttt;
                    cpy(ttt.s, tt, 32);
                    ttt.depth = t.depth + 1;
                    insertHT(tt);
                    q.push(ttt);
                }
            }
            startPos = pos + 1;
        }
    }
    cout << -1 << endl;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            FINAL[8 * i + j] = 10 * (i + 1) + j + 1;
        }
        FINAL[8 * i + 7] = 99;
    }
    cin >> n;
    while (n--)
    {
        while (!q.empty())
        {
            q.pop();
        }
        memset(ht, 0, sizeof(ht));
        char cur[32];
        for (int i = 0; i < 4; i++)
        {
            cur[8 * i] = 99;
            for (int j = 1; j <= 7; j++)
            {
                int t;
                cin >> t;
                cur[8 * i + j] = t;
            }
        }
        for (int i = 0; i < 4; i ++)
        {
            for (int j = 0; j < 32; j++)
            {
                if (cur[j] == 10 * (i + 1) + 1)
                {
                    cur[8 * i] = cur[j];
                    cur[j] = 99;
                    break;
                }
            }
        }
        nn init;
        cpy(init.s, cur, 32);
        init.depth = 0;
        q.push(init);
        insertHT(cur);
        //sets.insert(cur);
        bfs();
    }
    return 0;
}
