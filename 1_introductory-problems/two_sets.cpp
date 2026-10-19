#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    int n; cin >> n;
    ll sum = 0;
    for(ll i = 1;i <= n;i++) sum += i;

    if(sum % 2LL) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        cout << "YES" << endl; 
        sum /= 2LL;
        vector<ll> s1, s2; 
        while(n){
            if(sum - n >= 0){
                s1.push_back(n);
                sum -= n;
            }else{
                s2.push_back(n);
            }
            n--;
        }
        cout << s1.size() << endl;
        for(ll s : s1) cout << s << " ";
        cout << endl << s2.size() << endl; 
        for(ll s : s2) cout << s << " ";
        cout << endl;
    }
    
    return 0;
}