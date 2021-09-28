#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
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
    int tmp, cnt = 0, indx = 0;
    for(int i = 0; i < s.size(); i++)
    {
        tmp = s[i] - 'a';
        cnt += tree[indx].last;
        if(tree[indx].child[tmp] == -1)
        {
            new_node();
            tree[indx].child[tmp] = tree.size()-1;
        }
        indx = tree[indx].child[tmp];
    }
    ans = max(ans, cnt+1);
    tree[indx].last = 1;
}
int main()
{
    ///freopen("CHAIN2.inp", "r", stdin);
    ///freopen("CHAIN2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    new_node();
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        add_string(s);
    }
    cout << ans;
}
