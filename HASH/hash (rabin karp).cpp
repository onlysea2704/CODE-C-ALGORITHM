#include <bits/stdc++.h>
#define maxn 1000111
#define int long long
using namespace std;
int base = 31, mod = 1e9+7;
int hashb, tmp;
int poww[maxn], hasha[maxn];
string a, b;
int32_t main()
{
    // idea :: mã hóa 1 xâu thành 1 số rồi thay vì so sánh xâu mình sẽ so sánh số
    freopen("HASH (Rabin karp).inp", "r", stdin);     // xâu con vnoi SUBSTR
    ///freopen("HASH (Rabin-karp).out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> a >> b;
    a = '#' + a, b = '#' + b;
    poww[0] = 1;
    for(int i = 1; i < a.size(); i++)
        poww[i] = (poww[i-1] * base)%mod;
    for(int i = 1; i < a.size(); i++)
        hasha[i] = (hasha[i-1]*base + a[i] - 'a' + 1) % mod;
    for(int i = 1; i < b.size(); i++)
        hashb = (hashb*base + b[i] - 'a' + 1)% mod;
    for(int i = 1; i < a.size(); i++)
    {
        tmp = (hasha[i+b.size()-2]-hasha[i-1]*poww[b.size()-1]+mod*mod)%mod;
        if(tmp == hashb)
           cout << i << " ";
    }

}
