#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e3+11;
int m, n, a[maxn][maxn], dp1[maxn], dp2[maxn], u, res;
int main()
{
    ///freopen("qbrect.inp", "r", stdin);     vnoi
    ///freopen("qbrect.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
                a[i][j] += a[i-1][j];
        }
    for(int i = 1; i <= m; i++)
    {
        stack <int> st1, st2;
        dp1[1] = 0, st1.push(1), dp2[n] = n+1, st2.push(n);
        for(int j = 2; j <= n; j++)
        {
            u = st1.top();
            while(a[i][u] >= a[i][j])
            {
                st1.pop();
                if(st1.size() == 0)
                {
                    u = 0;
                    break;
                }
                u = st1.top();
            }

            dp1[j] = u;
            st1.push(j);
        }
        for(int j = n-1; j >= 1; j--)
        {
            u = st2.top();
            while(a[i][u] >= a[i][j])
            {
                st2.pop();
                if(st2.size() == 0)
                {
                    u = n+1;
                    break;
                }
                u = st2.top();
            }
            dp2[j] = u;
            st2.push(j);
        }
        for(int j = 1; j <= n; j++)
            res = max(res, (dp2[j]-dp1[j]-1)*a[i][j]);
    }
    cout << res;
}
