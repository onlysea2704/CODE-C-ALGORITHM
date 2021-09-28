#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans, mid, last, tmp, n, k, first;
string s;
int const maxn = 555555, mod = 1000003, base = 31;
int hashh[maxn], poww[maxn];
int mark[mod+10];
bool kt(int m)
{
    for(int i = 0; i <= mod+10; i++)
        mark[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        int tmp1 = (hashh[i+mid-1] - hashh[i-1]*poww[mid]+ mod*mod)%mod;
        mark[tmp1]++;
        if(mark[tmp1] >= k)
            return true;
    }
    return false;
}
int32_t main()
{

    //SOLUTION chặt nhị phân rồi mới chạy
    // giảm giá trị của mod để dùng được mảng đánh dấu (neu dùng map tle)
    ///freopen("dtksub.inp", "r", stdin); // vnoi  Chuỗi con xuất hiện K lần
    ///freopen("dtksub.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k >> s;
    s = '#' + s;
    poww[0] = 1;
    for(int i = 1; i <= n; i++)
        poww[i] = (poww[i-1]*base)%mod;
    for(int i = 1; i <= n; i++)
        hashh[i] = (hashh[i-1]*base+s[i]-'a'+1)%mod;

    first = 1, last = n;
    while(first <= last)
    {
        mid = (first+last)/2;
        if(kt(mid))
            ans = mid, first = mid+1;
        else
            last = mid-1;
    }
    cout << ans;
}
