#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const char ori[27] = "abcdefghijklmnopqrstuvwxyz";
const char tra[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    ofstream fout;
    fout.open("out.out", ios::out);
    int n;
    cin >> n;
    getchar();
    int i;
    for (i = 1; i <= n; i++)
    {
        char str[110];
        gets(str);
        int len = strlen(str);
        int j;
        for (j = 0; j < len; j++)
        {
            if (str[j] == ' ')
                continue;
            str[j] = tra[str[j] - 'a'];
        }
        fout << "Case #" << i << ": " << str << endl;
    }
    return 0;
}
