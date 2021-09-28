#include <bits/stdc++.h>

using namespace std;
int const mn = 1e6*4;
int n, q, u, v;
string s;
struct node
{
    int left, right, res;
};
node stree[mn];

node operator + (node b, node d)
{
    node ans;
    ans.left = ans.res = ans.right = 0;
    int tmp = min(b.left, d.right);
    ans.res = b.res + d.res + 2*tmp;
    ans.left = b.left + d.left - tmp;
    ans.right = b.right + d.right - tmp;
    return ans;
}

void update(int id, int l, int r, int i)
{
    if(i < l || i > r)
        return;
    if(l == r)
    {
        if(s[i] == ')')
            stree[id].right++;
        else
            stree[id].left++;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, i);
    update(id*2+1, mid+1, r, i);
    int tmp = min(stree[id*2].left, stree[id*2+1].right);
    stree[id] = stree[id*2] + stree[id*2+1];
}

node get(int id, int l, int r, int u, int v)
{
    node ans;
    ans.left = ans.res = ans.right = 0;
    if(l > v || r < u)
        return ans;
    if(u <= l && r <= v)
        return stree[id];
    int mid = (l+r)/2;
    ans = get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
    return ans;
}

int main()
{
    ///freopen("Sereja and Brackets.inp", "r", stdin);
    ///freopen("Sereja and Brackets.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    cin >> q;
    n = s.size();
    s = '#'+s;
    for(int i = 1; i <= n; i++)
        update(1,1,n,i);
    while(q--)
    {
        cin >> u >> v;
        cout << get(1,1,n,u,v).res << endl ;
    }
}
