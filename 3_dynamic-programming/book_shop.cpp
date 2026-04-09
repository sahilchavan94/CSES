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

int rec(vi &pr, vi & pg, int i, int x, vector<vi> & dp){
    int n = pr.size(); 
    if(i == n || x == 0) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    int pick = -1;
    if(pr[i] <= x) pick = pg[i] + rec(pr, pg, i + 1, x - pr[i], dp); 
    int skip = rec(pr, pg, i + 1, x, dp); 
    return dp[i][x] = max(pick, skip);
}

int tabulation(vi & pr, vi &pg, int x){
    int n = pr.size(); 
    vector<vi> dp(n + 1, vi(x + 1, 0)); 
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= x;j++){
            int pick = -1; 
            if(pr[i - 1] <= j) pick = pg[i - 1] + dp[i - 1][j - pr[i - 1]];
            int skip = dp[i - 1][j];
            dp[i][j] = max(pick, skip);
        }
    }
    return dp[n][x];
}

int tabulation2(vi & pr, vi &pg, int x){
    int n = pr.size(); 
    vi dp(x + 1, 0); 
    for(int i = 0;i < n;i++){
        for(int j = x;j >= pr[i];j--){
            dp[j] = max(dp[j], pg[i] + dp[j - pr[i]]); 
        }
    }
    return dp[x];
}

int main()
{
    cin.tie(NULL);
    int n, x; cin >> n >> x; 
    vi pr(n), pg(n); 
    for(int i = 0;i < n;i++) cin >> pr[i];
    for(int i = 0;i < n;i++) cin >> pg[i];
    vector<vi> dp(n, vi(x + 1,-1)); 
    // cout << rec(pr, pg, 0, x, dp) << endl; 
    // cout << tabulation(pr, pg, x) << endl;
    cout << tabulation2(pr, pg, x) << endl;
    return 0;
}