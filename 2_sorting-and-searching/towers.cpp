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
    int n; cin >> n;
    multiset<int> mst; 
    int ans = 0;
    while(n--){
        int t; cin >> t;
        auto it = mst.upper_bound(t);
        if(it != mst.end()) mst.erase(it); 
        else ans++;
        mst.insert(t); 
    }
    cout << ans << endl;
    return 0;
}