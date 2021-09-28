#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const maxn = 711;
int m, n, cnt, nrow, ncol, h, k, z, ans;
int dd[maxn][maxn], a[maxn][maxn];
int row[8] = {-1,-1,0,1,1,1,0,-1};
int col[8] = {0,1,1,1,0,-1,-1,-1};
queue<pii> qu;
struct st
{
    int v, x, y;
};
st b[maxn*maxn];
bool tmp(st a, st b)
{
    return a.v > b.v;
}
int main()
{
    ///freopen("nkguard.inp", "r", stdin);
    ///freopen("nkguard.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            cnt++;
            b[cnt].v = a[i][j];
            b[cnt].x = i;
            b[cnt].y = j;
        }
    sort(b+1, b+1+m*n, tmp);
    for(int i = 1; i <= m*n; i++)
    {
        h = b[i].x, k = b[i].y, z = b[i].v;
        if(dd[h][k] == 0)
        {
            ans++;
            qu.push(make_pair(h,k));
            dd[h][k] = 1;
            while(!qu.empty())
            {
                h = qu.front().fi, k = qu.front().se, qu.pop();
                for(int i = 0; i < 8; i++)
                {
                    nrow = h + row[i], ncol = k + col[i];
                    if(nrow >= 1 && nrow <= m && ncol >= 1 && ncol <= n)
                        if(a[nrow][ncol] <= a[h][k] && dd[nrow][ncol] == 0)
                        {
                            qu.push(make_pair(nrow,ncol));
                            dd[nrow][ncol] = 1;
                        }
                }
            }
        }
    }
    cout << ans;
}
