#include <iostream>

using namespace std;

int w, h, a, b, s, t, p, q;
int count;

bool checkbroken(int i, int j)
{
    return (i >= s && i < s + p && j >= t && j < t + q);
}

bool checkb(int p, int q)
{
    for (int i = p; i < p + a; i++)
    {
        for (int j = q; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p; i < p + 2 * a + b; i++)
    {
        for (int j = q + a + b; j < q + 2 * a + b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p; i < p + 2 * a + b; i++)
    {
        for (int j = q + 2 * a + 2 * b; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p + a + b; i < p + 2 * a + b; i++)
    {
        for (int j = q + a + b; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }
    return true;
}

bool checki(int p, int q)
{
    for (int i = p + 3 * a + b; i < p + 4 * a + b; i++)
    {
        for (int j = q + b - a; j < q + b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p + 3 * a + b; i < p + 4 * a + b; i++)
    {
        for (int j = q + a + b; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    return true;
}

bool checkd(int p, int q)
{
    for (int i = p + 6 * a + 2 * b; i < p + 7 * a + 2 * b; i++)
    {
        for (int j = q; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p + 5 * a + b; i < p + 7 * a + 2 * b; i++)
    {
        for (int j = q + a + b; j < q + 2 * a + b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p + 5 * a + b; i < p + 7 * a + 2 * b; i++)
    {
        for (int j = q + 2 * a + 2 * b; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p + 5 * a + b; i < p + 6 * a + b; i++)
    {
        for (int j = q + a + b; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }
    return true;
}

bool checku(int p, int q)
{
    for (int i = p + 8 * a + 2 * b; i < p + 9 * a + 2 * b; i++)
    {
        for (int j = q + a + b; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p + 9 * a + 3 * b; i < p + 10 * a + 3 * b; i++)
    {
        for (int j = q + a + b; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    for (int i = p + 8 * a + 2 * b; i < p + 10 * a + 3 * b; i++)
    {
        for (int j = q + 2 * a + 2 * b; j < q + 3 * a + 2 * b; j++)
        {
            if (checkbroken(i, j))
                return false;
        }
    }

    return true;
}

int main()
{
    cin >> w >> h >> a >> b >> s >> t >> p >> q;
    for (int i = 0; i <= w - 10 * a - 3 * b; i++)
    {
        for (int j = 0; j <= h - 3 * a - 2 * b; j++)
        {
            if (checkb(i, j) && checki(i, j) && checkd(i, j) && checku(i, j))
                count++;
        }
    }
    cout << count << endl;
    return 0;
}
