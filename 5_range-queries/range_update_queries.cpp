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

vll nums, t, lazy; 
void build(int l, int r, int idx){
    if(l == r) t[idx] = nums[l];
    else {
        int m = (l + r) / 2; 
        build(l, m, idx * 2 + 1);
        build(m + 1, r, idx * 2 + 2);
        t[idx] = t[idx * 2 + 1] + t[idx * 2 + 2];
    }
}
void update(int a, int b, int l, int r, int idx, int val){
    if(lazy[idx] != 0){
        t[idx] += (r - l + 1) * lazy[idx];
        if(l != r){
            lazy[idx * 2 + 1] += lazy[idx]; 
            lazy[idx * 2 + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if(a > r || b < l) return; 
    if(a <= l && r <= b) {
        t[idx] += (r - l + 1) * val; 
        if(l != r) {
            lazy[idx * 2 + 1] += val; 
            lazy[idx * 2 + 2] += val;
        }
        return;
    } 
    int m = (l + r) / 2; 
    update(a, b, l, m, idx * 2 + 1, val);
    update(a, b, m + 1, r, idx * 2 + 2, val);
    t[idx] = t[idx * 2 + 1] + t[idx * 2 + 2];
}
ll rq(int a, int b, int l, int r, int idx){
    if(lazy[idx] != 0){
        t[idx] += (r - l + 1) * lazy[idx];
        if(l != r){
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx * 2 + 2] += lazy[idx]; 
        }
        lazy[idx] = 0;
    }
    if(a > r || b < l) return 0ll; 
    if(a <= l && r <= b) return t[idx]; 
    int m = (l + r) / 2;
    return rq(a, b, l, m, idx * 2 + 1) + 
    rq(a, b, m + 1, r, idx * 2 + 2);
}
int main()
{
    cin.tie(NULL);
    int n, q; cin >> n >> q; 
    nums.resize(n); t.resize(n * 4); lazy.resize(n * 4);
    for(int i = 0;i < n;i++) cin >> nums[i]; 
    build(0, n - 1, 0);
    for(int i = 0;i < q;i++) {
        int t; cin >> t;
        if(t == 1) {
            int a, b, c; cin >> a >> b >> c; 
            update(a - 1, b - 1, 0, n - 1, 0, c); 
        }else {
            int a; cin >> a; 
            cout << rq(a - 1, a - 1, 0, n - 1, 0) << endl; 
        }
    }
    return 0;
}