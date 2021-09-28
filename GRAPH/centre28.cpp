#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const maxn = 30011, oo = 1e9;
int n, m, u, v, w, res;
int d[maxn], ans[maxn], dd[maxn];
vector<pii> g[maxn];
void dfs(int u)
{
    dd[u] = 1;
    if(u == n)
    {
        for(int i = 1; i <= n; i++)
            if(dd[i] == 0)
                ans[i] = 1;
        dd[n] = 0;
        return;
    }
    for(pii x:g[u])
    {
        v = x.fi, w = x.se;
        if(dd[v] == 0 && d[v] == d[u]+w)
            dfs(v);
    }
    dd[u] = 0;
}
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = 0, pq.push({0,1});
    while(!pq.empty())
    {
        w = pq.top().fi, u = pq.top().se, pq.pop();
        if(d[u] != w)
            continue;
        for(pii x: g[u])
        {
            v = x.fi, w = x.se;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
}

int main()
{
    ///freopen("centre28.inp", "r", stdin);
    ///freopen("centre28.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra();
    dfs(1);
    for(int i = 1; i <= n; i++)
        res += ans[i];
    cout << res << endl;
    for(int i = 1; i <= n; i++)
        if(ans[i] == 1)
            cout << i << endl;

}
