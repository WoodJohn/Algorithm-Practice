/*
POJ 2044
DFS + 状态存储优化（只存储四个角的状态，非常重要的优化！否则内存严重不足）
注意：不需要回溯状态，因为一个状态只要走过就没必要再走了（如果成功，则已经得到
了一个解；如果失败，则该状态没有价值）
*/

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int n;

short data[366][16];
bool used[366][9][7][7][7][7];

inline int makestate(int a, int b, int c, int d, int e)
{
    return a * 10000 + b * 1000 + c * 100 + d * 10 + e;
}

bool dfs(int day, int state)
{
    if (day == n)
        return true;
    int pos = state / 10000;
    int posx = pos / 3;
    int posy = pos % 3;
    int cnt1 = (state / 1000) % 10;
    int cnt2 = (state / 100) % 10;
    int cnt3 = (state / 10) % 10;
    int cnt4 = state % 10;
    if (data[day][posx * 4 + posy] == 1 ||
        data[day][posx * 4 + posy + 1] == 1 ||
        data[day][(posx + 1) * 4 + posy] == 1 ||
        data[day][(posx + 1) * 4 + posy + 1] == 1)
    {
        return false;
    }
    if (posx == 0 && posy == 0)
    {
        cnt1 = 0;
        cnt2++;
        if (cnt2 > 6)
            return false;
        cnt3++;
        if (cnt3 > 6)
            return false;
        cnt4++;
        if (cnt4 > 6)
            return false;
    }
    else if (posx == 2 && posy == 0)
    {
        cnt3 = 0;
        cnt1++;
        if (cnt1 > 6)
            return false;
        cnt2++;
        if (cnt2 > 6)
            return false;
        cnt4++;
        if (cnt4 > 6)
            return false;
    }
    else if (posx == 0 && posy == 2)
    {
        cnt2 = 0;
        cnt1++;
        if (cnt1 > 6)
            return false;
        cnt3++;
        if (cnt3 > 6)
            return false;
        cnt4++;
        if (cnt4 > 6)
            return false;
    }
    else if (posx == 2 && posy == 2)
    {
        cnt4 = 0;
        cnt2++;
        if (cnt2 > 6)
            return false;
        cnt3++;
        if (cnt3 > 6)
            return false;
        cnt1++;
        if (cnt1 > 6)
            return false;
    }
    else
    {
        cnt1++;
        if (cnt1 > 6)
            return false;
        cnt2++;
        if (cnt2 > 6)
            return false;
        cnt3++;
        if (cnt3 > 6)
            return false;
        cnt4++;
        if (cnt4 > 6)
            return false;
    }
    int newpos;
    for (int i = 0; i < 3; i++)
    {
        newpos = i * 3 + posy;
        if (!used[day + 1][newpos][cnt1][cnt2][cnt3][cnt4])
        {
            used[day + 1][newpos][cnt1][cnt2][cnt3][cnt4] = true;
            int newstate = makestate(newpos, cnt1, cnt2, cnt3, cnt4);
            if (dfs(day + 1, newstate))
                return true;
            //used[day + 1][newpos][cnt1][cnt2][cnt3][cnt4] = false;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        newpos = posx * 3 + i;
        if (!used[day + 1][newpos][cnt1][cnt2][cnt3][cnt4])
        {
            used[day + 1][newpos][cnt1][cnt2][cnt3][cnt4] = true;
            int newstate = makestate(newpos, cnt1, cnt2, cnt3, cnt4);
            if (dfs(day + 1, newstate))
                return true;
            //used[day + 1][newpos][cnt1][cnt2][cnt3][cnt4] = false;
        }
    }
    return false;
}


int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                cin >> data[i][j];
            }
        }
        int init = 40000;
        used[0][4][0][0][0][0] = true;
        if (dfs(0, init))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
