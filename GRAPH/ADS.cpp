#include <bits/stdc++.h>

using namespace std;
int const maxn = 2222;
vector<int> g[maxn];
int n, m, u, v, ans;
int use[maxn], dd[maxn];
void dfs(int u, int dad)
{
    use[u] = dd[u] = 1;
    for(int v:g[u])
    {
        if(v != dad)
            if(use[v] == 0)
                dfs(v,u);
            else
            {
                if(dd[v] == 1)
                ans++;
            }
    }
    dd[u] = 0;
}

int main()
{
    ///freopen("ADS.inp", "r", stdin);
    ///freopen("ADS.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(use[i] == 0)
            dfs(i,i);
    cout << ans;
}
