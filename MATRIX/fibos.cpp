#include <bits/stdc++.h>

using namespace std;
int n;

struct matrix
{
    int mt[11][11];
};
matrix fi, ans;
matrix multiplymatrix(matrix a, matrix b)
{
    matrix c;
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++)
        {
            c.mt[i][j] = 0;
            for(int k = 1; k <= 2; k++)
                c.mt[i][j] += a.mt[i][k]*b.mt[k][j];
        }
    return c;
}

matrix po(matrix a, int b)

{
    if(b == 1)
        return a;
    matrix c = po(a, b/2);
    c = multiplymatrix(c,c);
    if(b % 2 != 0)
        c = multiplymatrix(c,a);
    return c;
}

int main()
{
    freopen("fibos.inp", "r", stdin);
    ///freopen("fibos.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    fi.mt[1][1] = 0, fi.mt[1][2] = 1;
    fi.mt[2][1] = 1, fi.mt[2][2] = 1;
    ans.mt[1][1] = 1, ans.mt[1][2] = 0;
    ans.mt[2][1] = 2, ans.mt[2][2] = 0;
    fi = po(fi,n-1);
    ans = multiplymatrix(fi,ans);
    cout << ans.mt[1][1];
}
