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

class DisjointSet {
    vector<ll> rank, parent;
public: 
    DisjointSet(ll n){
        rank.resize(n + 1, 0LL);
        parent.resize(n + 1); 
        for(int i = 1;i <= n;i++) parent[i] = 1LL * i;
    }
    ll find(ll x) {
        if(x == parent[x]) return x; 
        return find(parent[x]);
    }
    void unionn(ll x, ll y){
        ll px = find(x), py = find(y);
        if(px == py) return; 
        if(rank[px] > rank[py]) parent[py] = px;
        else if(rank[py] > rank[px]) parent[px] = py;
        else {
            parent[py] = px; 
            rank[px]++;
        }
    }
};

int main()
{
    cin.tie(NULL);
    ll n, m; cin >> n >> m; 
    vector<tuple<ll,ll,ll>> r; 
    for(int i = 0;i < m;i++){
        ll a, b, c; cin >> a >> b >> c; 
        r.push_back({c, a, b}); 
    }
    sort(r.begin(), r.end(), [](const auto &a, const auto &b){
        return get<0>(a) < get<0>(b);
    });
    DisjointSet ds(n); 
    ll ans = 0, e = 0;
    for(int i = 0;i < m;i++){
        auto [wt, s, d] = r[i];
        ll ps = ds.find(s), pd = ds.find(d);
        if(ps != pd) {
            ds.unionn(ps, pd);
            ans += wt; 
            e++;
        }
    }
    if(e == n - 1) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}