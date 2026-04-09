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
    ll n, x; cin >> n >> x;
    vll v(n);
    for(int i = 0;i < n;i++) cin >> v[i]; 
    if(accumulate(v.begin(), v.end(), 0LL) < x) {
        cout << 0 << endl;
        return 0;
    }
    ll l = 0, sum = 0, ans = 0;
    for(ll r = 0; r < n;r++){
        sum += v[r];
        while(sum > x) {
            sum -= v[l];
            l++;
        }
        if(sum == x) ans++;
    }
    cout << ans << endl;
    return 0;
}