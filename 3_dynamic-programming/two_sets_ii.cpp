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
    int n; cin >> n; 
    int s = (n * (n + 1)) / 2; 
    if(s % 2) {
        cout << 0 << endl; 
        return 0;
    }
    int t = s / 2;
    vi dp(t + 1, 0);
    dp[0] = 1; 
    for(int i = 1;i <= n;i++){
        for(int j = t;j >= i;j--){
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    } 
    long long inv2 = (MOD + 1) / 2;
    cout <<(dp[t] * inv2) % MOD<< endl;
    return 0;
}