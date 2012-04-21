/*
POJ 1635
树的最小表示
一个以0、1组成的字符串来表示一棵树，0表示从当前位置随机选一个子结点向下一层，1表示返回（只有在
叶节点处才会返回）。给出两个这样的字符串，问这两棵树是否同构
要点在于：从头起，每一个0、1数相等的连续子串都表示一棵子树，假设这些子树已经是有序表示的，则将
这些子树按序排列则即可以作为母树的有序表示。这显然是一个递归问题。需要注意的是，前述的连续子串
需要去掉头尾的0和1才能开始寻找其自身的子树（因为它们表示进入和退出该子树的步骤，不算在该子树的
结构内）
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
