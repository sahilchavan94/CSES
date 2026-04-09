#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    long long n; cin >> n;
    vector<long long> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    long long ans = LLONG_MIN; 
    long long current = 0;
    for(int i = 0;i < n;i++){
        current += nums[i];
        ans = max(ans, current);
        if(current < 0) current = 0;
    }
    cout << ans << endl;
    return 0;
}