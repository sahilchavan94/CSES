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

vi lt, rt, nums, lval, rval; 

void build(int l, int r, int idx, vi & vals, vi & t){
    if(l == r) t[idx] = vals[l]; 
    else {
        int m = (l + r) / 2; 
        build(l, m, idx * 2 + 1, vals, t); 
        build(m + 1, r, idx * 2 + 2, vals, t); 
        t[idx] = min(t[idx * 2 + 1], t[idx * 2 + 2]); 
    }
}
void update(int l, int r, int idx, int tidx, vi & t, int val){
    if(l == r) t[tidx] = val; 
    else {
        int m = (l + r) / 2; 
        if(idx <= m) update(l, m, idx, tidx * 2 + 1, t, val);
        else update(m + 1, r, idx, tidx * 2 + 2, t, val);
        t[tidx] = min(t[tidx * 2 + 1], t[tidx * 2 + 2]);
    }
}
int rq(int l, int r, int a, int b, vi & t, int idx){
    if(l > b || r < a) return INT_MAX; 
    if(l >= a && r <= b) return t[idx];
    int m = (l + r) / 2; 
    return min(
      rq(l, m, a, b, t, idx * 2 + 1), 
      rq(m + 1, r, a, b, t, idx * 2 + 2)
    );
}
int main()
{
    cin.tie(NULL);
    int n, q; cin >> n >> q; 
    nums.resize(n); lval.resize(n); rval.resize(n); lt.resize(n * 4); rt.resize(n * 4); 
    for(int i = 0;i < n;i++) cin >> nums[i];
    for(int i = 0;i < n;i++){
        lval[i] = nums[i] - (i + 1); 
        rval[i] = nums[i] + (i + 1);
    }
    build(0, n - 1, 0, lval, lt);  
    build(0, n - 1, 0, rval, rt);
    for(int i = 0;i < q;i++){
        int a; cin >> a;
        if(a == 1){
            int b, c; cin >> b >> c; 
            update(0, n - 1, b - 1, 0, lt, c - b);
            update(0, n - 1, b - 1, 0, rt, c + b); 
            nums[b - 1] = c; 
        }else{
            int b; cin >> b; 
            int lqr = rq(0, n - 1, 0, b - 1, lt, 0); 
            int rqr = rq(0, n - 1, b, n - 1, rt, 0);
            cout << min(lqr + b, rqr - b) << endl;
        }
    }
    return 0;
}