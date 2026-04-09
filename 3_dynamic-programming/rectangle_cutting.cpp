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
    int a, b; cin >> a >> b; 
    vector<vi> dp(a + 1, vi(b + 1, INT_MAX)); 
    for(int i = 1; i <= a;i++){
        for(int j = 1;j <= b;j++){
            if(i == j) dp[i][j] = 0;
            else {
                for(int k = 1;k < i;k++) dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                for(int k = 1;k < j;k++) dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}