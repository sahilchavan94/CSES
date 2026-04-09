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
    int n; cin >> n; 
    vi x(n);
    for(int i = 0;i < n;i++) cin >> x[i]; 
    int s = accumulate(x.begin(), x.end(), 0); 
    vi dp(s + 1, 0); 
    dp[0] = 1; vi ans{}; int c = 0;
    for(int i = 0;i < n;i++){
        for(int sm = s;sm >= 0;sm--){
            if(dp[sm]) dp[x[i] + sm] = 1; 
        }
    }
    for(int i = 1;i <= s;i++){
        if(dp[i]) {
            ans.push_back(i);
            c++; 
        }
    }
    cout << c << endl;
    for(int a : ans) cout << a << " ";
    return 0;
}