#include <bits/stdc++.h>

using namespace std;
int const mn = 1e5+11;
int t, n, k, dp[mn], b[mn];
int main()
{
    ///freopen("mink.inp", "r", stdin);     vnoj
    ///freopen("mink.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            cin >> b[i];
        deque <int> dq;
        dq.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            while(dq.size() && dq.front() <=  i-k)
                dq.pop_front();
            while(dq.size() && b[dq.back()] >= b[i])
                dq.pop_back();
            dq.push_back(i);
            dp[i] = b[dq.front()];
        }
        for(int i = k; i <= n; i++)
            cout << dp[i] << " ";
        cout << endl;
    }

}
