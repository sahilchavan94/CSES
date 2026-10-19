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
    int x, n; cin >> x >> n; 
    set<int> pts = {0, x}; 
    set<vector<int>> intr = {{x, 0, x}}; 
    for(int i = 1;i <= n;i++){
        int p; cin >> p; 
        auto pl = pts.lower_bound(p); pl--;
        auto nr = pts.upper_bound(p); 
        intr.erase({*nr - *pl, *pl, *nr}); 
        intr.insert({p - *pl, *pl, p}); 
        intr.insert({*nr - p, p, *nr});
        pts.insert(p);
        cout << (*intr.rbegin())[0]<< " ";
    }
    return 0;
}