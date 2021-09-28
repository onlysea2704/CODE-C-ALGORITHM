#include <bits/stdc++.h>

using namespace std;
string a, b, c = "";

string sum(string a, string b)
{
    string c = "";
    int tmp = 0, last;
    while(a.size() > b.size())
        b = "0" + b;
    while(a.size() < b.size())
        a = "0" + a;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        last = int(a[i]) + int(b[i]) - 48*2 + tmp;
        tmp = last/10, last %= 10;
        c = char(last+48) + c;
    }
    if(tmp == 1)
        c = "1" + c;
    return c;
}

string subtract(string a, string b)
{
    string c = "", dau =  "";
    int tmp = 0, last;
    while(a.size() > b.size())
        b = "0" + b;
    while(a.size() < b.size())
        a = "0" + a;
    if(a < b)
        dau = "-", swap(a,b);
    for(int i = a.size()-1; i >= 0; i--)
    {
        last = int(a[i]) - int(b[i]) - tmp;
        if(last < 0)
            tmp = 1, last += 10;
        else
            tmp = 0;
        c = char(last+48) + c;
    }
    while(c.size() > 1 && c[0] == '0')
        c.erase(0,1);
    c = dau + c;
    return c;
}

string multiply(string a, string b)
{
    string c = "";
    int tmp = 0, last;
    int an = a.size(), bn = b.size();
    int cn = an+bn;
    for(int i = cn-1; i >= 0; i--)
    {
        for(int j = an-1; j >=0; j--)
            if(i-j >= 1 && i-j <= bn)
            {
                int a1 = int(a[j])-48, b1 = int(b[i-j-1])-48;
                tmp += a1*b1;
            }
        last = tmp % 10, tmp /= 10;
        c = char(last+48) + c;
    }
    while(c.size() > 1 && c[0] == '0')
        c.erase(0,1);
    return c;
}


int main()
{
    ///freopen("BIGNUM.inp", "r", stdin);
    ///freopen("BIGNUM.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> a >> b;
    c = sum(a,b);
    cout << c << endl;
    c = subtract(a,b);
    cout << c << endl;
    c = multiply(a,b);
    cout << c;
}
