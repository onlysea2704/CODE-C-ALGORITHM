#include <bits/stdc++.h>
#define maxn 111111
#define int long long
using namespace std;
int n, a[maxn], u, dp[maxn], t, dp2[maxn], ans;
int32_t main()
{
    freopen("SSAM219G.inp", "r", stdin); //spoj
    ///freopen("SSAM219G.out", "w", tdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        stack <int> st, st2;
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        dp[1] = 0, st.push(1);
        for(int i = 2; i <= n; i++)
        {
            u = st.top();
            while(a[u] >= a[i])
            {
                st.pop();
                if(st.size() == 0)
                {
                    u = 0;
                    break;
                }
                u = st.top();
            }
            dp[i] = u;
            st.push(i);
        }
        dp2[n] = n+1, st2.push(n);
        for(int i = n-1; i >= 1; i--)
        {
            u = st2.top();
            while(a[u] >= a[i])
            {
                st2.pop();
                if(st2.size() == 0)
                {
                    u = n+1;
                    break;
                }
                u = st2.top();
            }
            dp2[i] = u;
            st2.push(i);
        }
        for(int i = 1; i <= n; i++)
            ans = max(ans, a[i]*(dp2[i]-dp[i]-1));
        cout << ans << endl;
    }
}
