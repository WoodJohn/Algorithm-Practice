#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<string> backward;
    stack<string> forward;
    string current = "http://www.acm.org/";
    string op;
    while (cin >> op)
    {
        if (op == "QUIT")
        {
            break;
        }
        if (op == "VISIT")
        {
            if (current != "")
            {
                backward.push(current);
            }
            cin >> current;
            while(!forward.empty())
            {
                forward.pop();
            }
            cout << current << endl;
        }
        else if (op == "BACK")
        {
            if (backward.size() == 0)
            {
                cout << "Ignored" << endl;
            }
            else
            {
                forward.push(current);
                current = backward.top();
                backward.pop();
                cout << current << endl;
            }
        }
        else if (op == "FORWARD")
        {
            if (forward.size() == 0)
            {
                cout << "Ignored" << endl;
            }
            else
            {
                backward.push(current);
                current = forward.top();
                forward.pop();
                cout << current << endl;
            }
        }
    }
    return 0;
}
