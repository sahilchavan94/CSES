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

vi hotel, t;
void build(int l, int r, int idx){
    if(l == r) t[idx] = hotel[l];
    else {
        int m = (l + r) / 2; 
        build(l, m, idx * 2 + 1); 
        build(m + 1, r, idx * 2 + 2); 
        t[idx] = max(t[idx * 2 + 1], t[idx * 2 + 2]);
    }
}
void update(int l, int r, int idx, int tidx, int val){
    if(l == r) t[tidx] = val;
    else {
        int m = (l + r) / 2; 
        if(idx <= m) update(l, m, idx, tidx * 2 + 1, val);
        else update(m + 1, r, idx, tidx * 2 + 2, val);
        t[tidx] = max(t[tidx * 2 + 1], t[tidx * 2 + 2]); 
    }
}
int query(int l, int r, int idx, int x){
    if(t[idx] < x) return -1; 
    if(l == r) return l; 
    int m = (l + r) / 2; 
    if(t[idx * 2 + 1] >= x) return query(l, m, idx * 2 + 1, x);
    return query(m + 1, r, idx * 2 + 2, x);
}
int main()
{
    cin.tie(NULL);
    int n, m; cin >> n >> m; 
    hotel.resize(n); t.resize(n * 4); 
    for(int i = 0;i < n;i++) cin >> hotel[i]; 
    build(0, n - 1, 0);
    for(int i = 0;i < m;i++){
        int r; cin >> r; 
        int idx = query(0, n - 1, 0, r); 
        if(idx == -1) cout << 0 << " ";
        else {
            cout << idx + 1 << " "; 
            hotel[idx] -= r;
            update(0, n - 1, idx, 0, hotel[idx]);
        }
    }
    return 0;
}