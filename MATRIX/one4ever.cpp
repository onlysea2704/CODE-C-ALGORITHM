#include<bits/stdc++.h>
#define int long long
using namespace std;
int a, b, mod, k, t;
struct matrix
{
    int mt[4][4];
};
matrix d, f;
matrix nmt(matrix a, matrix b, int m, int n, int p)
{
    matrix c;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= p; j++)
        {
            c.mt[i][j] = 0;
            for(int k = 1; k <= n; k++)
                c.mt[i][j] = (c.mt[i][j] + (a.mt[i][k]*b.mt[k][j]) %mod) % mod;
        }
    return c;
}
matrix po(matrix a, int b)
{
    if(b == 1)
        return a;
    matrix c = po(a, b/2);
    c = nmt(c,c,2,2,2);
    if(b % 2 != 0)
        c = nmt(c,a,2,2,2);
    return c;
}
int32_t main()
{
    freopen("ONE4EVER.inp","r",stdin);
    freopen("ONE4EVER.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    for(int t1 = 1; t1 <= t; t1++)
    {
        cin >> a >> b >> mod >> k;
        if(k == 1)
        {
            cout << b % mod << endl;
            continue;
        }
        d.mt[1][1] = a, d.mt[1][2] = 1;
        d.mt[2][1] = 0, d.mt[2][2] = 1;
        f.mt[1][1] = b % mod, f.mt[2][1] = b;
        d = po(d, k - 1);
        d = nmt(d, f, 2, 2, 1);
        cout << d.mt[1][1] << endl;
    }
}
