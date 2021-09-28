#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, mod;
struct matrix
{
    int mt[4][4];
};
matrix a, f;
matrix nmt(matrix a, matrix b, int m, int n, int p)
{
    matrix c;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= p; j++)
    {
        c.mt[i][j] = 0;
        for(int k = 1; k <= n; k++)
            c.mt[i][j] = (c.mt[i][j] + (a.mt[i][k]*b.mt[k][j]) % mod) % mod;
    }
     return c;
}
matrix po(matrix a, int b)
{
    if(b == 1)
        return a;
    matrix c = po(a, b/2);
    c = nmt(c, c, 3, 3, 3);
    if(b % 2 == 1)
       c = nmt(c, a, 3, 3, 3);
    return c;
}
int main()
{
   freopen("loco.inp","r",stdin);
   freopen("loco.out","w",stdout);
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   cin >> n >> mod;
   a.mt[1][1] = 1, a.mt[1][2] = 1, a.mt[1][3] = 1;
   a.mt[2][1] = 1, a.mt[2][2] = 0, a.mt[2][3] = 0;
   a.mt[3][1] = 0, a.mt[3][2] = 1, a.mt[3][3] = 0;
   f.mt[1][1] = 4, f.mt[2][1] = 2, f.mt[3][1] = 1;
   a = po(a, n - 3);
   a = nmt(a, f, 3, 3, 1);
   cout << a.mt[1][1];
}
