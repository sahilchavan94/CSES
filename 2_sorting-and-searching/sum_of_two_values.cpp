#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    int n, x; 
    cin >> n >> x; 
    vector<pii> nums(n);
    for(int i = 0;i < n;i++) {
        int n; cin >> n;
        nums[i] = {n, i};
    }
    sort(nums.begin(), nums.end(), [](const pii &a, const pii &b){
        return a.first < b.first; 
    });
    int l = 0, r = n - 1; 
    while(l < r){
        int sum = nums[l].first + nums[r].first;
        if(sum == x){
            cout << nums[l].second + 1 << " " << nums[r].second + 1 << endl;
            return 0;
        }else if(sum < x) l += 1; 
        else r -= 1;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}