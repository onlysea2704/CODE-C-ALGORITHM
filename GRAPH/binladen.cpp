#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const maxn = 1e5, oo = 1e15;
int m, n, u, v, w;
int d[maxn];
vector<pii> g[maxn];
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= m*n; i++)
        d[i] = oo;
    d[0] = 0, pq.push({0,0});
    while(!pq.empty())
    {
        w = pq.top().fi, u = pq.top().se, pq.pop();
        if(u == m*n)
            return;
        if(d[u] != w)
            continue;
        for(pii x:g[u])
        {
            v = x.fi, w = x.se;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
}

int32_t main()
{
    ///freopen("binladen.inp", "r", stdin);
    ///freopen("binladen.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> w;
        g[0].push_back({i,w});
    }
    for(int i = 1; i < n; i++)
    {
        cin >> w;
        g[i].push_back({i+1,w});
        g[i+1].push_back({i,w});
    }
    for(int i = 2; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> w;
            g[(i-2)*n+j].push_back({(i-1)*n+j,w});
            g[(i-1)*n+j].push_back({(i-2)*n+j,w});
        }
        for(int j = 1; j < n; j++)
        {
            cin >> w;
            g[(i-1)*n+j].push_back({(i-1)*n+j+1,w});
            g[(i-1)*n+j+1].push_back({(i-1)*n+j,w});
        }
    }
    dijkstra();
    cout << d[m*n];
}
