#include <bits/stdc++.h>
#define int long long
using namespace std;
int const maxn = 1e5;
int n, x, ans, cnt;
int dad[maxn];
struct edge
{
    int u, v, w;
};
edge g[maxn];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
int findd(int u)
{
    if(u != dad[u])
        dad[u] = findd(dad[u]);
    return dad[u];
}

bool join(int u, int v)
{
    u = findd(u), v = findd(v);
    if(u == v)
        return false;
    dad[u] = v;
    return true;
}
main()
{
    ///freopen("fwater.inp", "r", stdin);
    ///freopen("fwater.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        g[i].u = 0, g[i].v = i, g[i].w = x;
    }
    cnt = n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> x;
            if(j > i)
                g[++cnt].u = i, g[cnt].v = j, g[cnt].w = x;
        }

    for(int i = 0; i <= n; i++)
        dad[i] = i;
    sort(g+1, g+cnt+1, cmp);
    for(int i = 1; i <= cnt; i++)
        if(join(g[i].u, g[i].v))
            ans += g[i].w;
    cout << ans;
}
