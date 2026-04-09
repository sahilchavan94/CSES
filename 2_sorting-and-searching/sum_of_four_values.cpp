#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int main()
{
    cin.tie(NULL);
    ll n, x; cin >> n >> x; 
    vector<pll> v(n); 
    for(int i = 0;i < n;i++){
        ll a; cin >> a; 
        v[i] = {a, i + 1};
    }
    sort(v.begin(), v.end(),[](const pll &a, const pll &b){
        return a.first < b.first;
    });
    unordered_map<ll, vector<pll>> mpp;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            ll sum = v[i].first + v[j].first;
            ll rem = x - sum; 
            for(pll &p : mpp[rem]){
                if(p.first != v[i].second && p.second != v[i].second && 
                    p.first != v[j].second && p.second != v[j].second){
                    cout << v[i].second << " " << v[j].second << " " 
                    << p.first << " " << p.second << endl;
                    return 0;
                }
           }
           mpp[sum].push_back({v[i].second, v[j].second});
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}