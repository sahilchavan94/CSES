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
        int a, b; 
        cin >> a >> b; 
        v[i] = {a, b, i}; 
    } 
    sort(v.begin(), v.end(), [](const vi &a, const vi &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    int ans = 0;
    vector<int> rooms(n);
    for(int i = 0;i < n;i++){
        int a = v[i][0], d = v[i][1], idx = v[i][2];
        if(!pq.empty() && pq.top().first < a){
            auto [dt, rm] = pq.top(); pq.pop();
            pq.push({d, rm});
            rooms[idx] = rm;
        }
        else{
            ans++;
            pq.push({d, ans});
            rooms[idx] = ans;
        }
    }
    cout << ans << endl;
    for(int &r : rooms) cout << r << " ";
    return 0;
}