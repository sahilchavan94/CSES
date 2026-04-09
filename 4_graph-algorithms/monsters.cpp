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
    int m, n; cin >> m >> n; 
    char l[m][n]; int mt[m][n], v[m][n];
    qpi q; pii A; 
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin >> l[i][j];
            if(l[i][j] == 'A') A = {i,j};
            v[i][j] = 0;
            mt[i][j] = 1e9;
            if(l[i][j] == 'M') {
                v[i][j] = 1;
                q.push({i, j});
                mt[i][j] = 0;
            }; 
        }
    }
    vi dirs = {0, -1, 0, 1, 0};
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        for(int i = 0;i < dirs.size() - 1;i++){
            int nr = r + dirs[i], nc = c + dirs[i + 1]; 
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && l[nr][nc] != '#'){
                if(mt[nr][nc] > 1 + mt[r][c]){
                    mt[nr][nc] = 1 + mt[r][c];
                    q.push({nr, nc});
                }
            }
        }
    }
    int t = 0; 
    while(!q.empty()) q.pop();
    q.push(A); 
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            v[i][j] = 0;
        }
    }
    v[A.first][A.second] = 1; 
    bool found = false;
    vector<vector<pii>> p(m, vector<pii>(n));
    vector<vector<char>> mv(m, vector<char>(n)); pii B;
    char moves[] = {'L','U','R','D'};
    while(!q.empty()){
        int s = q.size();
        while(s--){
            auto [r, c] = q.front(); q.pop(); 
            if(r == 0 || c == 0 || r == m - 1 || c == n - 1) {
                B = {r, c};
                found = true;
                break;
            }
            for(int i = 0;i < dirs.size() - 1;i++){
                int nr = r + dirs[i], nc = c + dirs[i + 1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && l[nr][nc] != '#' && !v[nr][nc]){
                    if(mt[nr][nc] <= t + 1) continue; 
                    v[nr][nc] = 1; 
                    q.push({nr,nc});
                    p[nr][nc] = {r, c}; 
                    mv[nr][nc] = moves[i];
                }
            }
        }
        if(found) break;
        t++;
    }

    if(!found) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    string path = "";
    while(B != A){
        path += mv[B.first][B.second]; 
        B = p[B.first][B.second];
    }
    reverse(path.begin(), path.end());
    cout << t << endl;
    cout << path << endl;
    return 0;
}