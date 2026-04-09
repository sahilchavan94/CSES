#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    int n; cin >> n; 
    vector<pair<ll, ll>> c;
    while(n--){
        long long a, b; 
        cin >> a >> b; 
        c.push_back({a, 1});
        c.push_back({b, -1});
    }
    sort(c.begin(), c.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b){
        return a.first < b.first;
    });

    long long ans = 0, current = 0;
    for(pair<ll,ll> e : c){
        current += e.second; 
        ans = max(ans, current);
    }

    cout << ans << endl;
    return 0;
}