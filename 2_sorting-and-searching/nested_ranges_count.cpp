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
    int n;cin >> n; 
    vector<vll> a(n); 
    vll t, svals;
    for(int i = 0;i < n;i++){
        ll x, y; cin >> x >> y; 
        a[i] = (vll){x, y, i}; 
        svals.push_back(x);  
    }

    sort(svals.begin(), svals.end());
    svals.erase(unique(svals.begin(), svals.end()), svals.end());
    int x = (int) svals.size(); 
    t.resize((x + 1) * 4); 

    sort(a.begin(), a.end(), [&](const auto &i1, const auto &i2){
        if(i1[1] == i2[1]) return i1[0] > i2[0]; 
        else return i1[1] < i2[1]; 
    });

    auto getl = [&](ll val) -> int {
        return lower_bound(svals.begin(), svals.end(), val) 
        - svals.begin(); 
    };

    function<void(int,int,int,int,int)> update = [&](int left, int right, int idx, int tidx, int val) {
        if(left == right) t[tidx] += 1; 
        else {
            int m = (left + right) / 2; 
            if(idx <= m) update(left, m, idx, tidx * 2 + 1, val); 
            else update(m + 1, right, idx, tidx * 2 + 2, val); 
            t[tidx] = t[tidx * 2 + 1] + t[tidx * 2 + 2]; 
        }
    };

    function<ll(int,int,int,int,int)> query = [&](int left, int right, int a, int b, int idx) {
        if(left > right || left > b || right < a) return 0ll; 
        else if(left >= a && right <= b) return t[idx];
        int m = (left + right) / 2;
        return query(left, m, a, b, idx * 2 + 1) + 
                query(m + 1, right, a, b, idx * 2 + 2); 
    };

    vll b(n), c(n); 
    for(int i = 0;i < n;i++){
        int idx = getl(a[i][0]); 
        b[a[i][2]] = query(0, x - 1, idx, x - 1, 0); 
        update(0, x - 1, idx, 0, 1); 
    }
    fill(t.begin(), t.end(), 0ll); 
    for(int i = n - 1; i >= 0;i--){
        int idx = getl(a[i][0]); 
        c[a[i][2]] = query(0, x - 1, 0, idx, 0); 
        update(0, x - 1, idx, 0, 1); 
    }
    for(int i = 0;i < n;i++) {
        if(i == n - 1) cout << b[i] << "\n";
        else cout << b[i] << " ";
    }
    for(int i = 0;i < n;i++){
        if(i == n - 1) cout << c[i] << "\n";
        else cout << c[i] << " ";
    }
    return 0;
}