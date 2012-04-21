#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int n;
int c;
bool has[100001];
int pos[100001][4];
vector<int> v;
vector<int> v2;
int data[10001];
int count[10001];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d", &n);
    memset(has, 0, sizeof(has));
    memset(pos, 0, sizeof(pos));
    memset(data, 0, sizeof(data));
    memset(count, 0, sizeof(count));
    v.clear();
    v2.clear();
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++)
        {
            int a;
            scanf("%d", &a);
            if (!has[a])
            {
                has[a] = true;
                v.push_back(a);
            }
            pos[a][pos[a][0] + 1] = i;
            pos[a][0]++;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        int t = v[i];
        if (pos[t][0] == 3)
            continue;
        else if (pos[t][0] == 1)
            data[pos[t][1]] += 2;
        else
        {
            v2.push_back(t);
            count[pos[t][1]]++;
            count[pos[t][2]]++;
        }
    }
    int mMax = 0;
    for (int i = 0; i < v2.size(); i++)
    {
        int t = v2[i];
        int src = pos[t][1];
        int dst = pos[t][2];
        if (data[src] < data[dst])
            data[src]++;
        else if (data[dst] < data[src])
            data[dst]++;
        else if (count[src] < count[dst])
            data[src]++;
        else
            data[dst]++;
        count[src]--;
        count[dst]--;
        int m = max(data[src], data[dst]);
        if (m > mMax)
            mMax = m;
    }
    printf("%d\n", mMax);
    return 0;
}
