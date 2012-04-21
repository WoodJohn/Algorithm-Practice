#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> op[10];
vector<int> result;
vector<int> temp;
int data[3][3];
int mini;

bool judge()
{
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            if (data[i][j] != 0)
                return false;
        }
    }
    return true;
}

void dfs(int a)
{
    if (a == 10)
        return;
    for (int i = 0; i <= 3; i ++)
    {
        if (i > 0)
        {
            for (int j = 0; j < op[a].size(); j ++)
            {
                int t = op[a][j];
                {
                    data[t/3][t%3] = (data[t/3][t%3] + i) % 4;
                }
            }
            for (int k = 0; k < i; k ++)
                temp.push_back(a);
        }
        if (judge() && temp.size() < mini)
        {
            result.clear();
            for (int j = 0; j < temp.size(); j ++)
                result.push_back(temp[j]);
            mini = temp.size();
        }
        else
        {
            dfs(a + 1);
        }
        if (i > 0)
        {
            for (int j = 0; j < op[a].size(); j ++)
            {
                int t = op[a][j];
                data[t/3][t%3] = (data[t/3][t%3] + (4 - i)) % 4;
            }
            for (int k = 0; k < i; k ++)
                    temp.pop_back();
        }
    }
}

int main()
{
    op[1].push_back(0);
    op[1].push_back(1);
    op[1].push_back(3);
    op[1].push_back(4);
    op[2].push_back(0);
    op[2].push_back(1);
    op[2].push_back(2);
    op[3].push_back(1);
    op[3].push_back(2);
    op[3].push_back(4);
    op[3].push_back(5);
    op[4].push_back(0);
    op[4].push_back(3);
    op[4].push_back(6);
    op[5].push_back(1);
    op[5].push_back(3);
    op[5].push_back(4);
    op[5].push_back(5);
    op[5].push_back(7);
    op[6].push_back(2);
    op[6].push_back(5);
    op[6].push_back(8);
    op[7].push_back(3);
    op[7].push_back(4);
    op[7].push_back(6);
    op[7].push_back(7);
    op[8].push_back(6);
    op[8].push_back(7);
    op[8].push_back(8);
    op[9].push_back(4);
    op[9].push_back(5);
    op[9].push_back(7);
    op[9].push_back(8);
    mini = 99999999;
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    temp.clear();
    dfs(1);
    for (int i = 0; i < result.size(); i ++)
    {
        printf("%d", result[i]);
        if (i != result.size() - 1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
