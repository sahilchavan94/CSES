#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int tpop(queue<int> &q){
    int t = q.front(); q.pop();
    return t;
}

int main()
{
    cin.tie(NULL);
    int n; cin >> n;
    queue<int> q; 
    for(int i = 1;i <= n;i++) q.push(i);
    while(!q.empty()){
        int t = tpop(q);
        q.push(t); 
        int r = tpop(q);
        cout << r << " ";
    }
    return 0;
}