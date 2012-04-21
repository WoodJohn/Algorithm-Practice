/*
POJ 1143
DFS+cache+λ����
���в���˼���DFS�����ڶ�ս˫��A��B���ԣ����赱ǰȡ��ΪA����A��ĳ��ѡ���ܹ���ʤ�ĳ�Ҫ�������ڸ�ѡ����Bû�л�ʤ
��ѡ�񷽷�������Ȼ��һ���ݹ�ļ��㡣
�ؼ��㣺
1.����ʣ���ѡ���ֵĶ�̬�޸ģ���һ��ɨ�輴�ɣ�ֻ��Ҫ����ȵ�ǰѡ������ָ��������
2.λ���㡣�ǳ���Ҫ���Ż����������س�ʱ���������ݹ�ģֻ��20����˿�����2^21 - 1���ڵ�int����ʾ���п��ܵ�״̬��
����״̬�޸ģ�������ʣ���ѡ���ֵ��޸ģ�����λ����ʵ�֣�Ч�ʴ�����
3.Cache����ʹʹ����λ���㣬��Ȼ��ʱ����ʱע�⵽2^21 * 20��Ȼ�ڿ��Խ��ܵ��ڴ淶Χ�ڣ���˿��Խ�
״̬����ѡ����->�Ƿ�ɹ�
����Ͽռ���ȫ��¼��������������һ�Ż���ǰ����ɵļ���������Ϊ����ļ����ṩCache����һ�������Ч��
��ϧ����û��ͨ������ѧ�Ჩ����
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
            //����һ��B���ڿ��н⣬��A�ĸ�ȡ���ذܡ�A/B��ɫ�Ե�
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
