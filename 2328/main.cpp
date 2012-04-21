#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

struct stu
{
    int val;
    int cond;
};

vector<stu> v;

bool check(stu input, int guess)
{
    return input.cond == 1 ? (guess < input.val) : (guess > input.val);
}

int main()
{
    int n;
    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }
        getchar();
        stu input;
        input.val = n;
        string s;
        getline(cin, s);
        if (s == "too high")
        {
            input.cond = 1;
            v.push_back(input);
        }
        else if (s == "too low")
        {
            input.cond = -1;
            v.push_back(input);
        }
        else
        {
            int i;
            for (i = 0; i < v.size(); i ++)
            {
                if (!check(v[i], n))
                {
                    cout << "Stan is dishonest" << endl;
                    break;
                }
            }
            if (i == v.size())
            {
                cout << "Stan may be honest" << endl;
            }
            v.clear();
        }
    }
    return 0;
}
