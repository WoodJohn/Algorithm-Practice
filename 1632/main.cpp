/*
POJ 1632
DFS!
看到数据量较小就决定用DFS来枚举。做法比较笨：枚举左边的点，dfs时将当前点放入左队列，然后从该点
关联的右结点中找到跟左队列中全部的点都相连的，再dfs右边的这个点。这样逐步增加，每次dfs到底的时
候取两个队列的最小值作为结果，最后要找的就是结果中的最大值。
第一次写的时候比较2B，想当然的以为要找到不能再找的时候才计算结果，这样由于使用了bool数组来判重，
导致先从非答案结点出发，途径答案结点时会导致答案结点在之后的计算中不可用从而出错。后来改为每次
从头搜索开始前清空bool数组，然后每次不管是否有子空间都算一遍（这样不影响最大值的记录）。这时又
出现了第二个bug：每次dfs一个点以后还要将该点的bool记录重置，否则之后还有更大值时算不出。修复之
后，TLE。。。想想，发现时间是指数级的，我擦累
睡前想了一会，醒来后又稍微想想，发现只要在dfs中枚举时加个剪枝就行了。即：如果当前待加入的那个
队列的长度（即目前被选中的结点数）+目前结点还待扩展的子空间树的数目 <= 当前计算出的最大值，则
不必再搜索了：因为再搜也不会比这个值更大了。由于DFS的性质，如果当前搜索的结点是答案结点，那么
肯定会先找到最大值才进入不必要的冗余状态，因此这个剪枝几乎可以减掉所有的无用解空间。最后提交的
时候忘记把fout改回cout，多贡献了一个WA，orz。。
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

void sdfs(int a);
void ddfs(int a);

struct snode
{
    int cnt;
    int edges[37];
}snodes[37];

struct dnode
{
    int cnt;
    int edges[37];
}dnodes[37];

bool adj[37][37];
bool sused[37];
bool dused[37];
bool slog[37];
vector<int> sv;
vector<int> dv;
int mMax;

void sdfs(int a)
{
    sused[a] = true;
    sv.push_back(a);
    for (int i = 0; i < snodes[a].cnt; i++)
    {
        if (dv.size() + snodes[a].cnt - i <= mMax)
            break;
        int temp = snodes[a].edges[i];
        if (!dused[temp])
        {
            bool cc = true;
            for (int j = 0; j < sv.size(); j++)
            {
                if (!adj[sv[j]][temp])
                {
                    cc = false;
                    break;
                }
            }
            if (cc)
                ddfs(temp);
        }
    }
    int mm = sv.size() < dv.size() ? sv.size() : dv.size();
    if (mm > mMax)
        mMax = mm;
    sv.pop_back();
    sused[a] = false;
}

void ddfs(int a)
{
    dused[a] = true;
    dv.push_back(a);
    for (int i = 0; i < dnodes[a].cnt; i++)
    {
        if (sv.size() + dnodes[a].cnt - i <= mMax)
            break;
        int temp = dnodes[a].edges[i];
        if (!sused[temp] && !slog[temp])
        {
            bool cc = true;
            for (int j = 0; j < dv.size(); j++)
            {
                if (!adj[temp][dv[j]])
                {
                    cc = false;
                    break;
                }
            }
            if (cc)
                sdfs(temp);
        }
    }
    int mm = sv.size() < dv.size() ? sv.size() : dv.size();
    if (mm > mMax)
        mMax = mm;
    dv.pop_back();
    dused[a] = false;
}

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(snodes, 0, sizeof(snodes));
        memset(dnodes, 0, sizeof(dnodes));
        memset(adj, 0, sizeof(adj));
        memset(slog, 0, sizeof(slog));
        while (n--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            snodes[a].edges[snodes[a].cnt++] = b;
            dnodes[b].edges[dnodes[b].cnt++] = a;
            adj[a][b] = true;
        }
        mMax = 0;
        for (int i = 0; i < 37; i++)
        {
            if (snodes[i].cnt > 0)
            {
                sv.clear();
                dv.clear();
                memset(sused, 0, sizeof(sused));
                memset(dused, 0, sizeof(dused));
                sdfs(i);
                slog[i] = true;
            }
        }
        cout << mMax << endl;
    }
    return 0;
}
