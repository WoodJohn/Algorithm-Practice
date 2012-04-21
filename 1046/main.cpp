#include <iostream>
#include <cmath>

using namespace std;

struct stu
{
    int x;
    int y;
    int z;
};

float dist(stu p1, stu p2)
{
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0) + pow(p1.z - p2.z, 2.0));
}

int main()
{
    stu target[16];
    for (int i = 0; i < 16; i ++)
    {
        cin >> target[i].x >> target[i].y >> target[i].z;
    }
    stu input;
    while (cin >> input.x >> input.y >> input.z)
    {
        if (input.x == -1)
        {
            break;
        }
        float min = 999999.0;
        int index = -1;
        for (int j = 0; j < 16; j ++)
        {
            float dis = dist(input, target[j]);
            if (dis < min)
            {
                min = dis;
                index = j;
            }
        }
        if (index != -1)
        {
            cout << '(' << input.x << ',' << input.y << ',' << input.z << ')' << " maps to (" << target[index].x << ',' << target[index].y << ',' << target[index].z << ')' << endl;
        }
    }
    return 0;
}
