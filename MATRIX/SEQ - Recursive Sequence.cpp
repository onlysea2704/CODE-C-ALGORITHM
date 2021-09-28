#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int mod = 1e9, t, n, k;
int b[11];
struct matrix
{
    int mt[11][11];
};
matrix c, a, ans;
matrix multiplymatrix(matrix a, matrix b, int nn)
{
    matrix f;
    for(int i = 1; i <= nn; i++)
        for(int j = 1; j <= nn; j++)
        {
            f.mt[i][j] = 0;
            for(int u = 1; u <= nn; u++)
                f.mt[i][j] = (f.mt[i][j] + (a.mt[i][u] * b.mt[u][j])%mod)%mod;
        }
    return f;
}

matrix po(matrix a, int b)
{
    if(b == 1)
        return a;
    matrix f = po(a,b/2);
    f = multiplymatrix(f,f,n);
    if(b % 2 != 0)
        f = multiplymatrix(f,a,n);
    return f;
}
int32_t main()
{
    ///freopen("SEQ - Recursive Sequence.inp", "r", stdin); // SPOJ
    ///freopen("SEQ - Recursive Sequence.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
            a.mt[n-i+1][1] = b[i];
        }
        for(int i = 1; i <= n; i++)
            for(int j = 2; j <= n; j++)
                a.mt[i][j] = 0;

        for(int i = 1; i <= n; i++)
            cin >> c.mt[1][i];

        cin >> k;

        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i - j == 1)
                    c.mt[i][j] = 1;
                else
                    c.mt[i][j] = 0;
        if(k <= n)
        {
            cout << b[k] << endl;
            continue;
        }

        ans = po(c,k-n);
        ans = multiplymatrix(ans,a,n);
        cout << ans.mt[1][1] << endl;
    }
}
