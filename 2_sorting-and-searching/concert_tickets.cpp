#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ll n, m; 
    cin >> n >> m; 
    multiset<long long> t;
    for(int i = 0;i < n;i++) {
        long long tk; 
        cin >> tk; 
        t.insert(tk);
    }

    for(int i = 0;i < m;i++){
        long long c; cin >> c; 
        auto it = t.upper_bound(c);
        if(it != t.begin()){
            it--; 
            cout << *it << endl;
            t.erase(it);
        }else{
            cout << -1 << endl;
        }
    }

    return 0;
}