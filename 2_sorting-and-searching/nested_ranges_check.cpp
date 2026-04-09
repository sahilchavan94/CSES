#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int main()
{
    cin.tie(NULL);
    int n; cin >> n; 
    vector<vi> v(n);
    for(int i = 0;i < n;i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y, i};
    }
    sort(v.begin(), v.end(), [](const vi &a, const vi &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    vi in(n, 0), out(n, 0);
    int mxr = 0;
    for(int i = 0;i < n;i++){
        if(v[i][1] <= mxr) in[v[i][2]] = 1;
        mxr = max(mxr, v[i][1]);
    }
    int mnl = INT_MAX;
    for(int i = n - 1;i >= 0;i--){
        if(v[i][1] >= mnl) out[v[i][2]] = 1; 
        mnl = min(mnl, v[i][1]);
    }
    for(int o : out) cout << o << " ";
    cout << endl;
    for(int i : in) cout << i << " "; 
    return 0;
}