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
    int n; cin >> n; 
    vi dp(n + 1, INT_MAX); 
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        int c = i; 
        while(c > 0){
            int d = c % 10; 
            int rem = i - d; 
            if(dp[rem] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[rem]);
            }
            c = c / 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}