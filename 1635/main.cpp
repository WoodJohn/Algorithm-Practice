/*
POJ 1635
������С��ʾ
һ����0��1��ɵ��ַ�������ʾһ������0��ʾ�ӵ�ǰλ�����ѡһ���ӽ������һ�㣬1��ʾ���أ�ֻ����
Ҷ�ڵ㴦�Ż᷵�أ������������������ַ����������������Ƿ�ͬ��
Ҫ�����ڣ���ͷ��ÿһ��0��1����ȵ������Ӵ�����ʾһ��������������Щ�����Ѿ��������ʾ�ģ���
��Щ�������������򼴿�����Ϊĸ���������ʾ������Ȼ��һ���ݹ����⡣��Ҫע����ǣ�ǰ���������Ӵ�
��Ҫȥ��ͷβ��0��1���ܿ�ʼѰ�����������������Ϊ���Ǳ�ʾ������˳��������Ĳ��裬�����ڸ�������
�ṹ�ڣ�
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s[2];
int n;

string process(string str)
{
    if (str == "01")
        return str;
    vector<string> v;
    int len = str.length();
    int c0, c1;
    c0 = c1 = 0;
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '0')
            c0++;
        else
            c1++;
        if (c1 == c0)
        {
            if (i - start == 1)
                v.push_back("01");
            else
            {
                string ss = "0" + process(str.substr(start + 1, i - start - 1)) + "1";
                v.push_back(ss);
            }
            start = i + 1;
        }
    }
    sort(v.begin(), v.end());
    string result = "";
    for (int i = 0; i < v.size(); i++)
    {
        result += v[i];
    }
    return result;
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s[0];
        cin >> s[1];
        s[0] = process(s[0]);
        s[1] = process(s[1]);
        if (s[0] == s[1])
            cout << "same" << endl;
        else
            cout << "different" << endl;
    }
    return 0;
}
