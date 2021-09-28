#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans, x, n;
int const maxn = 60011;
int a[maxn], b[maxn];
mt19937 rng(time(0));

int get(int id)
{
    int res = 0;
    while(id > 0)
    {
        res += a[id];
        id = id - (id & (-id));
    }
    return res;
}

void update(int id)
{
    while(id <= maxn)
    {
        a[id]++;
        id = id + (id & (-id));
    }
}

int32_t main()
{
    ///freopen("nkinv.inp",  "r", stdin);
    ///freopen("nkinv.out", "w", stdout);    vnoi
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = n; i >= 1; i--)
    {
        ans += get(b[i]-1);
        update(b[i]);
    }
    cout << ans;
}
