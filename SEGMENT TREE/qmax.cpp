#include<bits/stdc++.h>
#define int long long
using namespace std;

int m,n,p,u,v,k;
int const maxn = 51111, oo = 1e12;
int segmentree[maxn*4], a[maxn], sum[maxn];

void update(int id, int left, int right, int i)
{
    if(i < left || i > right)
        return;
    if(left == right)
    {
        segmentree[id] = a[i];
        return;
    }
    int mid = (left+right)/2;
    update(id*2, left, mid, i);
    update(id*2+1, mid+1, right, i);
    segmentree[id] = max(segmentree[id*2], segmentree[id*2+1]);
}

int get(int id, int left, int right, int u, int v)
{
    if(right < u || left > v)
        return -oo;
    if(u <= left && right <= v)
        return segmentree[id];
    int mid = (left + right)/2;
    return max(get(id*2,left,mid,u,v), get(id*2+1,mid+1,right,u,v));
}

int32_t main()
{
    ///freopen("qmax.inp", "r", stdin);
    ///freopen("qmax.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> k;
        sum[u] += k;
        sum[v+1] -= k;
    }
    for(int i = 1; i <= n; i++)
    {
        sum[i] += sum[i-1];
        a[i] += sum[i];
    }
    for(int i = 1; i <= n; i++)
        update(1,1,n,i);
    cin >> p;
    for(int i = 1; i <= p; i++)
    {
        cin >> u >> v;
        cout << get(1,1,n,u,v) << endl;
    }
}
