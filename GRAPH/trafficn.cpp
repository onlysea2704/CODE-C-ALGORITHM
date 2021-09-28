#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const maxn = 1e4+11, oo = 1e9;
int q, m, n, k, s, t, u, v , w, ans;
int d1[maxn], d2[maxn];
vector<pii> g1[maxn], g2[maxn];
void dijkstra1()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= n; i++)
        d1[i] = oo;
    d1[s] = 0, pq.push({0,s});
    while(!pq.empty())
    {
        w = pq.top().fi, u = pq.top().se, pq.pop();
        if(d1[u] != w)
            continue;
        for(pii x:g1[u])
        {
            w = x.fi, v = x.se;
            if(d1[v] > d1[u]+w)
            {
                d1[v] = d1[u]+w;
                pq.push({d1[v],v});
            }
        }
    }
}

void dijkstra2()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= n; i++)
        d2[i] = oo;
    d2[t] = 0, pq.push({0,t});
    while(!pq.empty())
    {
        w = pq.top().fi, u = pq.top().se, pq.pop();
        if(d2[u] != w)
            continue;
        for(pii x:g2[u])
        {
            w = x.fi, v = x.se;
            if(d2[v] > d2[u]+w)
            {
                d2[v] = d2[u]+w;
                pq.push({d2[v],v});
            }
        }
    }
}

int main()
{
    ///freopen("trafficn.inp", "r", stdin);
    ///freopen("trafficn.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n >> m >> k >> s >> t;
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            g1[u].push_back({w,v});
            g2[v].push_back({w,u});
        }
        dijkstra1(),dijkstra2();
        for(int i = 1; i <= n; i++)
            g1[i].clear(), g2[i].clear();
        ans = d1[t];
        for(int i = 1; i <= k; i++)
        {
            cin >> u >> v >> w;
            ans = min(ans, d1[u]+d2[v]+w);
            ans = min(ans, d1[v]+d2[u]+w);
        }
        if(ans == oo)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
