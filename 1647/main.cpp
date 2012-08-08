#include <iostream>
#include <cmath>
using namespace std;

struct point
{
    int x;
    int y;
}k1, q, k2;

bool checkedByKing(int x, int y)
{
    return (x == k1.x - 1 && y == k1.y - 1) || (x == k1.x + 1 && y == k1.y + 1) ||
    (x == k1.x - 1 && y == k1.y + 1) || (x == k1.x + 1 && y == k1.y - 1) ||
    (x == k1.x && y == k1.y - 1) || (x == k1.x && y == k1.y + 1) ||
    (x == k1.x - 1 && y == k1.y) || (x == k1.x + 1 && y == k1.y);
}

bool checkedByQueen(int x, int y, int qx, int qy)
{
    if (x == qx && y == qy)
        return false;
    return (x == qx) || (y == qy) || (abs(double(x - qx)) == abs(double(y - qy)));
}

bool checked(int x, int y, int qx, int qy)
{
    if (x > 8 || x < 1 || y > 8 || y < 1)
        return true;
    return (checkedByKing(x, y) || checkedByQueen(x, y, qx, qy));
}

char res[5];

bool checkmate(int qx, int qy)
{
    if (checked(k2.x + 1, k2.y, qx, qy) && checked(k2.x - 1, k2.y, qx, qy) && checked(k2.x, k2.y - 1, qx, qy) && checked(k2.x, k2.y + 1, qx, qy)
        && checked(k2.x + 1, k2.y + 1, qx, qy) && checked(k2.x - 1, k2.y - 1, qx, qy) && checked(k2.x - 1, k2.y + 1, qx, qy) && checked(k2.x + 1, k2.y - 1, qx, qy))
        {
            res[0] = 'a' + qx - 1;
            res[1] = '1' + qy - 1;
            res[2] = '\0';
            return true;
        }
        return false;
}

bool find()
{
    for (int x = 1; x <= 8; x++)
    {
        for (int y = 1; y <= 8; y++)
        {
            if (!(x == q.x && y == q.y))
            {
                if (x == q.x || y == q.y || abs(double(x - q.x)) == abs(double(y - q.y)))
                {
                    if (x == k2.x || y == k2.y || abs(double(x - k2.x)) == abs(double(y - k2.y)))
                    {
                        if (x == k2.x)
                        {

                        }
                        if (checkmate(x, y))
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    char sk1[5], sq[5], sk2[5];
    cin >> sk1 >> sq >> sk2;
    k1.x = sk1[0] - 'a' + 1;
    k1.y = sk1[1] - '1' + 1;
    q.x = sq[0] - 'a' + 1;
    q.y = sq[1] - '1' + 1;
    k2.x = sk2[0] - 'a' + 1;
    k2.y = sk2[1] - '1' + 1;
    if (!find())
        cout << "no" << endl;
    else
        cout << res << endl;
    return 0;
}
