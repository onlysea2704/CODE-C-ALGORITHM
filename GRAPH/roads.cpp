#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define fi first
#define se second
using namespace std;
int const oo = 1e9;
int m, n, k, u, v, l, t, w, x, ans, q;
int d[101][10001];
vector<pip> g[101];
void dijkstra()
{
    priority_queue<pip, vector<pip>, greater<pip>> pq;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++)
            d[i][j] = oo;
    d[1][0] = 0;
    pq.push({0,{1,0}});
    while(!pq.empty())
    {
        w = pq.top().fi, u = pq.top().se.fi, x = pq.top().se.se, pq.pop();
        if(d[u][x] != w)
            continue;
        for(pip z:g[u])
        {
            v = z.fi, l = z.se.fi, t = z.se.se;
            if(x+t <= k && d[v][x+t] > d[u][x]+l)
            {
                d[v][x+t] = d[u][x]+l;
                pq.push({d[v][x+t],{v,x+t}});
            }
        }
    }

}

int main()
{
    ///freopen("roads.inp", "r", stdin);
    ///freopen("roads.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> q;
    while(q--)
    {
        ans = oo;
        cin >> k >> n >> m;
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v >> l >> t;
            g[u].push_back({v,{l,t}});
        }
        dijkstra();
        for(int i = 1; i <= n; i++)
            g[i].clear();
        for(int i = 0; i <= k; i++)
            ans = min(ans, d[n][i]);
        if(ans == oo)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
