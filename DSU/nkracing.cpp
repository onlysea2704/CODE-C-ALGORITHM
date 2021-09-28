#include<bits/stdc++.h>
using namespace std;
int const maxn = 100000+11;
int n, m, ans;
int dad[maxn];
struct edge
{
    int u, v, w;
};
edge g[maxn];
bool cmp(edge a, edge b)
{
    return a.w > b.w;
}
int findd(int u)
{
    if( u != dad[u])
        dad[u] = findd(dad[u]);
    return dad[u];
}
bool join(int u, int v)
{
    u = findd(u), v = findd(v);
    if(u == v)
        return false;
    dad[u] = v;
    return true;
}
int main()
{
    ///freopen("nkracing.inp", "r", stdin);
    ///freopen("nkracing.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        dad[i] = i;
    for(int i = 1; i <= m; i++)
        cin >> g[i].u >> g[i].v >> g[i].w;
    sort(g+1, g+m+1,cmp);
    for(int i = 1; i <= m; i++)
        if(!join(g[i].u, g[i].v))
            ans += g[i].w;
    cout << ans;

}
