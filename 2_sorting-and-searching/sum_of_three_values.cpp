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
    int n, x; cin >> n >> x;
    vector<pll> v(n);
    for(int i = 0;i < n;i++) {
        ll a; cin >> a; 
        v[i] = {a, i + 1};
    }
    sort(v.begin(), v.end(), [](const auto &a, const auto &b){
        return a.first < b.first;
    }); 
    for(int i = 0;i < n;i++){
        ll c = v[i].first; 
        ll rem = x - c; 
        int l = 0, r = n - 1; 
        while(l < r){
            if(l == i) l++; 
            if(r == i) r--;
            if(l >= r) break;
            ll sum = v[l].first + v[r].first; 
            if(sum == rem) {
                cout << v[i].second << " " << v[l].second << " " << v[r].second << endl;
                return 0;
            }else if(sum < rem) {
                l++;
                while(l < r && v[l].first == v[l - 1].first) l++; 
            } 
            else {
                r--;
                while(l < r && v[r].first == v[r + 1].first) r--; 
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}