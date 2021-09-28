#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const maxn = 555, oo = 1e9;
int p, n, c, u, v, w, ans;
double sum, tmp = 1e9;
int a[maxn], d[maxn][maxn];
vector<pii> g[maxn];
void dijkstra(int root)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= p; i++)
        d[root][i] = oo;
    d[root][root] = 0,pq.push({0,root});
    while(!pq.empty())
    {
        w = pq.top().fi, u = pq.top().se, pq.pop();
        if(d[root][u] != w)
            continue;
        for(pii x:g[u])
        {
            w = x.fi, v = x.se;
            if(d[root][v] > d[root][u]+w)
            {
                d[root][v] = d[root][u]+w;
                pq.push({d[root][v],v});
            }
        }
    }
}

int main()
{
    ///freopen("bestspot.inp", "r", stdin);
    ///freopen("bestspot.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> p >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= c; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    for(int i = 1; i <= n; i++)
    {
        dijkstra(a[i]);
    }
    for(int i = 1; i <= p; i++)
    {
        sum = 0;
        for(int j = 1; j <= n; j++)
            sum += d[a[j]][i];
        if(tmp > sum/n)
            ans = i, tmp = sum/n;
    }
    cout << ans;

}
