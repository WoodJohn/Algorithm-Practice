#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

char result[20][102];
vector<int> on;
vector<int> off;

int data[101];

int resultcount = 0;
int count;
int n;

int cmp(const void *a, const void *b)
{
    char *p = (char *)a;
    char *q = (char *)b;
    return strcmp(p, q);
}

bool checkon()
{
    for (int i = 0; i < on.size(); i ++)
    {
        if (data[on[i] - 1] != 1)
            return false;
    }
    return true;
}

bool checkoff()
{
    for (int i = 0; i < off.size(); i ++)
    {
        if (data[off[i] - 1] != 0)
            return false;
    }
    return true;
}

void op1()
{
    for (int i = 0; i < n; i ++)
        data[i] = (data[i] + 1) % 2;
}

void op2()
{
    for (int i = 0; i < n; i += 2)
        data[i] = (data[i] + 1) % 2;
}

void op3()
{
    for (int i = 1; i < n; i += 2)
        data[i] = (data[i] + 1) % 2;
}

void op4()
{
    for (int i = 0; i < n; i += 3)
        data[i] = (data[i] + 1) % 2;
}

void dfs(int a)
{
    if (a == 5 || count <= 0)
        return;
    for (int i = 0; i <= 1; i ++)
    {
        if (i > 0)
        {
            if (a == 1)
            {
                if (i % 2)
                {
                    op1();
                }
            }
            else if (a == 2)
            {
                if (i % 2)
                    op2();
            }
            else if (a == 3)
            {
                if (i % 2)
                {
                    op3();
                }
            }
            else
            {
                if (i % 2)
                {
                    op4();
                }
            }
        }
        count -= i;
        if (count % 2 == 0 && checkon() && checkoff())
        {
            char *temp = new char[n + 1];
            for (int j = 0; j < n; j ++)
                temp[j] = data[j] + '0';
            temp[n] = '\0';
            strcpy(result[resultcount ++], temp);
        }
        dfs(a + 1);
        count += i;
        if (i > 0)
        {
            if (a == 1)
            {
                if (i % 2)
                {
                    op1();
                }
            }
            else if (a == 2)
            {
                if (i % 2)
                {
                    op2();
                }
            }
            else if (a == 3)
            {
                if (i % 2)
                {
                    op3();
                }
            }
            else
            {
                if (i % 2)
                {
                    op4();
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &count);
    int a;
    for (int i = 0; i < n; i ++)
    {
        data[i] = 1;
    }
    while (scanf("%d", &a))
    {
        if (a == -1)
            break;
        on.push_back(a);
    }
    while (scanf("%d", &a))
    {
        if (a == -1)
            break;
        off.push_back(a);
    }
    dfs(1);
    qsort(result, resultcount, sizeof(char) * 102, cmp);
    for (int i = 0; i < resultcount; i ++)
    {
        while (i < resultcount - 1 && strcmp(result[i], result[i + 1]) == 0)
            i ++;
        printf("%s\n", result[i]);
    }
    return 0;
}
