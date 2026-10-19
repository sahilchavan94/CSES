#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    int t; cin >> t; 
    vector<string> ans;
    while(t--){
        long long a, b; 
        cin >> a >> b;
        long long x = ((2LL * b) - a); 
        long long y = ((2LL * a) - b); 
        if(x >= 0 && y >= 0 && x % 3LL == 0 && y % 3LL == 0) ans.push_back("YES");
        else ans.push_back("NO");
    }
    for(auto a : ans) cout << a << endl;
    return 0;
}