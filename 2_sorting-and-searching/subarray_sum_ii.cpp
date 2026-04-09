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
    map<ll, int> mpp; mpp[0] = 1; 
    ll sum = 0, ans = 0;
    for(int i = 0;i < n;i++){
        sum += v[i];
        ll rem = sum - x;
        if(mpp.count(rem)) ans += mpp[rem];
        mpp[sum]++;
    }    
    cout << ans << endl;
    return 0;
}