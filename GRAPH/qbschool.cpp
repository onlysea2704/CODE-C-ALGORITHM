#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
int const maxn = 1e4, oo = 1e14;
int m, n, u, v, w, k;
int d[maxn], dd[maxn];
vector<pii> g[maxn];
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = 0, dd[1] = 1;
    pq.push({0,1});
    while(!pq.empty())
    {
        w = pq.top().fi, u = pq.top().se, pq.pop();
        if(d[u] != w)
            continue;
        for(pii x:g[u])
        {
            v = x.fi, w = x.se;
            if(d[v] >= d[u]+w)
            {
                if(d[v] > d[u]+w)
                {
                    d[v] = d[u]+w;
                    pq.push({d[v],v});
                    dd[v] = dd[u];
                }
                else
                    dd[v] += dd[u];
            }
        }
    }
}

int32_t main()
{
    ///freopen("qbschool.inp", "r", stdin);
    ///freopen("qbschool.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> k >> u >> v >> w;
        g[u].push_back({v,w});
        if(k == 2)
            g[v].push_back({u,w});
    }
    dijkstra();
    cout << d[n] << " " << dd[n];
}

