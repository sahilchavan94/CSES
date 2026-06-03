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

int main()
{
    cin.tie(NULL);
    int n, q; cin >> n >> q; 
    vi nums(n + 1);
    for(int i = 1;i <= n;i++){
        int a; cin >> a;
        nums[i] = nums[i - 1] ^ a; 
    } 
    for(int i = 0;i < q;i++){
        int a, b; cin >> a >> b; 
        int xr = nums[b] ^ nums[a - 1];
        cout << xr << endl;
    }
    return 0;
}