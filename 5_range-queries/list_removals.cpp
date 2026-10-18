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

vll nums,pr; 
void build(int l, int r, int idx){
    if(l == r) pr[idx] = 1;
    else {
        int m = (l + r) / 2; 
        build(l, m, idx * 2 + 1);
        build(m + 1, r, idx * 2 + 2);
        pr[idx] = pr[idx * 2 + 1] + pr[idx * 2 + 2];
    }
}
void update(int l, int r, int tidx, int idx, int val){
    if(l == r) pr[tidx] = val; 
    else {
        int m = (l + r) / 2; 
        if(idx <= m) update(l, m, tidx * 2 + 1, idx, val);
        else update(m + 1, r, tidx * 2 + 2, idx, val);
        pr[tidx] = pr[tidx * 2 + 1] + pr[tidx * 2 + 2];
    }
}
int kth(int l, int r, int idx, int k){
    if(l == r) return l; 
    int lc = pr[idx * 2 + 1], m = (l + r) / 2; 
    if(lc >= k) return kth(l, m, idx * 2 + 1, k); 
    return kth(m + 1, r, idx * 2 + 2, k - lc);
}
int main()
{
    cin.tie(NULL);
    int n; cin >> n; 
    nums.resize(n); pr.resize(n * 4); 
    for(int i = 0;i < n;i++) cin >> nums[i]; 
    build(0, n - 1, 0);
    for(int i = 0;i < n;i++){
        int p; cin >> p; 
        int idx = kth(0, n - 1, 0, p);
        cout << nums[idx] << " ";
        update(0, n - 1, 0, idx, 0);
    }
    return 0;
}