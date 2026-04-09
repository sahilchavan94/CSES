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
    int n, m, ans = 1; cin >> n >> m; 
    unordered_map<int,vector<int>> g; 
    vi v(n + 1,0), p(n + 1, -1);
    for(int i = 0;i < m;i++){
        int a, b; cin >> a >> b; 
        g[a].push_back(b); 
        g[b].push_back(a);
    }
    qi q; 
    q.push(1); v[1] = 1; 
    bool found = false;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            int node = q.front(); q.pop();
            if(node == n) {
                found = true; 
                break;
            }
            for(int next : g[node]){
                if(v[next]) continue; 
                v[next] = 1; p[next] = node;
                q.push(next); 
            }
        }
        if(found) break;
        ans++;
    }
    if(!found) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << ans << endl;
    int c = n;
    vi r;
    while(c != 1){
        r.push_back(c); 
        c = p[c];
    }
    r.push_back(c);
    reverse(r.begin(), r.end());
    for(int k : r) cout << k << " ";
    return 0;
}