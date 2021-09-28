#include <bits/stdc++.h>
#define int long long
using namespace std;
int const maxn = 1e4;
int u, v, n, m, cnt, bridge, ans;
int num[maxn], low[maxn], son[maxn], dd[maxn];
vector<int> g[maxn];
int d[maxn][3];
void dfs(int u, int dad)
{
    num[u] = low[u] = ++cnt;
    for(int v:g[u])
        if(v != dad)
            if(num[v] == 0)
            {
                dfs(v,u);
                son[u] += son[v];
                low[u] = min(low[v],low[u]);
                if(low[v] >= num[v])
                    d[++bridge][1] = u, d[bridge][2] = v;
            }
            else
                low[u] = min(low[u],num[v]);
}
void dfs2(int u)
{
    for(int v:g[u])
        if(dd[v] == 0)
        {
            dd[v] = dd[u];
            dfs2(v);
        }
}

int32_t main()
{
    ///freopen("weather.inp", "r", stdin);
    ///freopen("weather.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i<= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        son[i] = 1;
    for(int i = 1; i <= n; i++)
        if(num[i] == 0)
            dfs(i,i);
    for(int i = 1; i <= n; i++)
        if(dd[i] == 0)
        {
            dd[i] = son[i];
            dfs2(i);
        }
    for(int i = 1; i <= bridge; i++)
    {
        u = d[i][1], v = d[i][2];
        ///cout << u << " " << v << endl;
        ans += son[v]*(dd[u]-son[v]);
    }
    cout << ans;

}
