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
    int t; cin >> t; 
    while(t--){
        ll x, y; cin >> x >> y; 
        if(x >= y) {
            if(x % 2) 
                cout << (x - 1) * (x - 1) + y << "\n"; 
            else 
                cout << (x * x) - y + 1 << "\n"; 
        }
        else {
            if(y % 2)
                cout << (y * y) - x + 1 << "\n"; 
            else 
                cout << (y - 1) * (y - 1) + x<< "\n";
        }
    }
    return 0;
}