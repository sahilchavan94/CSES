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

int main()
{
    cin.tie(NULL);
    int n; cin >> n; 
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++){
            cin >> grid[i][j]; 
        }
    }
    if(grid[0][0] == '*') {
        cout << 0 << endl; 
        return 0;
    } 
    vector<vi> dp(n, vi(n, 0)); 
    dp[0][0] = 1; 
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if((i == 0 && j == 0) || grid[i][j] == '*') continue;
            int left = 0, up = 0;
            if(i > 0 && grid[i - 1][j] != '*') up = dp[i - 1][j]; 
            if(j > 0 && grid[i][j - 1] != '*') left = dp[i][j - 1];
            dp[i][j] = (up + left) % (int)(1e9 + 7);
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}