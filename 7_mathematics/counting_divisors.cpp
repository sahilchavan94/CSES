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
    while(n--){
        ll x; cin >> x; 
        ll ans = 0; 
        for(ll i = 1; i * i <= x;i++){
            if(!(x % i)) {
                if(i * i == x) ans += 1; 
                else ans += 2 ;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}