#include <stdio.h>
#include <stdlib.h>

#define N 32767

struct nn
{
    int x;
    int y;
    nn *next;
} points[N];

int data[2001][2];

void insert(int x, int y)
{
    int index = (x * x + y * y) % N;
    nn *node = &points[index];
    while (node->next != NULL)
        node = node->next;
    nn *t = new nn;
    t->x = x;
    t->y = y;
    t->next = NULL;
    node->next = t;
}

bool find(int x, int y)
{
    int index = (x * x + y * y) % N;
    nn *node = &points[index];
    while (node != NULL)
    {
        if (node->x == x && node->y == y)
            return true;
        node = node->next;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < N; i ++)
    {
        points[i].x = 20001;
        points[i].y = 20001;
        points[i].next = NULL;
    }
    int sum = 0;
    for (int i = 0; i < n; i ++)
    {
        scanf("%d %d", &data[i][0], &data[i][1]);
        insert(data[i][0], data[i][1]);
    }
    for (int i = 0; i < n - 1; i ++)
    {
        for (int j = i + 1; j < n; j ++)
        {
            int x1 = data[i][0];
            int y1 = data[i][1];
            int x2 = data[j][0];
            int y2 = data[j][1];
            if ((x1 + x2 + y1 + y2) % 2 == 0)
            {
                int x3 = (x1 + x2 + y1 - y2) / 2;
                int y3 = (y1 + y2 + x2 - x1) / 2;
                if (find(x3, y3))
                {
                    int x4 = (x1 + x2 - y1 + y2) / 2;
                    int y4 = (y1 + y2 + x1 - x2) / 2;
                    if (find(x4, y4))
                        sum ++;
                }
            }
        }
    }
    printf("%d\n", sum / 2);
    return 0;
}
