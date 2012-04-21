#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int val;
    int pos;
    int pay;
}ava[101];

int cmpval(const void *a, const void *b)
{
    node p = *((node *)a);
    node q = *((node *)b);
    if (p.val == q.val)
        return q.pos - p.pos;
    return p.val - q.val;
}

int cmppos(const void *a, const void *b)
{
    node p = *((node *)a);
    node q = *((node *)b);
    return p.pos - q.pos;
}

int n, p, cases;

int main()
{
    cin >> cases;
    while (cases--)
    {
        memset(ava, 0 , sizeof(ava));
        cin >> p >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> ava[i].val;
            ava[i].pos = i;
            sum += ava[i].val;
        }
        if (sum < p)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        qsort(ava, n, sizeof(node), cmpval);
        int pos = 0;
        sum = p;
        while (sum > 0 && pos < n)
        {
            if (double(sum) / (n - pos) <= ava[pos].val)
            {
                ava[pos].pay = sum / (n - pos);
                sum -= sum / (n - pos);
            }
            else
            {
                ava[pos].pay = ava[pos].val;
                sum -= ava[pos].val;
            }
            pos++;
        }
        qsort(ava, n, sizeof(node), cmppos);
        for (int i = 0; i < n; i++)
        {
            cout << ava[i].pay;
            if (i < n - 1)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
