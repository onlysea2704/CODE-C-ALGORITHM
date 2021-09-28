#include <bits/stdc++.h>
#define int long long
int const base = 31, mod = 1e9+7, maxn = 55555;
using namespace std;
int as, ans = 1, tmp, first, last, mid;
string a;
int poww[maxn], hashf[maxn], hashl[maxn];

bool kt(int i, int m, int k)
{   // k dùng chia trường hợp dãy cần tìm chẵn hay lẻ
    int tmp1 = (hashf[i] - hashf[i-m]*poww[m] + mod*mod)%mod;
    int tmp2 = (hashl[i+k] - hashl[i+m+k]*poww[m] + mod*mod)%mod;
    if(tmp1 == tmp2)
        return true;
    return false;
}

int32_t main()
{
    ///freopen("paliny.inp", "r", stdin);
    ///freopen("paliny.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> as;
    cin >> a;
    a = '#' + a;
    poww[0] = 1;
    for(int i = 1; i <= as; i++)
        poww[i] = (poww[i-1]*base)%mod;

    for(int i = 1; i <= as; i++)
        hashf[i] = (hashf[i-1]*base + a[i]-'a'+1)%mod;

    for(int i = as; i >=1 ; i--)
        hashl[i] = (hashl[i+1]*base + a[i]-'a'+1)%mod;

    for(int i = 1; i <= as; i++)
    {
        first = 1, last = min(i-1+1, as-i+1), tmp = 0;
        while(first <= last)
        {
            mid = (first+last)/2;
            if(kt(i,mid,0))
                tmp = mid, first = mid+1;
            else
                last = mid-1;
        }
        ans = max(ans, tmp*2-1);
        first = 1, last = min(i-1+1, as-i), tmp = 0;
        while(first <= last)
        {
            mid = (first+last)/2;
            if(kt(i,mid,1))
                tmp = mid, first = mid+1;
            else
                last = mid-1;
        }
        ans = max(ans, tmp*2);
    }
    cout << ans;
}
