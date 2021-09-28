#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e4+11;
int n, m, u, v, nnode, bridge, cnt;
int num[maxn], low[maxn], node[maxn];
vector<int> g[maxn];
void dfs(int u, int dad)
{
    int son = 0;
    num[u] = low[u] = ++cnt;
    for(int v:g[u])
        if(v != dad)
            if(num[v] == 0)
            {
                dfs(v,u);
                son++;
                low[u] = min(low[u], low[v]);
                if(low[v] >= num[v])
                    bridge++;
                if(u == dad)
                {
                    if(son >= 2)
                        node[u] = 1;
                }
                else if(low[v] >= num[u])
                    node[u] = 1;
            }
            else
                low[u] = min(low[u],num[v]);
}

int main()
{
    ///freopen("graph.inp", "r", stdin);
    ///freopen("graph.out", "w", stdout);
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
        if(num[i] == 0)
            dfs(i,i);
    for(int i = 1; i <= n; i++)
        if(node[i] == 1)
           nnode++;
    cout << nnode << endl << bridge;



}
