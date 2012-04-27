#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct node
{
    char c;
    node* next[26];
    node()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};
node *root;
void buildTrie(char word[])
{
    int len = strlen(word);
    node *cur = root;
    int pos = 0;
    while (pos < len)
    {
        char c = word[pos];
        if (cur->next[c - 'a'] == NULL)
        {
            cur->next[c - 'a'] = new node();
            cur->next[c - 'a']->c = c;
        }
        cur = cur->next[c - 'a'];
        pos++;
    }
}

int sum, l;
void dfs(char **token, int rpos, node *r)
{
    if (rpos == l)
    {
        sum++;
        return;
    }
    int cpos = 0;
    while (token[rpos][cpos] != '\0')
    {
        char c = token[rpos][cpos];
        node *cur = r->next[c - 'a'];
        if (cur != NULL)
            dfs(token, rpos + 1, cur);
        cpos++;
    }
}

int main()
{
    int d, n, i;
    cin >> l >> d >> n;
    char word[20];
    root = new node();
    root->c = '.';
    for (i = 0; i < d; i++)
    {
        cin >> word;
        buildTrie(word);
    }
    char **token;
    char input[500];
    ofstream fout;
    fout.open("out.out", ios::out);
    for (i = 0; i < n; i++)
    {
        token = new char*[20];
        sum = 0;
        cin >> input;
        int j = 0;
        int rpos = 0;
        int len = strlen(input);
        while (j < len)
        {
            token[rpos] = new char[26];
            if (input[j] == '(')
            {
                int k = j + 1;
                int cpos = 0;
                while (input[k] != ')')
                {
                    token[rpos][cpos] = input[k];
                    k++;
                    cpos++;
                }
                token[rpos][cpos] = '\0';
                j = k + 1;
            }
            else
            {
                token[rpos][0] = input[j];
                token[rpos][1] = '\0';
                j++;
            }
            rpos++;
        }
        dfs(token, 0, root);
        fout << "Case #" << i + 1 << ": " << sum << endl;
    }
    fout.close();
    return 0;
}
