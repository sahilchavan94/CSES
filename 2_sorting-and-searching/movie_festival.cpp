#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    int n; cin >> n; 
    int nn = n;
    vector<pair<int,int>> m;
    while(n--){
        int a, b; 
        cin >> a >> b;
        m.push_back({a, b});
    }
    sort(m.begin(), m.end(),[](const auto &a, const auto &b){
        return a.second < b.second;
    });
    int ans = 1;
    auto current = m[0];
    for(int i = 1;i < nn;i++){
        if(m[i].first >= current.second) {
            current = m[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}