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
    int n, m; cin >> n >> m;
    unordered_map<ll,vector<pll>> f; 
    for(int i = 0;i < m;i++){
        ll a, b, c; cin >> a >> b >> c; 
        f[a].push_back({b, c});
    }
    vll d(n + 1, LLONG_MAX); d[1] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> pq; 
    pq.push({0, 1}); 
    while(!pq.empty()){
        auto [w, cf] = pq.top(); pq.pop();
        if(w > d[cf]) continue;
        for(pll &next : f[cf]){
            int nf = next.first, nw = next.second; 
            if(d[nf] > nw + w) {
                pq.push({nw + w, nf});
                d[nf] = nw + w;
            }
        }
    } 
    for(int i = 1;i <= n;i++) cout << d[i] << " ";
    return 0;
}