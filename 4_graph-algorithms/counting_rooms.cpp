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
    char g[n][m]; int vis[n][m];
    int d[] = {0, -1, 0, 1, 0};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> g[i][j]; 
            vis[i][j] = 0;
        }
    }
    int rooms = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(g[i][j] == '.' && !vis[i][j]){
                spi st; st.push({i, j});
                while(!st.empty()){
                    auto [r,c] = st.top(); st.pop();
                    vis[r][c] = 1; 
                    for(int k = 0;k < 4;k++){
                        int nr = r + d[k], nc = c + d[k + 1]; 
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                            !vis[nr][nc] && g[nr][nc] == '.'){
                            st.push({nr,nc});
                        }
                    }
                }
                rooms += 1;
            }
        }
    }
    cout << rooms << endl;
    return 0;
}