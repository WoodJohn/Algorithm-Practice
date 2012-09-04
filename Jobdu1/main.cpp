#include <stdio.h>

int m, n;
int t;
int num[1005][1005];
bool check;

int findRow(int a)
{
    int l = 0;
    int r = m - 1;
    int mid = (l + r) / 2;
    while (l < r - 1)
    {
        if (num[mid][0] == t)
        {
            check = true;
            return mid;
        }
        if (num[mid][0] > t)
        {
            r = mid;
        }
        if (num[mid][0] < t)
        {
            l = mid;
        }
        if (l >= r - 1)
        {
            if (num[r][0] == t)
            {
                check = true;
                return r;
            }
            if (num[l][0] == t)
            {
                check = true;
                return l;
            }
        }
        mid = (l + r) / 2;
    }
    if (num[l][0] == t || num[r][0] == t)
    {
        check = true;
        return 1;
    }
    if (num[r][0] < t)
        return r;
    if (num[l][0] < t)
        return l;
    return -1;
}

int findCol(int a, int right)
{
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;
    while (l < r - 1)
    {
        if (num[right][mid] == t)
        {
            return mid;
        }
        if (num[right][mid] > t)
        {
            r = mid;
        }
        if (num[right][mid] < t)
        {
            l = mid;
        }
        if (l >= r - 1)
        {
            if (num[right][r] == t)
            {
                return r;
            }
            if (num[right][l] == t)
            {
                return l;
            }
        }
        mid = (l + r) / 2;
    }
    if (num[right][l] == t || num[right][r] == t)
        return 0;
    return -1;
}

int main()
{
    while (scanf("%d%d", &m, &n) != EOF)
    {
        check = false;
        scanf("%d", &t);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &num[i][j]);
            }
        }
        int r = findRow(t);
        if (r == -1)
        {
            printf("No\n");
            continue;
        }
        if (check)
        {
            printf("Yes\n");
            continue;
        }
        int c = findCol(t, r);
        if (c != -1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
