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
    ll mod = 1e9 + 7;
    ll n, x; cin >> n >> x; 
    vll c(n); 
    for(ll i = 0;i < n;i++) cin >> c[i]; 
    sort(c.begin(), c.end());
    vll dp(x + 1, 0); dp[0] = 1;
    for(ll i = 1;i <= x;i++){
        for(ll cn : c){
            if(i < cn) break;
            ll rem = i - cn;
            dp[i] = (dp[i] + dp[rem]) % mod;
        }
    }
    cout << dp[x] << endl;
    return 0;
}