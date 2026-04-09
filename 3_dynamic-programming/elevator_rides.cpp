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

// doesn't works for larger constraints 
// but still a valid solution for smaller val of x
// int cap = 0;
// int rec(int mask, vi & v, int x, vector<vi>& dp, int n){
//     if(mask == 0) return 1;
//     if(dp[x][mask] != -1) return dp[x][mask];
//     int ans = INT_MAX;
//     for(int i = 0;i < n;i++){
//         if((mask & (1 << i))){
//             if(x >= v[i]) {
//                 int add = rec(mask ^ (1 << i), v, x - v[i], dp, n);
//                 ans = min(ans, add);
//             }
//             else {
//                 if(v[i] > cap) continue;
//                 int nwr = 1 + rec(mask ^ (1 << i), v, cap - v[i], dp, n);
//                 ans = min(ans, nwr);
//             }
//         }
//     }
//     return ans;
// }

int main()
{
    cin.tie(NULL);
    int n, x; cin >> n >> x; 
    vi v(n);
    for(int i = 0;i < n;i++) cin >> v[i]; 
    return 0;
}