#include <bits/stdc++.h>

using namespace std;
int const mn = 1e6, oo = 1e9;
int n, q, u, v;
int stree[mn], b[mn];
void update(int id, int l, int r, int i, int v)
{
    if(i < l || i > r)
        return;
    if(l == r)
    {
        stree[id] = v;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, i, v);
    update(id*2+1, mid+1, r, i, v);
    stree[id] = max(stree[id*2], stree[id*2+1]);
}

int get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u)
        return -oo;
    if(u <= l && r <= v)
        return stree[id];
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}
int main()
{
    freopen("segment tree.inp", "r", stdin);
    ///freopen("segment tree.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        update(1,1,n,i,b[i]);
    for(int i = 1; i <= q; i++)
    {
        cin >> u >> v;
        cout << get(1,1,n,u,v) << endl;
    }
}
