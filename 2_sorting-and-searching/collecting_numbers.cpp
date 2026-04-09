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
    ll n; cin >> n;
    vll nums(n); 
    unordered_map<long long, int> mpp;
    for(int i = 0;i < n;i++) {
        cin >> nums[i]; 
        mpp[nums[i]] = i;
    }
    int ans = 1; 
    for(int i = 1;i <= n - 1;i++){
        if(mpp[i] > mpp[i + 1]){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}