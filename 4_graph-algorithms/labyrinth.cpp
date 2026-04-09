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
    char g[m][n]; int v[m][n]; 
    pii A, B; 
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin >> g[i][j]; 
            if(g[i][j] == 'A') A = {i,j};
            if(g[i][j] == 'B') B = {i,j};
            v[i][j] = 0;
        }
    }
    pii p[m][n]; char mv[m][n]; 
    int d[5] = {0, -1, 0, 1, 0}, steps = 0; 
    char dlbl[4] = {'L', 'U', 'R', 'D'}; 
    qpi q; q.push(A); v[A.first][A.second] = 1; 
    bool found = false;
    while(!q.empty()){
        int sz = q.size(); 
        while(sz--){
            auto [row, col] = q.front(); q.pop(); 
            if(row == B.first && col == B.second) {
                found = true; 
                break;
            };
            v[row][col] = 1;
            for(int i = 0;i < 4;i++){
                int nr = row + d[i], nc = col + d[i + 1]; 
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !v[nr][nc] && g[nr][nc] != '#'){
                    v[nr][nc] = 1; 
                    q.push({nr,nc});
                    p[nr][nc] = {row,col};
                    mv[nr][nc] = dlbl[i];
                }
            }
        }
        if(found) break;
        steps++;
    }

    if(!found){
        cout << "NO" << endl; 
        return 0;
    }

    cout << "YES" << endl; 
    cout << steps << endl; 
    string path = "";
    pii current = B; 
    while(current != A) {
        path += mv[current.first][current.second]; 
        current = p[current.first][current.second];
    }
    reverse(path.begin(), path.end());
    cout << path << endl;
    return 0;
}