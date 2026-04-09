#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using si = stack<int>;
using sll = stack<ll>;
using spi = stack<pii>; 
using spll = stack<pll>; 
using qi = queue<int>;
using qll = queue<ll>;
using qpi = queue<pii>;
using pqll = queue<pll>;

int main()
{
    cin.tie(NULL);
    ll n, k; cin >> n >> k; 
    vll v(n);
    for(ll i = 0;i < n;i++) cin >> v[i];
    ll l = *max_element(v.begin(), v.end()), r = accumulate(v.begin(), v.end(), 0LL);
    while(l <= r){
        ll m = (l + r) / 2; 
        ll cr = 0, kk = 1; 
        for(ll i = 0;i < n;i++){
            if(cr + v[i] > m){
                cr = v[i];
                kk += 1; 
            }else cr += v[i];
        }
        if(kk <= k) r = m - 1;
        else l = m + 1;
    }
    cout << l << endl;
    return 0;
}