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
    string s; cin >> s; 
    int len = (int) s.length(); 
    map<char,int> mpp;
    for(char &c : s) mpp[c]++; 
    int mx = len / 2 + (len % 2); 
    for(auto [ch, cnt] : mpp){
        if(cnt > mx) {
            cout << -1 << "\n";
            return 0;
        }
    }
    int rem = (int)s.length();
    string ans = "";
    while(rem) {
        int f = 1; 
        for(char c = 'A'; c <= 'Z';c++) {
            if(!ans.empty() && c == ans.back()) continue;
            if(mpp.count(c) && mpp[c] > rem / 2) {
                mpp[c]--; 
                f = 0; 
                if(!mpp[c]) 
                    mpp.erase(c);
            }
            if(!f){
                ans += c; 
                break; 
            }
        }
        if(f){
            for(char c = 'A';c <= 'Z';c++){
                if(!ans.empty() && c == ans.back()) continue;
                if(mpp.count(c)){
                    ans += c; mpp[c]--; 
                    if(!mpp[c]) 
                        mpp.erase(c); 
                    break;
                }
            }
        }
        rem--;
    }
    cout << ans << "\n";
    return 0;
}
