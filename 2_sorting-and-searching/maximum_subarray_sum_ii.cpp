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
    ll n, a, b; cin >> n >> a >> b; 
    vll x(n); 
    for(int i = 0;i < n;i++) cin >> x[i]; 
    ll l = 0, ans = 0, sum = 0;
    for(int r = 0;r < n;r++){
        sum += x[r];
        int d = r - l + 1; 
        if(d >= a){
            if(d <= b) {
                ans = max(ans, sum); 
            }else{
                while(d > b){
                    sum -= x[l]; d--;
                    l++;
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}