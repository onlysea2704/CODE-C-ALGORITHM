#include <bits/stdc++.h>

using namespace std;
int j;
int const maxn = 1111111;
int neext[maxn];
string s, t;
int main()
{
    ///freopen("KMP.inp", "r", stdin);
    ///freopen("KMP.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t >> s;
    t = '#' + t;
    s = '#' + s;
    j = neext[1] = 0;
    for(int i = 2; i < s.size(); i++)
    {
        while(j > 0 && s[j+1] != s[i])
            j = neext[j];
        if(s[j+1] == s[i])
            j++;
        neext[i] = j;
    }
    j = 0;
    for(int i = 1; i < t.size(); i++)
    {
        while(j > 0 && s[j+1] != t[i])
            j = neext[j];
        if(s[j+1] == t[i])
            j++;
        if(j == s.size()-1)
        {
            cout << i-j+1 << " ";
            j = neext[j];
        }
    }
}
