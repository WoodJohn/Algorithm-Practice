/*
POJ 2106
表达式求值。自己写了一个很屎的递归解法，速度很慢。用LL1文法可以轻取
*/

#include <string>
#include <iostream>

using namespace std;

bool calc(string s);

string trim(string s)
{
    int pos1 = 0;
    int pos2 = s.length() - 1;
    while (s[pos1] == ' ')
        pos1++;
    while (s[pos2] == ' ')
        pos2--;
    return s.substr(pos1, pos2 - pos1 + 1);
}

int findmatchedbrace(int start, string s)
{
    int pos = start;
    while (s[pos] != '(' && s[pos] != ')')
    {
        pos++;
    }
    if (s[pos] == ')')
        return pos;
    pos = findmatchedbrace(pos + 1, s);
    return findmatchedbrace(pos + 1, s);
}

bool calcand(string s)
{
    int pos = 0;
    int start = pos;
    string str = trim(s);
    string ands[100];
    int cnt = 0;
    while (pos < str.length())
    {
        if (str[pos] == '(')
        {
            pos = findmatchedbrace(pos + 1, str);
        }
        else if (str[pos] == '&')
        {
            ands[cnt++] = str.substr(start, pos - start);
            start = pos + 1;
            pos = start - 1;
        }
        pos++;
    }
    ands[cnt++] = str.substr(start, pos - start);
    if (cnt == 1)
    {
        if (str[0] == '!')
            return !calc(str.substr(1, str.length() - 1));
        else if (str[0] == '(')
        {
            int match = findmatchedbrace(1, str);
            return calc(str.substr(1, match - 1));
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        if (!calc(ands[i]))
            return false;
    }
    return true;
}

bool calc(string s)
{
    string str = trim(s);
    if (str.length() == 1)
    {
        return str == "V";
    }
    int pos = 0;
    string ors[100];
    int cnt = 0;
    int start = pos;
    while (pos < str.length())
    {
        if (str[pos] == '(')
        {
            pos = findmatchedbrace(pos + 1, str);
        }
        else if (str[pos] == '|')
        {
            ors[cnt++] = str.substr(start, pos - start);
            start = pos + 1;
            pos = start - 1;
        }
        pos++;
    }
    ors[cnt++] = str.substr(start, pos - start);
    if (cnt == 1)
    {
        return calcand(str);
    }
    for (int i = 0; i < cnt; i++)
    {
        if (calc(ors[i]))
            return true;
    }
    return false;
}

int main()
{
    char str[1001];
    int cnt = 0;
    while (cin.getline(str, 1001))
    {
        cnt++;
        string s = str;
        if (calc(s))
            cout << "Expression " << cnt << ": V" << endl;
        else
            cout << "Expression " << cnt << ": F" << endl;
    }
    return 0;
}
