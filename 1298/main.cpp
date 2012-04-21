#include <stdio.h>
#include <string.h>

using namespace std;

char data[202];
char a[50];

int main()
{
    while (scanf("%s", a))
    {
        if (strcmp(a, "ENDOFINPUT") == 0)
            break;
        getchar();
        gets(data);
        int l = strlen(data);
        for (int i = 0; i < l; i ++)
        {
            char c = data[i];
            if (c >= 'A' && c <= 'Z')
            {
                int t = c - 'A';
                t= (t + 21) % 26;
                data[i] = t + 'A';
            }
        }
        printf("%s\n", data);
        scanf("%s", a);
    }
    return 0;
}
