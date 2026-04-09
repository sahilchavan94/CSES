#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> st(n);
    for(ll i = 0;i < n;i++) cin >> st[i];
    sort(st.begin(), st.end());
    ll med = -1;
    if(n % 2) med = st[n / 2]; 
    else med = (st[n / 2] + st[n / 2 - 1]) / 2;
    ll x = 0; 
    for(ll i = 0;i < n;i++) x += abs(med - st[i]);
    cout << x << endl;
    return 0;
}