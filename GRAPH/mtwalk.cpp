#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const maxn= 105, oo = 1e4;
int n, minn = oo, maxx = -oo, l, r, mid, ans, x, y;
bool res;
int dd[maxn][maxn], a[maxn][maxn];
int row[4] = {-1,0,1,0};
int col[4] = {0,1,0,-1};

void dfs(int u, int v, int mi, int ma)
{
    if(a[u][v] < mi || a[u][v] > ma)
        return;
    if(u == n && v == n)
    {
        res = 1;
        return;
    }
    dd[u][v] = 1;
    for(int i = 0; i < 4; i++)
    {
        int h = u+row[i], k = v+col[i];
        if(h >= 1 && h <= n && k >= 1 && k <= n && !dd[h][k])
            if(a[h][k] >= mi && a[h][k] <= ma)
                dfs(h,k,mi,ma);
    }
}

bool check(int len)
{
    res = 0;
    for(int v = 0; v <= a[1][1]; v++)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dd[i][j] = 0;
        dfs(1,1,v,v+len);
    }
    return res;
}

int main()
{
    ///freopen("mtwalk.inp", "r", stdin);
    ///freopen("mtwalk.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            minn = min(minn,a[i][j]);
            maxx = max(maxx,a[i][j]);
        }
    l = 0, r = maxx-minn;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(check(mid))
            ans = mid, r = mid-1;
        else
            l = mid+1;
    }
    cout << ans;
}
