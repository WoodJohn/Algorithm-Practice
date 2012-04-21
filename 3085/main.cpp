#include <stdio.h>

using namespace std;

int n, quar, dime, nick, penn;
int t;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        quar = t / 25;
        t %= 25;
        dime = t / 10;
        t %= 10;
        nick = t / 5;
        t %= 5;
        penn = t;
        printf ("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", i + 1, quar, dime, nick, penn);
    }
    return 0;
}
