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
    vector<int> p(n); 
    for(int i = 0;i < n;i++) cin >> p[i];
    int ans = 0;
    int l = 0; 
    map<int ,int> mpp;
    for(int r = 0; r < n;r++){
        if(mpp.count(p[r])) {
            int idx = mpp[p[r]];
            l = max(l, idx + 1);
        }
        mpp[p[r]] = r;
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}