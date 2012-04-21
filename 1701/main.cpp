#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

__int64 p[10005],up[10005],down[10005],psum[10005];

int main()
{
    int t,m,a,b;
    scanf("%d", &t);
    while (t --)
    {
        scanf("%d %d %d", &m, &a, &b);
        up[m + 1] = 0;
        down[0] = 0;
        __int64 sum = 0;
        memset(psum, 0, (m + 2) * sizeof(__int64));
        for (int i = 1; i <= m; i ++)
        {
            scanf("%I64d", &p[i]);
            psum[i] = psum[i - 1] + p[i];
            down[i] = down[i - 1] + sum;
            sum += psum[i - 1] + p[i] * b;
        }

        sum = 0;
        memset(psum, 0, (m + 2) * sizeof(__int64));
        for (int i = m; i >= 1; i --)
        {
            psum[i] = psum[i + 1] + p[i];
            up[i] = up[i + 1] + sum;
            sum += psum[i + 1] + p[i] * a;
        }
        int best = 1;
        for (int i = 2; i <= m; i ++)
        {
            if (up[i] + down[i] < up[best] + down[best])
            {
                best = i;
            }
        }
        printf("%d\n", best);
    }
    return 0;
}
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//__int64 k[10005],up[10005],down[10005],floor[10005];
//int main()
//{
//int t,m,a,b,pro,sum,min;
//scanf("%d",&t);
//while(t--)
//{
//   int i;
//        scanf("%d%d%d",&m,&a,&b);
//   for(i=1;i<=m;i++)
//    scanf("%I64d",&k[i]);
//   pro=k[1];sum=0;down[1]=0;
//        for(i=2;i<=m;i++)//求每一层需要下楼梯的客户的不满意度
//   {
//    down[i]=down[i-1]+sum+b*pro;
//    printf("down[%d] = %I64d\n", i, down[i]);
//    sum+=pro;pro+=k[i];
//   }
//   pro=k[m];sum=0;up[m]=0;
//        for(i=m-1;i>=1;i--) //求每一层需要上楼梯的客户的不满意度
//   {
//    up[i]=up[i+1]+sum+a*pro;
//    printf("up[%d] = %I64d\n", i, up[i]);
//            sum+=pro;pro+=k[i];
//   }
//        min=1;
//        for(i=1;i<=m;i++)
//   {
//    floor[i]=down[i]+up[i];
//            if(floor[i]<floor[min])
//     min=i;
//   }
//        printf("%d\n",min);
//}
//    return 0;
//}
