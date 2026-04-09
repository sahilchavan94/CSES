#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n; cin >> n;
    vector<long long> nums(n); 
    for(int i = 0;i < n;i++) cin >> nums[i];
    long long ans = 0;
    for(int i = 1;i < n;i++) {
        if(nums[i] < nums[i - 1]) {
            ans += nums[i - 1] - nums[i]; 
            nums[i] = nums[i - 1];
        }
    }
    cout << ans;
}