#include <iostream>
#include <stdio.h>
using namespace std;

int n;

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        int cnt[100] = {0};
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            ++cnt[a];
        }
        for (int i = 1; i < 100; i++)
        {
            if (cnt[i])
            {
                for (int j = 0; j < cnt[i]; j++)
                    printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}
