#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

int cmp(const void *a, const void *b)
{
    char p = *((char *)a);
    char q = *((char *)b);
    return int(p - q);
}

int cmp2(const void *a, const void *b)
{
    string p = *((string *)a);
    string q = *((string *)b);
    if (p < q) return -1;
    return 1;
}

string str[101];
char s[101][256];
char t[256];

int main()
{
    int i = 0;
    while (cin >> str[i])
    {
        if (str[i] == "XXXXXX")
        {
            break;
        }
        i ++;
    }
    qsort(str, i, sizeof(string), cmp2);
    for (int j = 0; j < i; j ++)
    {
        strcpy(s[j], str[j].c_str());
        qsort(s[j], strlen(s[j]), sizeof(char), cmp);
    }
    string temp;
    while (cin >> temp)
    {
        if (temp == "XXXXXX")
        {
            break;
        }
        strcpy(t, temp.c_str());
        qsort(t, strlen(t), sizeof(char), cmp);
        bool check = 1;
        for (int j = 0; j < i; j ++)
        {
            if (strcmp(t, s[j]) == 0)
            {
                check = 0;
                cout << str[j] << endl;
            }
        }
        if (check)
        {
            cout << "NOT A VALID WORD" << endl;
        }
        cout << "******" << endl;
    }
    return 0;
}
