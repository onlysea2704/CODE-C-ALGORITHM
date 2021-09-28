#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e4;
int dd[maxn];
vector<int> g[maxn], ans;
int m, n, u, v, st, en;
queue<int> qu;
void dfs(int u)
{
    dd[u] = 1;
    ans.push_back(u);
    if(u == en)
    {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
        dd[u] = 0;
        ans.pop_back();
        return;
    }
    for(int v:g[u])
        if(dd[v] == 0)
            dfs(v);
    dd[u] = 0;
    ans.pop_back();
}

int main()
{
    freopen("dfs basic.inp", "r", stdin);
    ///freopen("dfs basic.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i<= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> st >> en;
    dfs(st);
}
