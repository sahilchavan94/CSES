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
    int n; cin >> n; 
    vector<vector<char>> g(n, vector<char>(n));
    vector<vector<int>> vis(n, vector<int>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> g[i][j]; 
        }
    }
    string ans = string(1, g[0][0]); 
    qpi f, tf; 
    f.push({0, 0}); 
    vis[0][0] = 1;
    vector<int> dirs = {0, 1, 0}; 
    while(ans.size() < 2*n-1) {
        char best = '[';
        while(!f.empty()){
            auto [x, y] = f.front(); 
            f.pop(); 
            for(int i = 0;i < dirs.size() - 1;i++){
                int nr = x + dirs[i], nc = y + dirs[i + 1]; 
                if(nr >= n || nc >= n || g[nr][nc] > best || vis[nr][nc]) continue;
                vis[nr][nc] = 1;
                if(g[nr][nc] < best){
                    best = g[nr][nc]; 
                    while(tf.size()) tf.pop();
                }
                tf.push({nr, nc});
            }
        }
        while(tf.size()) {
            f.push(tf.front()); 
            tf.pop();
        }
        if(ans.size() < 2 * n + 1) ans += best;
    }
    cout << ans << endl;
    return 0;
}