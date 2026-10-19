#include<bits/stdc++.h>
using namespace std;
using ll = long long;

long long helper(vector<ll>& apples, ll current, ll total, int i){
    if(i == apples.size()) {
        return (total == 0) ? LLONG_MAX : abs(current - total);
    }
    ll picked = helper(apples, current + apples[i], total - apples[i], i + 1); 
    ll skipped = helper(apples, current, total, i + 1); 
    return min(picked, skipped);
}

int main()
{
    cin.tie(NULL);
    int n; cin >> n; 
    vector<ll> apples(n);
    ll sum = 0;
    for(int i = 0;i < n;i++){
        cin >> apples[i];
        sum += apples[i];
    }
    
    cout << helper(apples, 0LL, sum, 0) << endl;
    return 0;
}