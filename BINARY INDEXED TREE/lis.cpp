#include <bits/stdc++.h>

using namespace std;
int const maxn = 30011;
int ans, n, dp[maxn], x, btree[maxn], tmp[maxn], b[maxn], a[maxn];

void press() //nén
{
    sort(tmp + 1, tmp + n + 1);
    for(int i = 1; i <= n; i++)
        b[i] = lower_bound(tmp + 1, tmp + n + 1, a[i]) - tmp;
}

void update(int id, int val)
{
    while(id <= maxn)
    {
        btree[id] = max(btree[id], val);
        id = id + (id & (-id));
    }
}

int get(int id)
{
    int res = 0;
    while(id > 0)
    {
        res = max(res, btree[id]);
        id = id - (id & (-id));
    }
    return res;
}

int main()
{
    ///freopen("lis.inp", "r", stdin);
    ///freopen("lis.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp[i];
        a[i] = tmp[i];
    }
    press();
    for(int i = 1; i <= n; i++)
    {
        dp[i] = get(b[i]-1) + 1;
        update(b[i],dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
