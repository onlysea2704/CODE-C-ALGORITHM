#include <bits/stdc++.h>
using namespace std;
int n;
string s;
struct node
{
    int index, num, last;
    int child[30];
};
vector<node> tree;

void new_node()
{
    node a;
    a.index = tree.size();
    a.num = a.last = 0;
    for(int i = 0; i < 26; i++)
        a.child[i] = -1;
    tree.push_back(a);
}

void add_string(string s)
{
    int indx = 0, tmp;
    for(int i = 0; i < s.size(); i++)
    {
        tree[indx].num++;
        tmp = s[i] -'a';
        if(tree[indx].child[tmp] == -1)
        {
            new_node();
            tree[indx].child[tmp] = tree.size()-1;
        }
        indx = tree[indx].child[tmp];
    }
    tree[indx].num++;
    tree[indx].last++;
}

int count_string(string s)
{
    int indx = 0, tmp;
    for(int i = 0; i < s.size(); i++)
    {
        tmp = s[i]-'a';
        if(tree[indx].child[tmp] == -1)
            return 0;
        indx = tree[indx].child[tmp];
    }
    return tree[indx].last;
}
void dell_string(string s)
{
    int tmp;
    if(!count_string(s))
        return;
    int indx = 0;
    for(int i = 0; i < s.size(); i++)
    {
        tree[indx].num--;
        tmp = s[i] - 'a';
        indx = tree[indx].child[tmp];
    }
    tree[indx].num--;
    tree[indx].last--;
}
int main()
{
    freopen("TRIE.inp", "r", stdin);
    ///freopen("TRIE.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    new_node();
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        add_string(s);
    }
    cin >> s;
    dell_string(s);
    cout << count_string(s);

}
