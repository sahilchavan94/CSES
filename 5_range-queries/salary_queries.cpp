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

vi nums,v,t; 
vector<tuple<char, int ,int>> qr; 
void update(int l, int r, int tidx, int idx, int val){
    if(l == r) t[tidx] += val;
    else{
        int m = (l + r) / 2; 
        if(idx <= m) update(l, m, tidx * 2 + 1, idx, val);
        else update(m + 1, r, tidx * 2 + 2, idx, val);
        t[tidx] = t[tidx * 2 + 1] + t[tidx * 2 + 2]; 
    }
}
int rq(int l, int r, int a, int b, int idx){
    if(l > r || l > b || r < a) return 0;
    if(l >= a && r <= b) return t[idx];
    int m = (l + r) / 2; 
    return rq(l, m, a, b, idx * 2 + 1) 
    + rq(m + 1, r, a, b, idx * 2 + 2);
}
int cmp(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}
int main()
{
    cin.tie(NULL);
    int n, q; cin >> n >> q; 
    nums.resize(n);
    for(int i = 0;i < n;i++) {
        cin >> nums[i];
        v.push_back(nums[i]);
    }
    for(int i = 0;i < q;i++){
        char a; cin >> a;
        int b, c; cin >> b >> c;
        if(a == '!') v.push_back(c); 
        qr.push_back({a, b, c});
    }
    sort(v.begin(), v.end()); 
    v.erase(unique(v.begin(), v.end()), v.end()); 
    int x = v.size(); t.resize(x * 4);
    for(int i = 0;i < n;i++) update(0, x - 1, 0, cmp(nums[i]), 1); 
    for(int i = 0;i < q;i++){
        auto [a, b, c] = qr[i]; 
        if(a == '!') {
            update(0, x - 1, 0, cmp(nums[b - 1]), -1);
            update(0, x - 1, 0, cmp(c), 1); 
            nums[b - 1] = c; 
        }else{
            int l = lower_bound(v.begin(), v.end(), b) - v.begin();
            int r = upper_bound(v.begin(), v.end(), c) - v.begin() - 1; 
            cout << rq(0, x - 1, l, r, 0) << endl;
        }
    } 
    return 0;
}