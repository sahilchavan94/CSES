#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

bool compare(pll &a, pll &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    cin.tie(NULL);
    int n; cin >> n;
    vector<pll> v(n);
    for(int i = 0;i < n;i++){
        ll a, b; 
        cin >> a >> b; 
        v[i] = {a, b};
    }
    sort(v.begin(), v.end(), compare); 
    ll time = 0;
    ll ans = 0;
    for(int i = 0;i < n;i++){
        time += v[i].first;
        ans += v[i].second - time;
    }
    cout << ans << endl;
    return 0;
}