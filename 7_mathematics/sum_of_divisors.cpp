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

using pqll = queue<pll>;

#define imin INT_MIN
#define imax INT_MAX
#define lmin LLONG_MIN
#define lmax LLONG_MAX
#define MOD 1000000007
#define INV 500000004

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // harmonic lemma & divisor ranges 
    ll n, l = 1; cin >> n; 
    ll ans = 0ll;
    while(l <= n) {
        ll q = n / l; 
        ll r = n / q; 
        ll cnt = (r - l + 1) % MOD; 
        ll sum = (l + r) % MOD; 
        ll prod = (((cnt * sum) % MOD) * INV) % MOD; 
        ll cont = (q * prod) % MOD;
        ans = (ans + cont) % MOD;
        l = r + 1;
    }
    cout << ans << "\n";
    return 0;
}