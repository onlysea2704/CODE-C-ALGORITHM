#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e4+11;
stack<int> st;
int m, n, u, v, cnt, tmp;
int num[maxn], low[maxn], sc[maxn];
vector<int> g[maxn], ans[maxn];
void dfs(int u)
{
    num[u] = low[u] = ++tmp;
    st.push(u);
    for(int v:g[u])
        if(num[v] == 0)
        {
            dfs(v);
            low[u] = min(low[v],low[u]);
        }
        else
        {
            if(sc[v] == 0)
                low[u] = min(low[u], num[v]);
        }
    if(num[u] == low[u])
    {
        int v;
        cnt++;
        do
        {
            v = st.top(), st.pop();
            ans[cnt].push_back(v);
            sc[v] = cnt;
        }
        while(u != v);
    }
}
int main()
{
    freopen("strongly connected.inp", "r", stdin);
    ///freopen("strongly connected.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(num[i] == 0)
            dfs(i);
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
