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
vll t; 
ll query(int l,int r,int a, int b, int idx){
    if(l > r || l > b || r < a) return 0; 
    else if(l >= a && r <= b) return t[idx]; 
    else {
        int m = (l + r) /  2; 
        return query(l, m, a, b, idx * 2 + 1)
            +  query(m + 1, r, a, b, idx * 2 + 2); 
    }
}
void update(int l, int r, int idx, int tidx, ll val) {
    if(l == r) 
        t[tidx] += val;
    else {
        int m = (l + r) / 2; 
        if(idx <= m) update(l, m, idx, tidx * 2 + 1, val);
        else update(m + 1, r, idx, tidx * 2 + 2, val); 
        t[tidx] = t[tidx * 2 + 1] + t[tidx * 2 + 2];
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; cin >> n; 
    vector<ll> a(n); 
    for(int i = 0;i < n;i++)
        cin >> a[i]; 
    vll vals = a; 
    sort(vals.begin(), vals.end()); 
    vals.erase(unique(vals.begin(), vals.end()), vals.end()); 
    int x = vals.size(); 
    t.resize(x * 4, 0); 
    ll ans = 0; 
    for(int i = 0;i < n;i++){
        int idx = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() - 1; 
        ll qval = 0; 
        if(idx >= 0) 
            qval = query(0, x - 1, 0, idx, 0) % MOD;  
        ans = (ans + (qval + 1)) % MOD;
        idx = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin(); 
        update(0, x - 1, idx, 0, (qval + 1) % MOD);
    }
    cout << ans << "\n";
    return 0;
}