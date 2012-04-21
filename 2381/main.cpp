#include <stdio.h>
#include <string.h>
using namespace std;


__int64 maxg;
bool *ht;
__int64 a, c, m, v;
__int64 maxnum, mMax;

int main()
{
    scanf("%I64d %I64d %I64d %I64d", &a, &c, &m, &v);
    ht = new bool[m + 1];
    memset(ht, 0, sizeof(bool) * (m + 1));
    maxnum =  v;
    mMax = 0;
    while (1)
    {
        if (ht[v])
        {
            for (int i = 0; i < maxnum; i++)
            {
                if (ht[i])
                {
                    for (int j = i + 1; j <= maxnum; j++)
                    {
                        if (ht[j])
                        {
                            if (j - i > mMax)
                            {
                                mMax = j - i;
                                i = j - 1;
                            }
                            break;
                        }
                    }
                }
            }
            printf("%I64d\n", mMax);
            break;
        }
        ht[v] = true;
        v = (a * v + c) % m;
        if (v > maxnum)
            maxnum = v;
    }
    return 0;
}
