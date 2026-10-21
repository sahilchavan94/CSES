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

#define imin INT_MIN
#define imax INT_MAX
#define lmin LLONG_MIN
#define lmax LLONG_MAX
#define MOD 1000000007

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; cin >> n; 
    map<ll,ll> mpp; 
    for(int i = 0;i < n;i++) {
        ll x; cin >> x; 
        mpp[x]++; 
    }
    ll ans = 1;
    for(auto &[num, cnt] : mpp){
        ans = (ans * (cnt + 1)) % MOD; 
    }
    cout << (ans - 1 + MOD) % MOD << "\n";
    return 0;
}