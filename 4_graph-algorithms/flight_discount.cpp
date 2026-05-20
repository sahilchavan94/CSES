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
    unordered_map<ll, vector<vll>> g;
    vi v(n + 1, 0);
    for(int i = 0;i < m;i++){
        int a, b; ll c; cin >> a >> b >> c; 
        g[a].push_back({b,c});
    }
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
    vector<vll> d(n + 1, vll(2, LLONG_MAX)); 
    d[1][0] = 0, d[1][1] = 0;
    pq.push({0, 1, 0});
    while(!pq.empty()){
        auto [wt, fl, st] = pq.top() ; pq.pop();   
        if(wt > d[fl][st]) continue; 
        for(auto nxt : g[fl]){
            ll nf = nxt[0], nw = nxt[1]; 
            if(st == 0){
                if(nw/2 + wt < d[nf][1]){
                    d[nf][1] = nw/2 + wt; 
                    pq.push({nw/2 + wt, nf, 1});
                }
            }
            if(nw + wt < d[nf][st]){
                d[nf][st] = nw + wt; 
                pq.push({nw + wt, nf, st});
            }
        }     
    }
    cout << min(d[n][0], d[n][1]) << endl;
    return 0;
}