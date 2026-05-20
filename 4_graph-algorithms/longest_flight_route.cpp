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
    unordered_map<int, vector<int>> g; 
    vi in(n + 1, 0);
    for(int i = 0;i < m;i++){
        int a, b; cin >> a >> b; 
        g[a].push_back(b); 
        in[b]++;
    }
    vi d(n + 1,-1),p(n + 1,-1); d[1] = 1; qi q; 
    vi ans; 
    for(int i = 1;i <= n;i++){
        if(!in[i]){
            q.push(i);
        }
    }
    if(q.empty()){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
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
    for(int a : ans){
        if(d[a] == -1) continue;
        for(int nx : g[a]){
            if(d[nx] < 1 + d[a]){
                d[nx] = 1 + d[a];
                p[nx] = a;
            }
        }
    }
    if(d[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << d[n] << endl;
    vi pth; int c = n; 
    while(p[c] != -1){
        pth.push_back(c); 
        c = p[c]; 
    }
    pth.push_back(c); 
    reverse(pth.begin(), pth.end());
    for(int f : pth) cout << f << " ";
    return 0;
}