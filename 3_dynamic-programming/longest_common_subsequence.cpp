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

int rec(vi &a, vi &b, int i, int j, vector<vi> & dp) {
    int n = a.size(), m = b.size();
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j]) return dp[i][j] = 1 + rec(a, b, i + 1, j + 1, dp); 
    int sa = rec(a, b, i + 1, j, dp);
    int sb = rec(a, b, i, j + 1,dp);
    return dp[i][j] = max({sa, sb});
}

int main()
{
    cin.tie(NULL);
    int n, m; cin >> n >> m; 
    vi a(n), b(m); 
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i]; 
    vector<vi> dp(n + 1, vi(m + 1, -1)); 
    // for(int i = 1;i <= n;i++){
    //     for(int j = 1;j <= m;j++){
    //         if(a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
    //         else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
    //     }
    // }
    // vi ans; 
    // int i = n, j = m;
    // while(i > 0 && j > 0){
    //     if(a[i - 1] == b[j - 1]) {
    //         ans.push_back(a[i - 1]); 
    //         i--; j--;
    //     }else if(dp[i - 1][j] >= dp[i][j - 1]) i--;
    //     else j--;
    // }
    // cout << ans.size() << endl;
    // for(int i = ans.size() - 1;i >= 0;i--) {
    //     cout << ans[i] << " ";
    // }
    cout << rec(a, b, 0, 0, dp) << endl;
    vi ans; 
    int i = 0, j = 0; 
    while(i < n && j < m){
        if(a[i] == b[j]) {
            ans.push_back(a[i]); 
            i++; j++;
        }else if(dp[i + 1][j] >= dp[i][j + 1]) i++;
        else j++;
    }
    for(int a : ans) cout << a << " ";
    return 0;
}