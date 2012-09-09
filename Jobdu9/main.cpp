#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int n;
int ins[100005];
int outs[100005];

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
            scanf("%d", &ins[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &outs[i]);
        int pos = 0;
        int inp = 0;
        while (pos < n)
        {
            int c = outs[pos];
            if (!s.empty() && s.top() == c)
            {
                s.pop();
                pos++;
            }
            else
            {
                while (inp < n && ins[inp] != c)
                {
                    s.push(ins[inp]);
                    inp++;
                }
                if (inp == n)
                    break;
                inp++;
                pos++;
            }
        }
        if (pos == n && s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
