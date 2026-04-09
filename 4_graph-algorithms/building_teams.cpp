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
    unordered_map<int,vector<int>> g;
    for(int i = 0;i < m;i++){
        int a, b; cin >> a >> b; 
        g[a].push_back(b);
        g[b].push_back(a); 
    }
    vi teams(n + 1, -1);
    for(int i = 1;i <= n;i++){
        if(teams[i] == -1){
            teams[i] = 1; 
            qpi q; q.push({i, 1});
            while(!q.empty()){
                auto [f, t] = q.front(); q.pop();
                for(int nf : g[f]){
                    if(t == teams[nf]) {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                    if(teams[nf] == -1){
                        if(t == 1) teams[nf] = 2; 
                        else teams[nf] = 1; 
                        q.push({nf, teams[nf]});
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;i++) cout << teams[i] << " ";
    return 0;
}