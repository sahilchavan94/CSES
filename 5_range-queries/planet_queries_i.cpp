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

// vll t; 
// void build(int l, int r, int idx, vi & nums){
//     if(l == r) t[idx] = l;
//     else {
//         int m = (l + r) / 2; 
//         build(l, m, idx * 2 + 1, nums); 
//         build(m + 1, r, idx * 2 + 2, nums); 
//         int lx = t[idx * 2 + 1], rx = t[idx * 2 + 2]; 
//         if(nums[lx] >= nums[rx]) t[idx] = lx; 
//         else t[idx] = rx; 
//     }
// }
// int query(int l, int r, int a, int b, int idx, vi &nums) {
//     if(l > b || r < a) return -1; 
//     if(l >= a && r <= b) return t[idx]; 
//     int m = (l + r) / 2; 
//     int lx = query(l, m, a, b, idx * 2 + 1, nums); 
//     int rx = query(m + 1, r, a, b, idx * 2 + 2, nums); 
//     if(nums[lx] >= nums[rx]) return lx; 
//     else return rx;
// }
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int LOG = 30; 
    int n, q; cin >> n >> q; 
    vi nums(n + 2); 
    vector<vi> up(n + 1, vi(LOG)); 
    for(int i = 1;i <= n;i++) {
        cin >> nums[i];
        up[i][0] = nums[i];
    }
    for(int j = 1;j < LOG;j++){
        for(int i = 1;i <= n;i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    for(int i = 0;i < q;i++){
        int a, b; cin >> a >> b; 
        for(int j = LOG - 1; j >= 0; j--){
            if(b & (1LL << j)) a = up[a][j];                
        }
        cout << a << "\n";
    }
    return 0;
}