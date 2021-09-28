#include <bits/stdc++.h>

using namespace std;
int const maxn = 1111;
int n, cnt;
int dd[maxn], a[maxn][maxn], use[maxn];
vector<int>g[maxn];

int main()
{
    ///freopen("nktrio.inp", "r", stdin);
    ///freopen("nktrio.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j])
                g[i].push_back(j);
        }
    for(int i = 1; i <= n; i++)
        for(int j:g[i])
            for(int k:g[j])
                if(a[k][i])
                {
                    cout << i << " " << j << " " << k;
                    exit(0);
                }
    cout << -1 << " " << -1 << " " << -1;
}
