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
int dp[5001][5001];

int recursive(string &m, string &n, int i, int j){
    int s1 = m.size(), s2 = n.size();
    if(i == s1) return s2 - j;
    if(j == s2) return s1 - i;
    if(dp[i][j] != -1) return dp[i][j];
    if(m[i] == n[j]) return dp[i][j] = recursive(m, n, i + 1,j + 1);
    int insert = 1 + recursive(m, n, i, j + 1);
    int del = 1 + recursive(m, n, i + 1, j);
    int rep = 1 + recursive(m, n, i + 1,j + 1);
    return dp[i][j] = min({insert, del, rep});
}

int tabulation(string &m, string &n){
    int s1 = m.size(), s2 = n.size(); 
    vector<vi> dp(s1 + 1, vi(s2 + 1, 0));
    for(int i = 0;i <= s1;i++) dp[i][0] = i;
    for(int i = 0;i <= s2;i++) dp[0][i] = i;
    for(int i = 1;i <= s1;i++){
        for(int j = 1;j <= s2;j++){
            if(m[i - 1] == n[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                int ins = dp[i][j - 1]; 
                int del = dp[i - 1][j]; 
                int rep = dp[i - 1][j - 1];
                dp[i][j] = 1 + min({ins, del, rep});
            }
        }
    }
    return dp[s1][s2];
}

int main()
{
    cin.tie(NULL);
    string m, n; 
    cin >> m >> n;
    memset(dp, -1, sizeof(dp));
    cout << tabulation(m, n) << endl;
    return 0;
}