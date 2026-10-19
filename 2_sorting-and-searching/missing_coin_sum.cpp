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
    ll n; cin >> n; 
    vll a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i]; 
    sort(a.begin(), a.end()); 
    if(a[0] > 1) {
        cout << 1 << "\n";
        return 0;
    }
    ll sum = 0; 
    for(int i = 0;i < n;i++){
        sum += a[i];
        if(sum + 1 < a[i + 1])
            break;
    }
    cout << sum + 1 << "\n";
    return 0;
}