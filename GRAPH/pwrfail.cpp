#include <bits/stdc++.h>
#define pdi pair<double,int>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const maxn = 1005;
double const oo = 1e9;
int n, w, x, y, u, v;
double l, m, d[maxn];
int dd[maxn][maxn];
pii a[maxn];
vector<pdi> g[maxn];
void dijkstra()
{
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    for(int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = 0, pq.push({0,1});
    while(!pq.empty())
    {
        l = pq.top().fi, u = pq.top().se, pq.pop();
        if(d[u] != l)
            continue;
        for(pdi z:g[u])
        {
            l = z.fi, v = z.se;
            if(d[v] > d[u] + l)
            {
                d[v] = d[u]+l;
                pq.push({d[v],v});
            }
        }
    }
}

double length(int u, int v)
{
    double x1 = a[u].fi, y1 = a[u].se, x2 = a[v].fi, y2 = a[v].se;
    double tmp1 = x1-x2, tmp2 = y1-y2;
    return sqrt(tmp1*tmp1 + tmp2*tmp2);
}
int main()
{
    ///freopen("pwrfail.inp", "r", stdin);
    ///freopen("pwrfail.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> w >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a[i] = {x,y};
    }
    for(int i = 1; i <= w; i++)
    {
        cin >> u >> v;
        g[u].push_back({0,v});
        g[v].push_back({0,u});
        dd[u][v] = dd[v][u] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(dd[i][j] == 0)
            {
                l = length(i,j);
                if(l <= m)
                {
                    g[i].push_back({l,j});
                    g[j].push_back({l,i});
                }
            }
    dijkstra();
    if(d[n] == oo)
        cout << -1;
    else
        cout << int(d[n]*1000);
}
