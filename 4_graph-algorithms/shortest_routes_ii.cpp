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

int main()
{
    cin.tie(NULL);
    int n, m, q; cin >> n >> m >> q; 
    unordered_map<int,vector<pii>> g; 
    for(int i = 0;i < m;i++){
        int a, b, c; cin >> a >> b >> c; 
        g[a].push_back({b,c}); 
    }
    
    return 0;
}