#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using si = stack<int>;
using sll = stack<ll>;
using spi = stack<pii>; 
using spll = stack<pll>; 
using qi = queue<int>;
using qll = queue<ll>;
using qpi = queue<pii>;
using pqll = queue<pll>;

int main()
{
    cin.tie(NULL);
    int n; cin >> n;
    vll v(n);
    for(int i = 0;i < n;i++) cin >> v[i];
    spll s; 
    vector<int> ans(n);
    for(int i = 0;i < n;i++){
        if(i == 0) {
            ans[i] = 0;
            s.push({v[i], i + 1});
        }else{
            while(!s.empty() && s.top().first >= v[i]){
                s.pop();
            }
            if(s.empty()) ans[i] = 0; 
            else ans[i] = s.top().second; 
            s.push({v[i], i + 1});
        }
    }
    for(int idx : ans) cout << idx << " ";
    return 0;
}