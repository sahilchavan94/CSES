#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define MOD 1e9 + 7 

int main()
{
    cin.tie(NULL);
    int n; cin >> n;
    vi nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    unordered_set<int> st; ll ans = 0; 
    for(int r = 0; r < n; r++){
        if(st.count(nums[r])) continue;
        else st.insert(nums[r]);
        ans += st.size();
    }
    cout << ans << endl;
    return 0;
}