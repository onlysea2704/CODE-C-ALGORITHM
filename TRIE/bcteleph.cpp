#include <bits/stdc++.h>

using namespace std;
int t, n, ans;
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
        tmp = s[i]-'0';
        if(tree[indx].child[tmp] == -1)
        {
            new_node();
            tree[indx].child[tmp] = tree.size()-1;
        }
        indx = tree[indx].child[tmp];

        if(tree[indx].last != 0)
            ans = 1;
    }
    if(tree[indx].num != 0)
        ans = 1;

    tree[indx].num++;
    tree[indx].last++;
}

int main()
{
    ///freopen("BCTELEPH.inp", "r", stdin);
    ///freopen("BCTELEPH.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        new_node(), ans = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> s;
            if(ans == 0)
                add_string(s);
        }
        if(ans == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
        tree.clear();
    }
}
