#include <iostream>
#define endl '\n'
#define int long long
using namespace std;
int mod = 111539786, n, t;
struct matrix
{
    int mt[4][4];
};
matrix fi, f, tmp;

matrix multiplymatrix(matrix a, matrix b)
{
    matrix c;
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++)
        {
            c.mt[i][j] = 0;
            for(int k = 1; k <= 2; k++)
                c.mt[i][j] = (c.mt[i][j] + (a.mt[i][k] * b.mt[k][j]%mod))%mod;
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

int32_t main()
{
    ///freopen("latgach4.inp", "r", stdin); // VNOI
    ///freopen("latgach4.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    f.mt[1][1] = 0, f.mt[1][2] = 1;
    f.mt[2][1] = 1, f.mt[2][2] = 1;
    fi.mt[1][1] = 1, fi.mt[1][2] = 0;
    fi.mt[2][1] = 2, fi.mt[2][2] = 0;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if(n == 2)
        {
            cout << 2 << endl;
            continue;
        }
        tmp = po(f,n-1);
        tmp = multiplymatrix(tmp, fi);
        cout << tmp.mt[1][1] << endl;
    }

}
