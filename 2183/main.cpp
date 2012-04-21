#include <stdio.h>
#include <vector>
#define N 100007
using namespace std;

struct nn
{
    int v;
    int p;
};

vector<nn> ht[N];

int find(int k)
{
    int key = k % N;
    vector<nn> t = ht[key];
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i].v == k)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int count = 1;
    while (1)
    {
        if (n > 99999)
            n = (n % 100000) / 10;
        else if (n > 9999)
            n /= 10;
        else n = 0;
        n *= n;
        n %= 1000000;
        int temp = find(n);
        if (temp != -1)
        {
            printf("%d %d %d", n, count - ht[n % N][temp].p, count);
            break;
        }
        nn t;
        t.p = count++;
        t.v = n;
        ht[n % N].push_back(t);
    }
    return 0;
}
