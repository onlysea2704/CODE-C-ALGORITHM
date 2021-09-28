#include <bits/stdc++.h>

using namespace std;
int const mod = 1337377, maxn =  333333;
int n, d[maxn], as;
string a, s;
struct node
{
    int last;
    int child[30];
};

vector<node> tree;

void new_node()
{
    node a;
    a.last = 0;
    for(int i = 0; i < 26; i++)
        a.child[i] = -1;
    tree.push_back(a);
}

void add_string(string s)
{
    int indx = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int tmp = s[i] - 'a';
        if(tree[indx].child[tmp] == -1)
        {
            new_node();
            tree[indx].child[tmp] = tree.size() - 1;
        }
        indx = tree[indx].child[tmp];
    }
    tree[indx].last = 1;
}

int main()
{
    ///freopen("NKSEV.inp", "r", stdin);
    ///freopen("NKSEV.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s >> n;
    new_node();
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        add_string(a);
    }
    as = s.size();
    d[as] = 1;
    for(int i = s.size()-1; i >= 0; i--)
    {
        int root = 0;
        for(int j = i; j < s.size(); j++)
        {
            int tmp = s[j] - 'a';
            if(tree[root].child[tmp] == -1)
                break;
            root = tree[root].child[tmp];
            if(tree[root].last == 1)
                d[i] = (d[i]+d[j+1])%mod;
        }
    }
    cout << d[0];

}
