#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int num[100001];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        int i, j;
        map<int, int> ht;
        scanf("%d%d", &n, &m);
        long long cnt = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            map<int, int>::iterator it = ht.find(num[i]);
            if (it == ht.end())
                ht.insert(pair<int, int>(num[i], 1));
            else
            {
                it->second++;
            }
        }
        for (i = 0; i < n; i++)
        {
            map<int, int>::iterator it = ht.find(m - num[i]);
            if (it == ht.end())
                continue;
            else
            {
                int t = it->second;
                if (num[i] == m - num[i])
                    cnt += t - 1;
                else
                    cnt += t;
            }
        }
        printf("%lld\n", cnt / 2);
    }
    return 0;
}
