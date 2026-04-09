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
    ll n; cin >> n; 
    if(n <= 2) {
        cout << n << endl;
        return 0;
    }
    vll dp(n + 1, 0);
    dp[0] = dp[1] = 1; dp[2] = 2;
    for(int i = 3;i <= n;i++){
        for(int j = 1;j <= 6;j++){
            if(j > i) break; 
            ll rem = i - j; 
            dp[i] = (dp[i] + dp[rem]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

// 1 1 1 1
// 1 1 2 
// 1 2 1 
// 2 1 1 
// 2 2 
// 4  

// 1 1 1 1 1 
// 1 1 1 2 
// 1 1 2 1 
// 1 2 1 1
// 2 1 1 1 
// 1 1 3 
// 1 3 1 
// 3 1 1 
// 2 2 1 
// 2 1 2 
// 1 2 2 
// 2 3 
// 3 2 
// 1 4 
// 4 1
// 5 