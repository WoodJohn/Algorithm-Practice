#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> result;
int capa, capb, cura, curb, n;
bool mark[1001][1001];
bool done;

void filla()
{
    cura = capa;
}

void fillb()
{
    curb = capb;
}

void emptya()
{
    cura = 0;
}

void emptyb()
{
    curb = 0;
}

void pourab()
{
    if (cura + curb < capb)
    {
        curb = cura + curb;
        cura = 0;
    }
    else
    {
        int temp = capb - curb;
        cura -= temp;
        curb = capb;
    }
}

void pourba()
{
    if (cura + curb < capa)
    {
        cura = cura + curb;
        curb = 0;
    }
    else
    {
        int temp = capa - cura;
        curb -= temp;
        cura = capa;
    }
}

void printresult()
{
    for (int i = 0; i < result.size(); i ++)
    {
        switch(result[i])
        {
            case 0:
                printf("fill A\n");
                break;
            case 1:
                printf("fill B\n");
                break;
            case 2:
                printf("empty A\n");
                break;
            case 3:
                printf("empty B\n");
                break;
            case 4:
                printf("pour A B\n");
                break;
            case 5:
                printf("pour B A\n");
                break;
            default:
                break;
        }
    }
    printf("success\n");
}

void dfs()
{
    if (mark[cura][curb] || done)
        return;
    if (curb == n)
    {
        done = true;
        printresult();
    }
    int tempa = cura;
    int tempb = curb;
    mark[cura][curb] = true;
    if (cura != capa)
    {
        filla();
        result.push_back(0);
        dfs();
        result.pop_back();
        cura = tempa;
    }
    if (curb != capb)
    {
        fillb();
        result.push_back(1);
        dfs();
        result.pop_back();
        curb = tempb;
    }
    if (cura != 0)
    {
        emptya();
        result.push_back(2);
        dfs();
        result.pop_back();
        cura = tempa;
    }
    if (curb != 0)
    {
        emptyb();
        result.push_back(3);
        dfs();
        result.pop_back();
        curb = tempb;
    }
    if (cura != 0 && curb != capb)
    {
        pourab();
        result.push_back(4);
        dfs();
        result.pop_back();
        cura = tempa;
        curb = tempb;
    }
    if (curb != 0 && cura != capa)
    {
        pourba();
        result.push_back(5);
        dfs();
        result.pop_back();
        cura = tempa;
        curb = tempb;
    }
}

int main()
{
    while (scanf("%d %d %d", &capa, &capb, &n) != EOF)
    {
        memset(mark, 0, sizeof(mark));
        cura = curb = 0;
        done = false;
        dfs();
    }
    return 0;
}
