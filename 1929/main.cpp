#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

float sumsum = 0.0;
float fattysum = 0.0;
float sum;
float per;
float fatty;

void cal(string s, int type)
{
    int res = 0;
    int l = s.size();
    for (int i = 0; i < l - 1; i ++)
    {
        res = 10 * res + s[i] - '0';
    }
    if (s[l - 1] == 'g')
    {
        if (type == 0)
        {
            fatty = res * 9.0;
            sum += fatty;
        }
        else if (type == 4)
        {
            sum += res * 7.0;
        }
        else
        {
            sum += res * 4.0;
        }
    }
    if (s[l - 1] == 'C')
    {
        if (type == 0)
        {
            fatty = res;
        }
        sum += res;
    }
    if (s[l - 1] == '%')
    {
        if (type == 0)
        {
            fatty = res / 100.0;
        }
        per -= res / 100.0;
    }
}


int main()
{
    string fat, protein, sugar, starch, alcohol;
    bool check = false;
    while (cin >> fat)
    {
        if (fat == "-")
        {
            if (!check)
            {
                printf("%d%%\n", int(round(fattysum / sumsum * 100)));
                sumsum = 0.0;
                fattysum = 0.0;
                check = true;
                continue;
            }
            else
            {
                break;
            }
        }
        check = false;
        sum = 0.0;
        per = 1.0;
        fatty = 0.0;
        cal(fat, 0);
        cin >> protein;
        cal(protein, 1);
        cin >> sugar;
        cal(sugar, 2);
        cin >> starch;
        cal(starch, 3);
        cin >> alcohol;
        cal(alcohol, 4);
        sum /= per;
        if (fatty < 1.0)
        {
            fatty *= sum;
        }
        sumsum += sum;
        fattysum += fatty;
    }
    return 0;
}
