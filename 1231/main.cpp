#include <stdio.h>
#define INF 1000001
int maxx[27];
int maxy[27];
int minx[27];
int miny[27];
int containsx[27];
int containsy[27];
int k,p;

bool containx(int a, int b)
{
    return (minx[a] <= minx[b] && maxx[a] >= maxx[b]);
}

bool containy(int a, int b)
{
    return (miny[a] <= miny[b] && maxy[a] >= maxy[b]);
}

bool apartx(int a, int b)
{
    return (minx[a] > maxx[b] || minx[b] > maxx[a]);
}

bool aparty(int a, int b)
{
    return (miny[a] > maxy[b] || miny[b] > maxy[a]);
}

bool testx(int a, int b)
{
    return (maxx[a] < maxx[b] && maxx[a] >= minx[b]);
}

bool testy(int a, int b)
{
    return (maxy[a] < maxy[b] && maxy[a] >= miny[b]);
}

bool test()
{
    if (p == 1)
        return true;
    for (int i = 1; i <= k; i ++)
    {
        for (int j = 1; j <= k; j ++)
        {
            if (i == j)
                continue;
            if (containx(i, j))
            {
                if (containx(j, i) && maxx[i] - minx[i] > 0)
                    return false;
                containsx[i] ++;
                if (containsx[i] > 1)
                    return false;
            }
            if (containy(i, j))
            {
                if (containy(j, i) && maxy[i] - miny[i] > 0)
                    return false;
                containsy[i] ++;
                if (containsy[i] > 1)
                    return false;
            }
        }
    }
    for (int i = 1; i <= k; i ++)
    {
        for (int j = 1; j <= k; j ++)
        {
            if (i == j)
                continue;
            if (testx(i, j) && !containx(j, i) && !aparty(i, j))
                return false;
            if (testy(i, j) && !containy(j, i) && !apartx(i, j))
                return false;
        }
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --)
    {
        scanf("%d %d", &k, &p);
        for (int i = 1; i <= k; i ++)
        {
            maxx[i] = maxy[i] = 0;
            minx[i] = miny[i] = INF;
            containsx[i] = containsy[i] = 0;
        }
        for (int i = 1; i <= k; i ++)
        {
            int a,b;
            for (int j = 0; j < p; j ++)
            {
                scanf("%d %d", &a, &b);
                if (a > maxx[i])
                    maxx[i] = a;
                if (a < minx[i])
                    minx[i] = a;
                if (b > maxy[i])
                    maxy[i] = b;
                if (b < miny[i])
                    miny[i] = b;
            }
        }
        if (test())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
