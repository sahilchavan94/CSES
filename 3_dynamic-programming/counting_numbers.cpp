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

ll dp[19][2][2][11]; 
ll solve(string & num, int i, int t, int s, int p){
    if(i == num.size()) return 1; 
    if(dp[i][t][s][p] != -1) return dp[i][t][s][p];
    int lim = t ? (num[i] - '0') : 9;
    ll ans = 0;
    for(int d = 0;d <= lim;d++){
        int nt = t & (d == (num[i] - '0'));
        if(!s && d == 0) ans += solve(num, i + 1, nt, s, p); 
        else {
            if(p == d) continue; 
            ans += solve(num, i + 1, nt, 1, d);
        }
    }
    return dp[i][t][s][p] = ans;
}

int main()
{
    cin.tie(NULL);
    ll a, b; cin >> a >> b; 
    memset(dp, -1, sizeof(dp)); 
    string bb = to_string(b);
    ll rans = solve(bb, 0, 1, 0, 10);
    if(a == 0) {
        cout << rans << endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    string aa = to_string(a - 1); 
    ll lans = solve(aa, 0, 1, 0, 10);
    cout << rans - lans << endl;
    return 0;
}