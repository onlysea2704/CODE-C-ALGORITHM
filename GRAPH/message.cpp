#include <bits/stdc++.h>

using namespace std;
int const maxn = 888;
int m, n, u, v, tmp;
int dd[maxn], ans[maxn];
vector<int> g[maxn];
void dfs(int u)
{
    dd[u] = 1;
    for(int v:g[u])
        if(dd[v] == 0)
        {
            dfs(v);
            ans[v] = 1;
        }
}

int main()
{
    freopen("message.inp", "r", stdin);
    ///freopen("mmessage.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(ans[i] == 0)
        {
            for(int j = 1; j <= n; j++)
                dd[j] = 0;
            dfs(i);
        }
    for(int i = 1; i <= n; i++)
        tmp += ans[i];
    cout << n - tmp;

}
