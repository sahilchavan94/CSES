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

#define imin INT_MIN
#define imax INT_MAX
#define lmin LLONG_MIN
#define lmax LLONG_MAX
#define MOD 1000000007

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m; cin >> n >> m; 
    vector<vector<char>> g(n, vector<char>(m)), ans(n, vector<char>(m));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> g[i][j]; 
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++){
            vi a(4, 0); 
            if(i) a[ans[i - 1][j] - 'A'] = 1; 
            if(j) a[ans[i][j - 1] - 'A'] = 1; 
            a[g[i][j] - 'A'] = 1; 
            for(int k = 0;k < 4;k++) {
                if(!a[k]){
                    char c = 'A' + k; 
                    ans[i][j] = c;
                    break;
                }
            }
        }  
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << ans[i][j]; 
        }
        cout << "\n";
    }
    return 0;
}