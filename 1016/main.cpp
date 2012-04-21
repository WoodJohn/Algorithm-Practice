#include <iostream>
#include <map>
#include <string>
using namespace std;

string calc(string s)
{
    string ret = "";
    int cnt[10] = {0};
    int i, len;
    len = s.length();
    for (i = 0; i < len; i++)
    {
        cnt[s[i] - '0']++;
    }
    for (i = 0; i < 10; i++)
    {
        if (cnt[i] > 0)
        {
            char c;
            if (cnt[i] < 10)
            {
                c = cnt[i] + '0';
                ret += c;
            }
            else
            {
                c = (cnt[i] % 10) + '0';
                ret += c;
                c = (cnt[i] / 10) + '0';
                ret += c;
            }
            c = i + '0';
            ret += c;
        }
    }
    return ret;
}

int main()
{
    string in;
    while (cin >> in)
    {
        if (in == "-1")
            break;
        map<string, int> ht;
        ht.insert(pair<string, int>(in, 0));
        int cnt = 0;
        string temp1 = in;
        string temp2 = calc(in);
        while (1)
        {
            //cout << temp2 << endl;
            if (temp1 == temp2)
            {
                if (cnt == 0)
                    cout << in << " is self-inventorying" << endl;
                else
                    cout << in << " is self-inventorying after " << cnt << " steps" << endl;
                break;
            }
            else
            {
                map<string, int>::iterator it = ht.find(temp2);
                if (it != ht.end())
                {
                    int t = it->second;
                    cout << in << " enters an inventory loop of length " << cnt + 1 - t << endl;
                    break;
                }
                else
                {
                    cnt++;
                    temp1 = temp2;
                    temp2 = calc(temp2);
                    ht.insert(pair<string, int>(temp1, cnt));
                }
            }
            if (cnt == 15)
            {
                cout << in << " can not be classified after 15 iterations" << endl;
                break;
            }
        }
    }
    return 0;
}
