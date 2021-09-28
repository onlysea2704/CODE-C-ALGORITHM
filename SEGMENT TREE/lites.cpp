#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5+11;
int m,n,u,v,tf;

struct node
{
    int val, lazy;
};
node stree[maxn*4];

void down(int id, int l, int r)
{
    stree[id*2].lazy += stree[id].lazy;
    stree[id*2+1].lazy += stree[id].lazy;
    if(stree[id].lazy % 2 != 0)
    {
        int mid = (l+r)/2;
        stree[id*2].val = mid-l+1-stree[id*2].val;
        stree[id*2+1].val = r-mid-stree[id*2+1].val;
    }
    stree[id].lazy = 0;
}

int get(int id, int l, int r, int u, int v)
{
    if(u > r || v < l)
        return 0;
    down(id,l,r);
    if(u <= l && r <= v)
        return stree[id].val;
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void update(int id, int l, int r, int u, int v)
{
    if(u > r || v < l)
        return;
    down(id,l,r);
    if(u <= l && r <= v)
    {
        stree[id].val = (r-l+1)-stree[id].val;
        stree[id].lazy++;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    stree[id].val = stree[id*2].val + stree[id*2+1].val;
}

int main()
{
    ///freopen("lites.inp", "r", stdin);
    ///freopen("lites.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> tf >> u >> v;
        if(tf == 0)
            update(1,1,n,u,v);
        else
            cout << get(1,1,n,u,v) << '\n';
    }
}
