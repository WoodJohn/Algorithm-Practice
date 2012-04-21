/*
实现一个最小堆
*/

#include <iostream>

using namespace std;

int heap[201];
int heapsize;

void swap(int a, int b)
{
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

void shift(int a)
{
    int si = a;
    if (a * 2 <= heapsize && heap[si] > heap[a * 2])
        si = a * 2;
    if (a * 2 + 1 <= heapsize && heap[si] > heap[a * 2 + 1])
        si = a * 2 + 1;
    if (a == si)
        return;
    swap(a, si);
    shift(si);
}

void buildheap()
{
    for (int i = heapsize / 2; i > 0; i--)
    {
        shift(i);
    }
}

void heapsort()
{
    buildheap();
    while (heapsize > 0)
    {
        cout << heap[1] << ' ';
        heap[1] = heap[heapsize];
        heapsize--;
        shift(1);
    }
}

int main()
{
    heap[1] = 5;
    heap[2] = 3;
    heap[3] = 2;
    heap[4] = 4;
    heap[5] = 1;
    heapsize = 5;
    heapsort();
    return 0;
}
