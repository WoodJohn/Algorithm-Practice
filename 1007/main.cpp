#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

struct stu
{
    int count;
    string str;
};

int cmp(const void *a, const void *b)
{
    stu p = *((stu *)a);
    stu q = *((stu *)b);
    return p.count - q.count;
}

int main()
{
    int n,m;
    cin >> m >> n;
    stu *array = new stu[n];
    for (int i = 0 ; i < n ; i ++)
    {
        int c = 0;
        string s;
        cin >> s;
        array[i].str = s;
        for (int j = 0; j < m - 1; j ++)
        {
            for (int k = j + 1; k < m; k ++)
            {
                if (s[j] > s[k])
                {
                    c ++;
                }
            }
        }
        array[i].count = c;
    }
    qsort(array, n, sizeof(stu), cmp);
    for (int r = 0 ; r < n ; r ++)
    {
        cout << array[r].str << endl;
    }
    delete array;
    return 0;
}
