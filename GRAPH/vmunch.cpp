#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const maxn = 111;
int row[4] = {-1,0,1,0};
int col[4]  = {0,1,0,-1};
queue<pii> qu;
pii st, en;
int m, n, nrow, ncol, u, v;
char a[maxn][maxn];
int dd[maxn][maxn];
int main()
{
    ///freopen("vmunch.inp", "r", stdin);
    ///freopen("vmunch.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'C')
                st = {i,j};
            if(a[i][j] == 'B')
                en = {i,j};
        }
    qu.push(st);
    dd[st.fi][st.se] = 1;
    while(qu.front() != en)
    {
        u = qu.front().fi, v = qu.front().se, qu.pop();
        for(int i = 0; i < 4; i++)
        {
            nrow = u+row[i];
            ncol = v+col[i];
            if(nrow >= 1 && ncol >= 1 && nrow <= m && ncol <= n)
                if(dd[nrow][ncol] == 0 && a[nrow][ncol] != '*' )
                {
                    dd[nrow][ncol] = dd[u][v]+1;
                    qu.push({nrow,ncol});
                }
        }
    }
    cout << dd[en.fi][en.se]-1;
}
