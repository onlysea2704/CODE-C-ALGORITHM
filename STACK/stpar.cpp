#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e6+11;
int n, a[maxn], tmp, ok;
int main()
{
    ///freopen("STPAR.inp", "r", stdin);   /// spoj
    ///freopen("STPAR.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while(cin >> n)
    {
        if(n == 0)
            return 0;
        stack <int> st;
        ok = 0, tmp = 1;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int i = 1; i <= n; i++)
        {
            if(st.size() != 0 && st.top() == i)
            {
                st.pop();
                continue;
            }
            while(a[tmp] != i && tmp < n)
                st.push(a[tmp]), tmp++;
            if(a[tmp] == i)
            {
                tmp++;
                continue;
            }
            ok = 1;
        }
        if(ok == 0)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
}
