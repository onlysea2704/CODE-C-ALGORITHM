#include <bits/stdc++.h>

using namespace std;
int const mn = 222222;
int n, q, u, v, k;
int d[mn], stree[mn], ans[mn];
pair <int,int> b[mn];
struct query
{
    int left, right, k, st;
};
query h[222222];

bool tmp(query b, query d)
{
    return b.k < d.k;
}
void update(int id, int l, int r, int i, int v)
{
    if(i > r || i < l)
        return;
    if(l == r)
    {
        stree[id] = v;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,i,v);
    update(id*2+1,mid+1,r,i,v);
    stree[id] = stree[id*2] + stree[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u)
        return 0;
    if(u <= l && r <= v)
        return stree[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

int main()
{
    ///freopen("K-query.inp", "r", stdin);
    ///freopen("K-query.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> h[i].left >> h[i].right >> h[i].k;
        h[i].st = i;
    }
    sort(h+1, h+q+1, tmp);
    sort(b+1, b+n+1);
    for(int i = 1; i <= n; i++)
        update(1,1,n,i,1);
    int j = 1;
    for(int i = 1; i <= q; i++)
    {
        while(b[j].first <= h[i].k && j <= n)
        {
            update(1,1,n,b[j].second,0);
            ///cout << b[j].second << endl;
            j++;
        }
        ans[h[i].st] = get(1,1,n,h[i].left,h[i].right);
    }
    for(int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}
