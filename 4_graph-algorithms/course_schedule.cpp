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
    unordered_map<int, vector<int>> c; 
    vi in(n + 1, 0);
    for(int i = 0;i < m;i++){
        int a, b; cin >> a >> b; 
        c[a].push_back(b);
        in[b]++;
    }
    qi q; vi ans;
    for(int i = 1;i <= n;i++) if(!in[i]) {
        q.push(i); 
        ans.push_back(i);
    }
    if(q.empty()){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(int nc : c[t]){
            in[nc]--;
            if(in[nc] == 0){
                ans.push_back(nc);
                q.push(nc); 
            }
        }
    }
    if(ans.size() < n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int a : ans) cout << a << " ";
    return 0;
}