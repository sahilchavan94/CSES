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

vll nums, t; 
void build(int l, int r, int idx){
    if(l == r) t[idx] = nums[l];
    else {
        int m = (l + r) / 2; 
        build(l, m, idx * 2 + 1); 
        build(m + 1, r, idx * 2 + 2);
        t[idx] = t[idx * 2 + 1] + t[idx * 2 + 2]; 
    }
}
ll rq(int l, int r, int a, int b, int idx){
    if(l > b || r < a) return 0LL;
    if(l >= a && r <= b) return t[idx]; 
    int m = (l + r) / 2; 
    return rq(l, m, a, b, idx * 2 + 1) + 
    rq(m + 1, r, a, b, idx * 2 + 2); 
}
int main()
{
    cin.tie(NULL);
    int n, q; cin >> n >> q; 
    nums.resize(n); t.resize(n * 4);
    for(int i = 0;i < n;i++) cin >> nums[i];
    build(0, n - 1, 0); 
    for(int i = 0;i < q;i++){
        int a, b; cin >> a >> b; 
        cout << rq(0, n - 1, a - 1, b - 1, 0) << endl;
    } 
    return 0;
}