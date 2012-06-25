#include <iostream>
#include <string.h>
using namespace std;

bool arr[102][102];

int get(int a, int b, int l)
{
    int i,j;
    int sum = 0;
    for (i = a; i < a + l ; i++)
    {
        for (j = b; j < b + l; j++)
        {
            if (arr[i][j])
                sum++;
        }
    }
    return sum;
}

void set(int a, int b, int l, bool v)
{
    int i,j;
    for (i = a; i < a + l ; i++)
    {
        for (j = b; j < b + l; j++)
        {
            arr[i][j] = v;
        }
    }
}

int main()
{
    char s[10];
    int a, b, l;
    int n;
    cin >> n;
    memset(arr, 0, sizeof(arr));
    while (n--)
    {
        cin >> s >> a >> b >> l;
        if (strcmp(s, "TEST") == 0)
        {
            cout << get(a, b, l) << endl;
        }
        else
        {
            set(a, b, l, (strcmp(s, "BLACK") == 0));
        }
    }
    return 0;
}
