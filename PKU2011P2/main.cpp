#include <stdio.h>
#include <string.h>

struct nn
{
    int v;
    nn *lchild;
    nn *parent;
    nn *rbro;
}*graph[10001];

struct node
{
    int v;
    node *next;
}*nodes[10001];

nn *root;

void insertNode(int a, int b)
{
    node *temp = nodes[a];
    if (temp == NULL)
    {
        nodes[a] = new node;
        temp = nodes[a];
        temp->v = a;
        temp->next = NULL;
    }
    while (temp->next != NULL)
        temp = temp->next;
    node *bb = new node;
    bb->v = b;
    bb->next = NULL;
    temp->next = bb;
}

void deleteNode(int a, int b)
{
    node *temp = nodes[a];
    while (temp->next != NULL)
    {
        if (temp->next->v == b)
            break;
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

nn *buildGraph(int a)
{
    nn *temp = new nn;
    if (root == NULL)
        root = temp;
    temp->v = a;
    temp->lchild = NULL;
    temp->parent = NULL;
    temp->rbro = NULL;
    graph[a] = temp;
    node *n = nodes[a]->next;
    if (n != NULL)
    {
        deleteNode(n->v, a);
        temp->lchild = buildGraph(n->v);
        nn *tt = temp->lchild;
        graph[n->v] = tt;
        tt->parent = temp;
        n = n->next;
        while (n != NULL)
        {
            deleteNode(n->v, a);
            tt->rbro = buildGraph(n->v);
            tt = tt->rbro;
            tt->parent = temp;
            graph[n->v] = tt;
            n = n->next;
        }
    }
    return temp;
}

int find(int a, int b)
{
    nn *temp = graph[a];
    while (temp->parent != NULL && temp->parent->v != b)
        temp = temp->parent;
    if (temp->parent == NULL)
        return graph[b]->parent->v;
    return temp->v;
}

bool inroot(int a)
{
    nn *temp = graph[a];
    while (temp != root && temp != NULL)
    {
        temp = temp->parent;
    }
    if (temp == root)
        return true;
    return false;
}

int n,q,a,b;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --)
    {
        root = NULL;
        memset(nodes, NULL, sizeof(nodes));
        memset(graph, NULL, sizeof(graph));
        scanf("%d %d", &n, &q);
        n --;
        while (n --)
        {
            scanf("%d %d", &a, &b);
            insertNode(a, b);
            insertNode(b, a);
        }
        root = buildGraph(1);
        while (q --)
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", find(a, b));
        }
    }
    return 0;
}
