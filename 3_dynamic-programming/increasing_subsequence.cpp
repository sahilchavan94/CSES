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
    vi v(n);
    for(int i = 0;i < n;i++) cin >> v[i];
    // vi dp(n, 1); 
    // for(int i = 1;i < n;i++){
    //     for(int j = 0;j < i;j++){
    //         if(v[j] < v[i]) {
    //             dp[i] = max(dp[i], 1 + dp[j]);
    //         }
    //     }
    // }
    // int ans = 0; 
    // for(int s : dp) ans = max(ans, s);
    // cout << ans << endl;
    vi lis;
    for(int i = 0;i < n;i++){
        if(i == 0 || v[i] > lis.back()) {
            lis.push_back(v[i]); 
        }else{
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
        }
    }
    cout << lis.size() << endl;
    return 0;
}