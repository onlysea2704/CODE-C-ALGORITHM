#include <bits/stdc++.h>

using namespace std;
int const maxn = 5*1e4+11;
int n, a[maxn], m, x, y;
struct node
{
    int maxall, maxleft, maxright, sumall;
};
node segmentree[maxn*4];

void update(int id, int left, int right, int i)
{
    if(i < left || i > right)
        return;
    if(left == right)
    {
        segmentree[id].maxall = a[i];
        segmentree[id].sumall = a[i];
        segmentree[id].maxleft = a[i];
        segmentree[id].maxright = a[i];
        return;
    }
    int mid = (left+right)/2;
    update(id*2,left,mid,i);
    update(id*2+1,mid+1,right,i);
    segmentree[id].maxleft = max(segmentree[id*2].maxleft, segmentree[id*2].sumall+segmentree[id*2+1].maxleft);
    segmentree[id].maxright = max(segmentree[id*2+1].maxright, segmentree[id*2+1].sumall+segmentree[id*2].maxright);
    segmentree[id].maxall = max(max(segmentree[id*2].maxall, segmentree[id*2+1].maxall),segmentree[id*2].maxright+segmentree[id*2+1].maxleft);
    segmentree[id].sumall = segmentree[id*2].sumall + segmentree[id*2+1].sumall;
}

node get(int id, int left, int right, int u, int v)
{
    node tmp, tmp1, tmp2;
    if(u > right || v < left)
        return segmentree[0];
    if(u <= left && right <= v)
        return segmentree[id];
    int mid = (left+right)/2;
    tmp1 = get(id*2,left,mid,u,v);
    tmp2 = get(id*2+1,mid+1,right,u,v);
    tmp.maxleft = max(tmp1.maxleft, tmp1.sumall+tmp2.maxleft);
    tmp.maxright = max(tmp2.maxright, tmp2.sumall+tmp1.maxright);
    tmp.maxall = max(max(tmp1.maxall,tmp2.maxall),tmp1.maxright+tmp2.maxleft);
    tmp.sumall = tmp1.sumall+tmp2.sumall;
    return tmp;
}

int main()
{
    ///freopen("gss.inp", "r", stdin);
    ///freopen("gss.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    segmentree[0].maxall = segmentree[0].maxleft = segmentree[0].maxright = -1e9;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1,1,n,i);
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        node res = get(1,1,n,x,y);
        cout << res.maxall << endl;
    }
}
