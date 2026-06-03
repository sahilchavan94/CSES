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

void dfs1(int i, vi &vis, si &st, unordered_map<int,vector<int>> & g){
    vis[i] = 1; 
    for(int nxt : g[i]){
        if(!vis[nxt]) dfs1(nxt, vis, st, g);
    }
    st.push(i);
}

void dfs2(int i, vi & vis, unordered_map<int, vector<int>> &rg, vi &comp, int id){
    vis[i] = 1; comp[i] = id; 
    for(int nxt : rg[i]){
        if(!vis[nxt]) dfs2(nxt, vis, rg, comp, id);
    }
}

int main()
{
    cin.tie(NULL);
    int n, m, k = 0; cin >> n >> m;
    unordered_map<int,vector<int>> g, rg; 
    vi comp(n + 1), vis(n + 1, 0); si st; 
    for(int i = 0;i < m;i++){
        int a, b; cin >> a >> b; 
        g[a].push_back(b); rg[b].push_back(a); 
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]) dfs1(i, vis, st, g);
    }
    fill(vis.begin(), vis.end(), 0); 
    while(!st.empty()){
        int node = st.top(); st.pop();
        if(!vis[node]){
            k++;
            dfs2(node, vis, rg, comp, k);
        }
    }
    cout << k << endl;
    for(int i = 1;i <= n;i++) cout << comp[i] << " ";
    return 0;
}