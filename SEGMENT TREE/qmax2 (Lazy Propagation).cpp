#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val, lazy;
};
int const mn = 50005*4;
node stree[mn];
int n, q, u, v, tf, k;
void down(int id)
{
    int t = stree[id].lazy;
    stree[id*2].lazy += t;
    stree[id*2+1].lazy += t;
    stree[id*2].val += t;
    stree[id*2+1].val += t;
    stree[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int k)
{
    if(r < u || l > v)
        return;
    if(u <= l && r <= v)
    {
        stree[id].val += k;
        stree[id].lazy += k;
        return;
    }
    down(id);
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,k);
    update(id*2+1,mid+1,r,u,v,k);
    stree[id].val = max(stree[id*2].val, stree[id*2+1].val);
}
int get(int id, int l, int r, int u, int v)
{
    if(r < u || l > v)
        return 0;
    if(u <= l && r <= v)
        return stree[id].val;
    down(id);
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

int main()
{
    ///freopen("qmax2.inp", "r", stdin);   vnoi
    ///freopen("qmax2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> tf;
        if(tf == 0)
        {
            cin >> u >> v >> k;
            update(1,1,n,u,v,k);
        }
        else
        {
            cin >> u >> v;
            cout << get(1,1,n,u,v) << endl;
        }
    }
}
