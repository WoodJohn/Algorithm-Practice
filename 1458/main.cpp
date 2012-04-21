/*
POJ 1458
DP«ÛLCS
*/

#include <stdio.h>
#include <string.h>
using namespace std;

char s1[501], s2[501];
int dp[501][501];
//bool same[501][501];

inline int min(int a, int b)
{
    return a < b ? a : b;
}

int find(int a, int b)
{
    if (dp[a][b] != -1)
        return dp[a][b];
    if (a < 0 || b < 0)
        return 0;
    int t1, t2, t3;
    t1 = find(a - 1, b - 1) + int(s1[a] == s2[b]);
    t2 = find(a - 1, b);
    t3 = find(a, b - 1);
    int mMax = t1;
    if (t2 > mMax)
        mMax = t2;
    if (t3 > mMax)
        mMax = t3;
    dp[a][b] = mMax;
    return mMax;
}

int main()
{
    while (scanf("%s %s", s1, s2) != EOF)
    {
        memset(dp, -1, sizeof(dp));
//        memset(same, 0, sizeof(same));
//        for (int i = 0; i < strlen(s1); i++)
//        {
//            for (int j = 0; j < strlen(s2); j++)
//            {
//                same[i][j] = (s1[i] == s2[j]);
//            }
//        }
        dp[0][0] = 0;
        if (s1[0] == s2[0])
            dp[0][0] = 1;
        printf("%d\n", find(strlen(s1) - 1, strlen(s2) - 1));
    }
    return 0;
}
