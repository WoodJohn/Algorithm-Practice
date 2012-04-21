#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nn
{
    int number;
    int time;
    int solved;
} teams[1001];

struct nnn
{
    int c;
    int p;
    int t;
    int r;
} input[1001];

int cmp(const void *a, const void *b)
{
    nn p = *((nn *)a);
    nn q = *((nn *)b);
    if (p.solved == q.solved)
    {
        if (p.time == q.time)
        {
            return p.number - q.number;
        }
        return p.time - q.time;
    }
    return q.solved - p.solved;
}

int cmp2(const void *a, const void *b)
{
    nnn p = *((nnn *)a);
    nnn q = *((nnn *)b);
    return p.t - q.t;
}

bool solve[1001][21] = {false};
int time[1001][21] = {0};
int actime[1001][21];

int main()
{
    int c,n;
    scanf("%d %d", &c, &n);
    teams[0].number = 100000;
    teams[0].solved = 0;
    teams[0].time = 36000001;
    memset(actime, -1, sizeof(actime));
    for (int i = 1; i <= c; i ++)
    {
        teams[i].number = i;
        teams[i].time = 0;
        teams[i].solved = 0;
    }
    for (int i = 0; i < n; i ++)
    {
        scanf("%d %d %d %d", &input[i].c, &input[i].p, &input[i].t, &input[i].r);
    }
    qsort(input, n, sizeof(nnn), cmp2);
    for (int i = 0; i < n ; i ++)
    {
        int cc = input[i].c;
        int p = input[i].p;
        int t = input[i].t;
        int r = input[i].r;
        if (solve[cc][p])
        {
            continue;
        }
        if (r == 0)
        {
            time[cc][p] += 1200;
        }
        else
        {
            time[cc][p] += t;
            teams[cc].time += time[cc][p];
            teams[cc].solved ++;
            solve[cc][p] = true;
        }
    }
    qsort(teams, c + 1, sizeof(nn), cmp);
    for (int i = 0; i < c; i ++)
    {
        printf("%d", teams[i].number);
        if (i < c - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
