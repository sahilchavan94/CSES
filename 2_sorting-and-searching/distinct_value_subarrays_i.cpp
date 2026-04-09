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
    vi nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    unordered_set<int> st; 
    int l = 0; ll ans = 0;
    for(int r = 0; r < n; r++){
        while(st.count(nums[r])){
            st.erase(nums[l]);
            l++;
        }
        st.insert(nums[r]);
        ans += (r - l + 1);
    }
    cout << ans << endl;
    return 0;
}