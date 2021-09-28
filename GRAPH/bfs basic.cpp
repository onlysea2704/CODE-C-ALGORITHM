#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
queue<pii> qu;
int const maxn = 1e4;
int n, m, u, v, st;
int dd[maxn];
vector<int> g[maxn];
int main()
{
    freopen("bfs basic.inp", "r", stdin);
    ///freopen("bfs basic.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> st;
    qu.push({st,0});
    dd[st] = 0;
    while(!qu.empty())
    {
        u = qu.front().fi, qu.pop();
        for(int v:g[u])
            if(dd[v] == 0 && v != st)
            {
                dd[v] = dd[u]+ 1;
                qu.push({v,dd[v]});
            }
    }
    for(int i = 1; i <= n; i++)
        cout << dd[i]<< endl;

}
