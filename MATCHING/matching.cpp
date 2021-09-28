#include <bits/stdc++.h>

using namespace std;
int const maxn = 111;
int cur, m, n, u, v, ans;
int match[maxn], use[maxn];
vector<int> g[maxn];

bool dfs(int u)
{
    if(use[u] == cur)
        return false;
    use[u] = cur;
    for(int v:g[u])
        if(match[v] == 0 || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    return false;
}

int main()
{
    ///freopen("matching.inp", "r", stdin);   // match1 vnoj
    ///freopen("matching.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    while(cin >> u)
    {
        cin >> v;
        g[u].push_back(v);
    }
    for(cur = 1; cur <= n; cur++)
        if(dfs(cur))
            ans++;
    cout << ans << endl;
    for(int i = 1; i <= m; i++)
        if(match[i] != 0)
            cout << match[i] << " " << i << endl;
}
