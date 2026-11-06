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

ll pow(ll a, ll b, ll mod) {
    ll ans = 1; 
    while(b) {
        if(b % 2) {
            ans = (ans * a) % mod;
            b -= 1; 
        }else{
            a = (a * a) % mod; 
            b /= 2; 
        }
    }
    return (ans % mod);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; cin >> n; 
    while(n--){
        ll a, b, c;
        cin >> a >> b >> c; 
        ll ans = pow(a, pow(b, c, MOD - 1), MOD); 
        cout << ans << "\n";
    }
    return 0;
}