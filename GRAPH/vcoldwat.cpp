#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e5+11;
int n, m, e, u, v;
int d[maxn];
int g[maxn][3];
void dfs(int u)
{
    if(g[u][1] == 0)
        return;
    d[g[u][1]] = d[g[u][2]] = d[u] + 1;
    dfs(g[u][1]);
    dfs(g[u][2]);
}
int main()
{
    ///freopen("vcoldwat.inp", "r", stdin);
    ///freopen("vcoldwat.out", "w", stdout)
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> e >> u >> v;
        g[e][1] = u;
        g[e][2] = v;
    }
    d[1] = 1;
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << d[i] << endl;
}
