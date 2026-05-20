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
    int n, m, q; cin >> n >> m >> q; 
    vector<vll> d(n, vll(n, LLONG_MAX));
    for(int i = 0;i < n;i++) d[i][i] = 0;
    for(int i = 0;i < m;i++){
        int a, b; ll c; cin >> a >> b >> c; 
        d[a - 1][b - 1] = min(d[a - 1][b - 1], c);
        d[b - 1][a - 1] = min(d[a - 1][b - 1], c);
    }
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    for(int i = 0;i < q;i++){
        int a, b; cin >> a >> b; 
        ll t = d[a - 1][b - 1];
        if(t == LLONG_MAX) cout << -1 << endl; 
        else cout << t << endl;
    }
    return 0;
}