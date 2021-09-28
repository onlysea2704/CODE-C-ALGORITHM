#include <bits/stdc++.h>
#define task "BIGNUM"
#define FOR(i, l, r) for(int i = l;(int) i <= r; ++i)
#define FOD(i, l, r) for(int i = l;(int) i >= r; --i)
#define ll long long
#define BigInt vector<ll>
using namespace std;
const int base = 1e9;
BigInt Init(string s)
{
    BigInt a;
    if(s.size() == 0)
    {
        a.push_back(0);
        return a;
    }
    while(s.size() % 9 != 0) s = '0' + s;
    for(int i = 0; i < (int) s.size(); i += 9)
    {
        ll val = 0;
        FOR(j,0,8) val = val * 10 + (s[i + j] - '0');
        a.insert(a.begin(), val);
    }
    return a;
}
void Print(const BigInt a)
{
    int len = a.size();
    printf("%ld", a[len - 1]);
    FOD(i, len - 2, 0) printf("%09ld", a[i]);
    printf("\n");
}
BigInt operator +(const BigInt a, const BigInt b)
{
    BigInt c;
    ll carry = 0;
    for(int i = 0; i < (int) a.size() || i < (int)b.size(); ++i)
    {
        if(i < (int) a.size()) carry += a[i];
        if(i < (int) b.size()) carry += b[i];
        c.push_back(carry % base);
        carry /= base;
    }
    if(carry) c.push_back(carry);
    return c;
}
BigInt operator -(const BigInt a, const BigInt b)
{
    BigInt c;
    ll carry = 0;
    FOR(i,0,(int) a.size() - 1)
    {
        ll s = a[i] - carry;
        if(i < b.size()) s -= b[i];
        if(s < 0) s += base, carry = 1;
        else carry = 0;
        c.push_back(s);
    }
    while(c.back() == 0 && c.size() > 1) c.pop_back();
    return c;
}
BigInt operator *(const BigInt a, const int &mul)
{
    BigInt c;
    ll carry = 0;
    FOR(i, 0, a.size() - 1)
    {
        carry += a[i] * mul;
        c.push_back(carry % base);
        carry /= base;
    }
    if(carry) c.push_back(carry);
    return c;
}
BigInt operator *(const BigInt a, const BigInt b)
{
    BigInt c(a.size() + b.size() + 5, 0);

    FOR(i, 0, a.size() - 1)
    {
        ll carry = 0;
        FOR(j, 0, b.size() - 1)
        {
            int k = i + j;
            c[k] += a[i] * b[j] + carry;
            carry = c[k] / base;
            c[k] %= base;
        }
        if(carry)
            c[i + b.size()] += carry;
    }
     while(c.back() == 0 && c.size() > 1) c.pop_back();
    return c;
}
bool operator < (BigInt a, BigInt b)
{
    while(a.size() && a.back()  == 0) a.pop_back();
    while(b.size() && b.back()  == 0) b.pop_back();
    if(a.size() != b.size()) return a.size() < b.size();
    FOD(i, a.size() - 1, 0) if(a[i] != b[i]) return a[i] < b[i];
    return 0;
}
int main()
{
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string sa, sb;
    cin >> sa >> sb;
    BigInt a = Init(sa);
    BigInt b = Init(sb);
    Print(a + b);
    if(a < b)
    {
        printf("-");
        Print(b - a);
    }
    else Print(a - b);
    Print (a * b);
    return 0;
}
