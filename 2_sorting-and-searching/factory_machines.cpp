#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int main()
{
    cin.tie(NULL);
    ll n, t; cin >> n >> t;
    vll v(n);
    for(int i = 0;i < n;i++) cin >> v[i];
    ll l = 0, r = (ll)*min_element(v.begin(), v.end()) * t; 
    ll ans = r;
    while(l <= r){
        ll m = (l + r) / 2; 
        ll p = 0;
        for(int k : v){
            p += m / k;
            if(p >= t) break;
        }
        if(p >= t){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << ans << endl;
    return 0;
}