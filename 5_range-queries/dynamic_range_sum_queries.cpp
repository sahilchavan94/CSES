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

vll t, nums;
void build(int l, int r, int idx){
    if(l == r) t[idx] = nums[l];
    else {
        int m = (l + r) / 2; 
        build(l, m, idx * 2 + 1); 
        build(m + 1, r, idx * 2 + 2);
        t[idx] = t[idx * 2 + 1] + t[idx * 2 + 2];
    }
}
void update(int l, int r, int idx, int tidx, int val){
    if(l == r) t[tidx] = val; 
    else {
        int m = (l + r) / 2; 
        if(idx <= m) update(l, m, idx, tidx * 2 + 1, val);
        else update(m + 1, r, idx, tidx * 2 + 2, val); 
        t[tidx] = t[tidx * 2 + 1] + t[tidx * 2 + 2];
    }
}
ll sum(int l, int r, int a, int b, int idx){
    if(l > b || r < a) return 0ll;
    if(l >= a && r <= b) return t[idx];
    int m = (l + r) / 2; 
    return sum(l, m, a, b, idx * 2 + 1) + 
    sum(m + 1, r, a, b, idx * 2 + 2);
}

int main()
{
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    nums.resize(n); t.resize(n * 4);
    for(int i = 0;i < n;i++) cin >> nums[i]; 
    build(0, n - 1, 0);
    for(int i = 0;i < q;i++) {
        int a, b, c; cin >> a >> b >> c; 
        if(a == 1) update(0, n - 1, b - 1, 0, c); 
        else cout << sum(0, n - 1, b - 1, c - 1, 0) << endl;
    }
    return 0;
}