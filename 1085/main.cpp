#include <iostream>
#include <stdio.h>
#define INF -999
using namespace std;

int pow2[19] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
                2048, 4096, 8192, 16384, 32768, 65536, 131072,
                262144};

short tris[9][3] = {{1, 2, 3}, {4, 5, 8}, {3, 5, 6}, {6, 7, 9}, {10, 11, 16}, {8, 11, 12}, {12, 13, 17}, {9, 13, 14}, {14, 15, 18}};
short dp[524288];
short p2l[11][11];

int t, n, i;

void init()
{
    for (i = 0; i < 524288; i++)
    {
        dp[i] = INF;
    }
    p2l[1][2] = 1;
    p2l[1][3] = 2;
    p2l[2][3] = 3;
    p2l[2][4] = 4;
    p2l[2][5] = 5;
    p2l[3][5] = 6;
    p2l[3][6] = 7;
    p2l[4][5] = 8;
    p2l[5][6] = 9;
    p2l[4][7] = 10;
    p2l[4][8] = 11;
    p2l[5][8] = 12;
    p2l[5][9] = 13;
    p2l[6][9] = 14;
    p2l[6][10] = 15;
    p2l[7][8] = 16;
    p2l[8][9] = 17;
    p2l[9][10] = 18;
    dp[524286] = 0;
}

inline int changebit(int state, int bit)
{
    return state ^ pow2[bit];
}

int countTris(int state, int line)
{
    int p, q;
    int cnt = 0;
    //检查取line这条边后是否形成了新的三角形
    for (p = 0; p < 9; p++)
    {
        for (q = 0; q < 3; q++)
        {
            if (tris[p][q] == line && (state & pow2[tris[p][(q + 1) % 3]]) && (state & pow2[tris[p][(q + 2) % 3]]))
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int dfs(int curState)
{
    int j;
    if (dp[curState] != INF)
        return dp[curState];
    int newState;
    int mMax = INF;
    for (j = 1; j < 19; j++)
    {
        if ((curState & pow2[j]) == 0)
        {
            int result;
            newState = changebit(curState, j);
            int cnt = countTris(curState, j);
            if (cnt > 0)
                result = cnt + dfs(newState);
            else
                result = cnt - dfs(newState);
            if (result > mMax)
                mMax = result;
        }
    }
    dp[curState] = mMax;
    return mMax;
}

int main()
{
    init();
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cin >> n;
        int state = 0;
        int cntAB[2];
        cntAB[0] = cntAB[1] = 0;
        int turn = 1;
        int total = 0;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            int line = p2l[a][b];
            int cnt = countTris(state, line);
            if (cnt > 0)
                total += turn * cnt;
            else
                turn *= -1;
            state = changebit(state, line);
        }
        total += turn * dfs(state);
        char c = total > 0 ? 'A' : 'B';
        printf("Game %d: %c wins.\n", i, c);
    }
    return 0;
}
