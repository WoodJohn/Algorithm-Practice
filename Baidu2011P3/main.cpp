#include <stdio.h>
#include <string.h>
#define MAX 99999999
using namespace std;

int min;
int n, k;
int id[11];
int t[11];
bool used[1000001];

bool subcheck(int a)
{
    for (int i = 0; i < n; i++)
    {
        if (a > id[i] && (a - id[i]) % t[i] == 0 && !used[(a - id[i]) / t[i]])
            return true;
    }
    return false;
}

bool check(int a)
{
    if (a < 0)
        return false;
    if (subcheck(a))
        return true;
    for (int i = 1; ; i++)
    {
        if (used[i])
            continue;
        for (int j = 0; j < n; j++)
        {
            used[i] = true;
            bool tt = check(a - (id[j] + i * t[j]));
            if (tt)
            {
                used[i] = false;
                return true;
            }
            used[i] = false;
        }
        return false;
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    min = MAX;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &id[i], &t[i]);
        if (id[i] + t[i] < min)
            min = id[i] + t[i];
    }
    memset(used, 0, sizeof(used));
    int count = 0;
    for (int i = min; ; i++)
    {
        if (check(i))
            count++;
        if (count == k)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
