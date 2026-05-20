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
    int n, m, k; cin >> n >> m >> k; 
    unordered_map<ll,vector<pll>> g; 
    for(int i = 0;i < m;i++){
        ll a, b, c; 
        cin >> a >> b >> c; 
        g[a].push_back({b,c});
    }
    vector<vll> d(n + 1, vll()); 
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    d[1].push_back(0);
    pq.push({0,1});
    while(!pq.empty()){
        auto [wt,node] = pq.top(); pq.pop(); 
        if(d[node].size() == k && wt > d[node][k - 1]) continue;
        for(auto [nxt,nwt] : g[node]){
            if(d[nxt].size() < k){
                d[nxt].push_back(wt + nwt); 
                sort(d[nxt].begin(), d[nxt].end());
                pq.push({nwt + wt, nxt});
            }else{
                int sz = d[nxt].size();
                if(sz == k && d[nxt][sz - 1] > nwt + wt){
                    d[nxt][sz - 1] = nwt + wt; 
                    sort(d[nxt].begin(), d[nxt].end()); 
                    pq.push({nwt + wt, nxt});
                }
            }
        }
    } 
    for(int i = 0;i < k;i++) cout << d[n][i] << " ";
    return 0;
}