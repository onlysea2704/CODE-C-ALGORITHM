#include <bits/stdc++.h>

using namespace std;
stack <int> st, st2;
int const maxn = 1e5+11;
int n, a[maxn], u, ans;
int main()
{
    ///freopen("Maximum Xor Secondary.inp", "r", stdin);   codeforce
    ///freopen("Maximum Xor Secondary.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    st.push(1);
    for(int i = 2; i <= n; i++)
    {
        u = st.top();
        while(a[u] <= a[i])
        {
            st.pop();
            if(st.size() == 0)
            {
                u = 0;
                break;
            }
            u = st.top();
        }
        st.push(i);
        if(u != 0)
            ans = max(ans, (a[i]^a[u]));
    }
    st2.push(n);
    for(int i = n-1; i >= 1; i--)
    {
        u = st.top();
        while(a[u] <= a[i])
        {
            st.pop();
            if(st.size() == 0)
            {
                u = 0;
                break;
            }
            u = st.top();
        }
        st.push(i);
        if(u != 0)
            ans = max(ans, (a[i]^a[u]));
    }
    cout << ans;
}
