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

#define imin INT_MIN
#define imax INT_MAX
#define lmin LLONG_MIN
#define lmax LLONG_MAX
#define MOD 1000000007

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n, a, b; 
        cin >> n >> a >> b; 
        int d = max(0, n - (a + b)), g = n - d; 
        if((a && a == g) || (b && (b == g)) || a + b > g || (n == 1 && (a || b))) {
            cout << "NO\n"; 
            continue;
        }
        cout << "YES\n"; 
        // all numbers for upper row 
        for(int i = 1;i <= n;i++){
            if(i == n) cout << i << "\n";
            else cout << i << " "; 
        }

        // number of games b has won
        for(int i = g - b + 1;i <= g;i++)
            cout << i << " ";

        // number of games a has won
        for(int i = 1;i <= g - b;i++) {
            if(i == g - b) {
                if(d) cout << i << " "; 
                else cout << i << "\n";
            }
            else {
                cout << i << " ";
            }
        }
        
        // remaining draw games
        for(int i = g + 1;i <= n;i++){
            if(i == n) cout << i << "\n";
            else cout << i << " ";
        }
    }
    return 0;
}

// 3 1 2
// 1 2 3 | 4 5 6 
// 2 3 1 | 4 5 6 

// 2 0 1 
// 1 2 
// 1 2


// 1 2 3 4 5 6 7 8 | 9 10
// 6 7 8 1 2 3 4 5

// 1 2 3 4 5 
// 3 4 5 1 2 