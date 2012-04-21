/*
POJ 1001
高精度浮点数求幂
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string result;

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
    string a;
    while (cin >> a)
    {
        int times;
        int posofdot = a.find(".");
        if (posofdot == -1)
            posofdot = 0;
        else
            posofdot = a.size() - posofdot - 1;
        cin >> times;
        posofdot *= times;
        string temp = "";
        result = "";
        int len = a.size();
        for (int i = 0 ; i < len ; i ++)
        {
            if (a[i] != '.')
            {
                temp = temp + a[i];
            }
        }
        while (temp[0] == '0')
        {
            int s = temp.size();
            temp = temp.substr(1, s - 1);
        }
        result = temp;
        times --;
        while (times --)
        {
            result = mul(result, temp);
        }
        int ss = result.size();
        if (posofdot == 0 || result == "")
        {
            if (result == "")
            {
                cout << '0' << endl;
            }
            else
            {
                cout << result << endl;
            }
        }
        else if (posofdot >= ss)
        {
            cout << '.';
            for (int k = 0 ; k < posofdot - ss ; k ++)
            {
                cout << '0';
            }
            int pos = ss - 1;
            while (result[pos] == '0')
            {
                pos --;
                result = result.substr(0, result.size() - 1);
            }
            if (result == "")
            {
                cout << 0 << endl;
            }
            else
            {
                cout << result << endl;
            }
        }
        else
        {
            int k;
            for (k = 0 ; k < ss - posofdot ; k ++)
            {
                cout << result[k];
            }
            int pos = ss - 1;
            while (result[pos] == '0' && pos >= k)
            {
                pos --;
                result = result.substr(0, result.size() - 1);
                ss --;
                posofdot --;
            }
            if (result.size() == k)
            {
                cout << endl;
            }
            else
            {
                cout << '.';
                for (k = ss - posofdot; k < ss; k ++)
                {
                    cout << result[k];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
