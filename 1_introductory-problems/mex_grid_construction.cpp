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
    // this is one unintuitive questions
    // brute force is thinkable but not this xor approach 
    // need to study the proof behind this
    int n; cin >> n; 
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cout << (i ^ j) << " ";
        cout << "\n";
    }
    return 0;
}