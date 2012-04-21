#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int data[64];
bool used[64];
int n;
int num;
int len;

int cmp(const void *a, const void *b)
{
    int p = *((int *)a);
    int q = *((int *)b);
    return q - p;
}

bool dfs(int a, int start, int total)
{
    if (total == num)
    {
        return true;
    }
    for (int i = start; i < n; i ++)
    {
        if (used[i] || a < data[i])
            continue;
        used[i] = true;
        if (a == data[i])
        {
            if (dfs(len, 1, total + 1))
                return true;
            used[i] = false;
            break;
        }
        if (dfs(a - data[i], i + 1, total))
            return true;
        used[i] = false;
        if (a == len || i == n - 1)
            return false;
        while (data[i] == data[i + 1] && i < n - 1)
            i ++;
    }
    return false;
}

int main()
{
    while(scanf("%d", &n))
    {
        if (n == 0)
            break;
        int max = 0;
        int sum = 0;
        memset(data, 0, n * sizeof(int));
        for (int i = 0; i < n; i ++)
        {
            scanf("%d", &data[i]);
            if (data[i] > max)
                max = data[i];
            sum += data[i];
        }
        qsort(data, n, sizeof(int), cmp);
        for (len = max; len <= sum; len ++)
        {
            if (sum % len == 0)
            {
                num = sum / len;
                memset(used, 0, sizeof(used));
                if(dfs(len, 0, 0))
                {
                    printf("%d\n", len);
                    break;
                }
            }
        }
    }
    return 0;
}
