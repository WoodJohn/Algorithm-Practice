/*
POJ 1143
DFS+cache+位运算
带有博弈思想的DFS。对于对战双方A、B而言，假设当前取者为A，则A的某种选择能够获胜的充要条件是在该选择下B没有获胜
的选择方法，这显然是一个递归的计算。
关键点：
1.对于剩余可选数字的动态修改（用一遍扫描即可，只需要处理比当前选择的数字更大的数）
2.位运算。非常重要的优化，否则严重超时。由于数据规模只有20，因此可以用2^21 - 1以内的int来表示所有可能的状态，
并将状态修改（包含了剩余可选数字的修改）都用位运算实现，效率大大提高
3.Cache。即使使用了位运算，仍然超时。这时注意到2^21 * 20仍然在可以接受的内存范围内，因此可以将
状态×所选数字->是否成功
的组合空间完全记录下来。采用了这一优化后，前边完成的计算结果可以为后面的计算提供Cache，进一步提高了效率
可惜的是没能通过这题学会博弈树
*/

#include <iostream>
#include <string.h>
#include <vector>
#define N 20
using namespace std;

int pow2[21] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
                2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
int n;
int mMax;
vector<int> result;
bool cache[2097152][21];

inline int changebit(int cur, int bit)
{
    return cur ^ pow2[bit];
}

bool dfs(int curstate, int step)
{
    int i, j;
    bool check = false;
    for (i = 2; i <= mMax; i++)
    {
        if (cache[curstate][i])
        {
            check = true;
            if (step == 0)
            {
                result.push_back(i);
                continue;
            }
            return true;
        }
        int state = curstate;
        if (curstate & pow2[i])
        {
            state = changebit(state, i);
            for (j = i + 2; j <= mMax && state != 0; j++)
            {
                if ((state & pow2[j]) && !(state & pow2[j - i]))
                {
                    state = changebit(state, j);
                }
            }
            if (state == 0)
            {
                cache[curstate][i] = true;
                check = true;
                if (step == 0)
                {
                    result.push_back(i);
                    continue;
                }
                return true;
            }
            //若下一步B存在可行解，则A的该取法必败。A/B角色对等
            if (dfs(state, step + 1))
            {
                continue;
            }
            cache[curstate][i] = true;
            if (step == 0)
            {
                check = true;
                result.push_back(i);
                continue;
            }
            return true;
        }
    }
    return check;
}

int main()
{
    int i;
    int t;
    int cnt = 1;
    memset(cache, 0, sizeof(cache));
    while (cin >> n)
    {
        if (n == 0)
            break;
        mMax = 0;
        int state = 0;
        for (i = 0; i < n; i++)
        {
            cin >> t;
            state = changebit(state, t);
            if (mMax < t)
                mMax = t;

        }
        result.clear();
        bool hasResult = dfs(state, 0);
        cout << "Test Case #" << cnt++ << endl;
        if (hasResult)
        {
            cout << "The winning moves are:";
            for (i = 0; i < result.size(); i++)
                cout << " " << result[i];
            cout << endl;
        }
        else
        {
            cout << "There's no winning move." << endl;
        }
        cout << endl;
    }
    return 0;
}
