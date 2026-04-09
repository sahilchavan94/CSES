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
#define MOD 1000000007

class DisjointSet{
public:
    int s; vi p, r; 
    DisjointSet(int s){
        this->s = s; 
        p.resize(s, -1); 
        r.resize(s, 0);
        for(int i = 0;i < s;i++) p[i] = i;
    }
    int find(int x){
        while(p[x] != x) x = p[x];
        return x;
    }
    void uni(int x,int y){
        int px = find(x), py = find(y);
        if(px == py) return; 
        if(r[px] > r[py]) p[py] = px; 
        else if(r[py] > r[px]) p[px] = py;
        else {
            p[px] = py; 
            r[py] += 1;
        }
    }
};

int main()
{
    cin.tie(NULL);
    int n, m; cin >> n >> m; 
    DisjointSet ds(n); 
    for(int i = 0;i < m;i++) {
        int a, b; cin >> a >> b; a--; b--;
        ds.uni(a, b);
    }
    set<int> leads; 
    for(int i = 0;i < n;i++) leads.insert(ds.find(i));
    cout << leads.size() - 1 << endl;
    vector<int> vl(leads.begin(), leads.end()); 
    for(int i = 0;i < vl.size() - 1;i++){
        cout << vl[i] + 1 << " " << vl[i + 1] + 1 << endl;
    }
    return 0;
}