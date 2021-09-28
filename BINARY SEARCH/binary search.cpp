#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e5;
int n, x, ans, mid, last, first;
int a[maxn];
int main()
{
    freopen("BINARY SEARCH.inp", "r", stdin);
    ///freopen("BINARY SEARCH.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> x;
    sort(a+1, a+n+1);
    last = n, first = 1;
    while(first <= last)
    {
        mid = (last+first)/2;
        if(a[mid] >= x)
            ans = mid, last = mid-1;
        else
            first = mid+1;
    }
    cout << ans;

}
