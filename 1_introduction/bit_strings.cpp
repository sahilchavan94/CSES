#include<bits/stdc++.h>
using namespace std;

long long binpow(long long n){
    long long res = 1, mod = 1e9 + 7;
    long long base = 2;
    while(n > 0){
        if(n & 1) res = (res * base) % mod; 
        base = (base * base) % mod; 
        n >>= 1;
    }
    return res;
}

int main()
{
    cin.tie(NULL);
    long long n; cin >> n;
    cout << binpow(n) << endl;
    return 0;
}