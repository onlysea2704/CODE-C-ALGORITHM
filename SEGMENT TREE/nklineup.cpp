#include <bits/stdc++.h>

using namespace std;
int const oo = 1e8, maxn = 51111;
int n,q,u,v, a[maxn];

struct node
{
    int minn, maxx;
};
node segmentree[maxn*4];

int getmin(int id, int left, int right, int u, int v)
{
    if(u > right || v < left)
        return oo;
    if(u <= left && right <= v)
        return segmentree[id].minn;
    int mid = (left+right)/2;
    return min(getmin(id*2,left,mid,u,v), getmin(id*2+1,mid+1,right,u,v));
}

int getmax(int id, int left, int right, int u, int v)
{
    if(u > right || v < left)
        return -oo;
    if(u <= left && right <= v)
        return segmentree[id].maxx;
    int mid = (left+right)/2;
    return max(getmax(id*2,left,mid,u,v), getmax(id*2+1,mid+1,right,u,v));
}


void update(int id, int left, int right, int i)
{
    if(i < left || i > right)
        return;
    if(left == right)
    {
        segmentree[id].maxx = a[i];
        segmentree[id].minn = a[i];
        return;
    }
    int mid = (left+right)/2;
    update(id*2,left, mid,i);
    update(id*2+1,mid+1,right,i);
    segmentree[id].minn = min(segmentree[id*2].minn, segmentree[id*2+1].minn);
    segmentree[id].maxx = max(segmentree[id*2].maxx, segmentree[id*2+1].maxx);
}

int main()
{
    ///freopen("nklineup.inp", "r", stdin);
    ///freopen("nklineup.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1,1,n,i);
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> u >> v;
        cout << getmax(1,1,n,u,v) - getmin(1,1,n,u,v) << endl;
    }
}
