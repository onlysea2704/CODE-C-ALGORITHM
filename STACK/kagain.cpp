#include <bits/stdc++.h>

using namespace std;
int const mn = 1e5+11;
int t, n, u, res, resf, resl;
int b[mn], mi[mn], mi1[mn];
int main()
{
    ///freopen("kagain.inp", "r", stdin);
    ///freopen("kagain.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        res = 0;
        for(int i = 1; i <= n; i++)
            cin >> b[i];
        stack <int> st, stc;
        st.push(1), mi[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            u = st.top();
            while(b[u] >= b[i])
            {
                st.pop();
                if(st.size() == 0)
                {
                    u = 0;
                    break;
                }
                u = st.top();
            }
            mi[i] = u;
            st.push(i);
        }
        stc.push(n), mi1[n] = n+1;
        for(int i = n-1; i >= 1; i--)
        {
            u = stc.top();
            while(b[u] >= b[i])
            {
                stc.pop();
                if(stc.size() == 0)
                {
                    u = n+1;
                    break;
                }
                u = stc.top();
            }
            mi1[i] = u;
            stc.push(i);
        }
        for(int i = 1; i <= n; i++)
            if(res <= b[i]*(mi1[i]-mi[i]-1))
            {
                if(res == b[i]*(mi1[i]-mi[i]-1))
                {
                    if(mi[i]+1 < resf)
                        resf = mi[i]+1, resl = mi1[i] - 1;
                }
                else
                {
                    res = b[i]*(mi1[i]-mi[i]-1);
                    resf = mi[i]+1, resl = mi1[i] - 1;
                }
            }
        cout << res << " " << resf << " " << resl << endl;
    }
}
