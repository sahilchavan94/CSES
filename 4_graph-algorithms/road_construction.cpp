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

class DisjointSet{
    vll p, r, s; 
public:
    DisjointSet(ll n){
        p.resize(n + 1); 
        r.resize(n + 1, 0);
        s.resize(n + 1, 1); 
        for(ll i = 1;i <= n;i++) p[i] = i;
    }
    
    ll find(ll x){
        if(x == p[x]) return x;
        return find(p[x]);
    }

    ll sz(ll x) { 
        return s[find(x)]; 
    }

    bool unionn(ll x, ll y){
        ll px = find(x), py = find(y); 
        if(px == py) return false; 
        if(r[px] > r[py]) {
            p[py] = px;
            s[px] += s[py];
        }
        else if(r[px] < r[py]) {
            p[px] = py;
            s[py] += s[px];
        }
        else {
            p[px] = py; r[py]++;
            s[py] += s[px];
        }
        return true;
    }
};

int main()
{
    cin.tie(NULL);
    ll n, m, sz = 1; cin >> n >> m; 
    DisjointSet ds(n); 
    for(int i = 0;i < m;i++){
        ll a, b; cin >> a >> b; 
        if(ds.unionn(a, b)) {
            sz = max(sz, ds.sz(ds.find(a))); 
            n--;
        }
        cout << n << " " << sz << endl;
    }
    return 0;
}