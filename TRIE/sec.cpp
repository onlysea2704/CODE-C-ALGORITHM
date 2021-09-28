#include <bits/stdc++.h>

using namespace std;
int m, n, k, x;
int res[50005];
struct node
{
    int num, last;
    int child[30];
};
vector<node> tree;
void new_node()
{
    node a;
    a.num = a.last = 0;
    for(int i = 0; i <= 1; i++)
        a.child[i] = -1;
    tree.push_back(a);
}

void add_string(string s)
{
    int indx = 0, tmp;
    for(int i = 0; i < s.size(); i++)
    {
        tree[indx].num++;
        tmp = s[i]-48;
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
    int indx = 0, tmp, ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        tmp = s[i]-48;
        ans += tree[indx].last;
        if(tree[indx].child[tmp] == -1)
            return ans;
        indx = tree[indx].child[tmp];
    }
    ans += tree[indx].num;
    return ans;
}

int main()
{
    ///freopen("sec.inp", "r",stdin);
    ///freopen("sec.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    new_node();
    for(int i = 1; i <= m+n; i++)
    {
        cin >> k;
        string s = "";
        for(int j = 1; j <= k; j++)
        {
            cin >> x;
            s += char(x+48);
        }
        if(i <= m)
            add_string(s);
        else
            res[i-m] = count_string(s);
    }
    for(int i = 1; i <= n; i++)
        cout << res[i] << '\n';

}
