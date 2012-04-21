#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define N 1001
int P, n, s, x;
int matrix[N][N],ans[N];

void init()
{
    int temp = s;
    for(int i = 0; i < n; i++)
    {
        int temp2 = 1;
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = temp2;
            temp2 = (temp2 * (temp % P)) % P;
        }
        temp++;
        temp %= P;
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &matrix[i][n]);
    }

}

int find(int a, int y)
{
    int i;
    a = (a%P + P) % P; y = (y%P + P)%P;
    for(i = 0; i < P; i++)
        if((a*i)%P == y)
            return i;
}

void solve()
{
    int i,j,k;
    int row,col;
    int a,b,sum;
    row = 0; col = 0;
    while(row < n && col < n)
    {
        for(i = row, j = -1; i < n; i++)
            if(matrix[i][col] != 0)
            {
                j = i;
                break;
            }
        for(i = col; i < n; i++)
        {
            k = matrix[row][i];
            matrix[row][i] = matrix[j][i];
            matrix[j][i] = k;
        }
        a = matrix[row][col];
        for(i = row+1; i < n; i++)
        {
            b = matrix[i][col];
            for(j = col; j <= n; j++)
                matrix[i][j] = (matrix[i][j]*a - matrix[row][j]*b)%P;
        }
        row++; col++;
    }
    for(i = n-1; i >= 0; i--)
    {
        sum = 0;
        for(j = i+1; j < n; j++)
            sum = (sum + matrix[i][j]*ans[j])%P;
        ans[i] = find(matrix[i][i],matrix[i][n]-sum);
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &P, &s, &x);
    init();
    solve();
    for (int i = 0; i < x; i++)
    {
        int ss = s + n + i;
        int temp = 1;
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum = (sum + (ans[j] % P) * (temp % P)) % P;
            temp = (temp * ss) % P;
        }
        printf("%d", sum);
        if (i < x - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}


