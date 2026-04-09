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
    int n, m; cin >> n >> m;
    vi v(n); 
    for(int i = 0;i < n;i++) cin >> v[i]; 
    for(int i = 0;i < n - 1;i++) {
        if(v[i] != 0 && v[i + 1] != 0 && abs(v[i] - v[i + 1]) > 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    vector<vi> dp(n, vi(m + 2, 0));
    if(v[0] == 0) for(int i = 1;i <= m;i++) dp[0][i] = 1;
    else dp[0][v[0]] = 1; 
    for(int i = 1;i < n;i++){
        for(int x = 1;x <= m;x++){
            if(v[i] != 0 && v[i] != x) continue; 
            dp[i][x] = dp[i - 1][x]; 
            dp[i][x] = (dp[i][x] + dp[i - 1][x - 1]) % MOD; 
            dp[i][x] = (dp[i][x] + dp[i - 1][x + 1]) % MOD; 
        }
    }
    int ans = 0; 
    for(int i = 1; i <= m;i++) ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << endl;
    return 0;
}