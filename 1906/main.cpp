#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string dtob(__int64 n)
{
    __int64 t = n;;
    string res = "";
    while(t > 0)
    {
        res = res + char(t % 2 + '0');
        t /= 2;
    }
    return res;
}

string mul(string a, string b)
{
    string res = "";
    int len_a = a.size();
    int len_b = b.size();
    for (int k = 0 ; k < len_a + len_b ; k ++)
    {
        res += "0";
    }

    for (int i = len_b - 1; i >= 0 ; i --)
    {
        for (int j = len_a - 1; j >= 0 ; j --)
        {
            int numtoadd = (a[j] - '0') * (b[i] - '0');
            res[i + j + 1] += (numtoadd % 10);
            if (res[i + j + 1] > '9')
            {
                res[i + j + 1] -= 10;
                res[i + j] ++;
            }
            res[i + j] += (numtoadd / 10);
            if (res[i + j] > '9')
            {
                res[i + j] -= 10;
                res[i + j - 1] ++;
            }
        }
    }
    if (res[0] == '0')
    {
        res = res.substr(1, len_a + len_b - 1);
    }
    return res;
}

int main()
{
    string result[66];
    result[0] = "1";
    __int64 n;
    for (int i = 1; i < 66; i ++)
    {
        result[i] = mul(result[i - 1], "3");
    }
    while (scanf("%I64d", &n))
    {
        if (n == 0)
        {
            break;
        }
        printf("{");
        string s = dtob(n - 1);
        int len = s.size();
        bool check = false;
        for (int i = 0; i < len; i ++)
        {
            if (s[i] != '0')
            {
                if (check)
                {
                    printf(",");
                }
                check = true;
                printf(" %s", result[i].c_str());
            }
        }
        printf(" }\n");
    }
    return 0;
}
