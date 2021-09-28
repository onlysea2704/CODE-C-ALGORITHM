#include <bits/stdc++.h>

using namespace std;
int n, dad[33], ans, u, v;
string s, t;
char a[1000001][3];
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
    ///freopen("Love Rescue.inp", "r", stdin);
    ///freopen("Love Rescue.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> s >> t;
    s = '#' + s, t = '#' + t;
    for(int i = 0; i <= 30; i++)
        dad[i] = i;
    for(int i = 1; i < s.size(); i++)
    {
        u = int(s[i])-97, v = int(t[i])-97;
        if(join(u,v))
        {
            ans++;
            a[ans][1] = s[i], a[ans][2] = t[i];
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= ans; i++)
        cout << a[i][1] << " " << a[i][2] << endl;
}
