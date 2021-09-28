#include <iostream>
#define int long long
using namespace std;
int const maxn = 1e5+11;
int n,m,a[maxn],x,u,v,tf;

void update(int id, int val)
{
    while(id <= n)
    {
        a[id] += val;
        id = id + (id & (-id));
    }
}

int get(int id)
{
    int ans = 0;
    while(id > 0)
    {
        ans += a[id];
        id = id - (id & (-id));
    }
    return ans;
}

int32_t main()
{
    ///freopen("Binary Indexed Tree.inp", "r", stdin);
    ///freopen("Binary Indexed Tree.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        update(i,x);
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> tf;
        if(tf == 1)
        {
            cin >> u >> v;
            update(u,v);
        }
        else
        {
            cin >> u >> v;
            if(u == 1)
               cout << get(v) << endl;
            else
                cout << get(v) - get(u-1) << endl;
        }
    }
}
