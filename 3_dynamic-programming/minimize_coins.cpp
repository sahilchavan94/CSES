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
    ll n, x; cin >> n >> x; 
    vll c(n);
    for(ll i = 0;i < n;i++) cin >> c[i]; 
    sort(c.begin(), c.end()); 
    if(x < c[0]) {
        cout << -1 << endl;
        return 0;
    }     
    vll dp(x + 1, INT_MAX);
    dp[0] = 0;
    for(ll i = 1;i <= x;i++){
        for(ll cn : c){
            if(cn > i) break; 
            ll rem = i - cn; 
            if(dp[rem] == INT_MAX) continue; 
            else dp[i] = min(dp[i], 1 + dp[rem]);
        }
    }
    if(dp[x] == INT_MAX) cout << -1 << endl;
    else cout << dp[x] << endl;
    return 0;
}