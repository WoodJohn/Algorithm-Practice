#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char input[202];
int n;

int main()
{
    scanf("%s", input);
    n = strlen(input);
    sort(input, input + n);
    do
    {
        printf("%s\n", input);
    }
    while (next_permutation(input, input + n));
    return 0;
}
