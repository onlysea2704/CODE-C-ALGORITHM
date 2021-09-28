#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e4+11;
int p, u, v, z;
int dad[maxn];
int findd(int u)
{
    if(u != dad[u])
        dad[u] = findd(dad[u]);
    return dad[u];
}

bool check(int u, int v)
{
    u = findd(u), v = findd(v);
    if(u == v)
        return true;
    return false;
}

void join(int u, int v)
{
    u = findd(u), v =findd(v);
    dad[u] = v;
}

int main()
{
    freopen("ioibin.inp", "r", stdin);
    ///freopen("ioibin.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> p;
    for(int i = 1; i <= maxn; i++)
        dad[i] = i;
    for(int i = 1; i <= p; i++)
    {
        cin >> u >> v >> z;
        if(z == 2)
        {
            if(check(u,v))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else
            join(u,v);
    }
}
