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
    unordered_map<int,vi> g; vi in(n + 1);
    for(int i = 0;i < m;i++){
        int a, b; cin >> a >> b; 
        g[a].push_back(b);
        in[b]++;
    }
    vll d(n + 1, 0); qi q; 
    for(int i = 1;i <= n;i++){
        if(in[i] == 0) {
            q.push(i);
        }
    }
    vi ans; 
    while(!q.empty()){
        int c = q.front(); q.pop();
        ans.push_back(c);
        for(int nx : g[c]){
            in[nx]--;
            if(in[nx] == 0){
                q.push(nx);
            }
        }
    }
    d[1] = 1;
    for(int a : ans){
        if(d[a] == 0) continue;
        for(int nx : g[a]){
            d[nx] = (d[nx] + d[a]) % MOD;
        }
    }
    cout << d[n] << " ";
    return 0;
}