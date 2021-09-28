/*
cho m truy vấn k u v
nếu k == 0 thì xem u v có chung đỉnh hay không nếu không thì nối
nếu k == 1 thì nối u v
*/
#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e4;
int m, n, k, u, v;
int dad[maxn];
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

int main()
{
    freopen("dsu.inp", "r", stdin);
    ///freopen("dsu.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        dad[i] = i;
    for(int i = 1; i <= m;  i++)
    {
        cin >> k >> u >> v;
        if(k == 0)
        {
            if(join(u,v))
                cout << "no" << endl;
            else
                cout << "ok" << endl;
        }
        else
            join(u,v);
    }
}
