#include <stdio.h>
#include <string.h>
using namespace std;

int n;
int pos[10];

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        memset(pos, -1, sizeof(pos));
        int a = 0;
        int b = 0;
        char stra[5];
        char strb[5];
        scanf("%s %s", stra, strb);
        for (int i = 0; i < 4; i++)
        {
            pos[stra[i] - '0'] = i;
        }
        for (int i = 0; i < 4; i++)
        {
            if (pos[strb[i] - '0'] != -1)
            {
                if (pos[strb[i] - '0'] == i)
                    a++;
                else
                    b++;
            }
        }
        printf("%dA%dB\n", a, b);
    }
    return 0;
}
