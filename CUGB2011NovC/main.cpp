#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;

struct stu
{
    string name;
    int num;
    bool used;
}stus[301];

int cmp(const void *p, const void *q)
{
    stu a = *((stu *)p);
    stu b = *((stu *)q);
    if (a.name == b.name)
    {
        return a.num - b.num;
    }
    else if (a.name > b.name)
        return 1;
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> stus[i].name >> stus[i].num;
        stus[i].used = false;
    }
    qsort(stus, n, sizeof(stu), cmp);
    for (i = 0; i < m; i++)
    {
        stu t;
        cin >> t.name >> t.num;
        void *pos = bsearch(&t, stus, n, sizeof(stu), cmp);
        if (pos == NULL)
            return 0;
        else
        {
            ((stu *)pos)->used = true;
        }
    }
    cout << n - m << endl;
    for (i = 0; i < n; i++)
    {
        if (!stus[i].used)
        {
            cout << stus[i].name << " ";
            printf("%07d\n", stus[i].num);
        }
    }
    return 0;
}
