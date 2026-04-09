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
#define MOD 1000000007


int main()
{
    cin.tie(NULL);
    ll n; cin >> n; 
    vector<array<ll,3>> p(n);
    for(int i = 0;i < n;i++){
        ll a, b, c; 
        cin >> a >> b >> c; 
        p[i] = {a, b, c};
    } 
    sort(p.begin(), p.end(), [](const auto &a, const auto &b){
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }); 
    vll dp(n, 0);
    dp[0] = p[0][2]; 
    for(ll i = 1;i < n;i++){
        ll l = 0, r = i - 1; 
        ll idx = -1;
        while(l <= r){
            ll m = (l + r) / 2; 
            if(p[m][1] < p[i][0]){
                idx = m; 
                l = m + 1;
            }
            else r = m - 1;
        }
        ll t = p[i][2]; 
        if(idx != -1) t += dp[idx]; 
        dp[i] = max(t, dp[i - 1]);
    }
    cout << dp[n - 1] << endl;
    return 0;
}