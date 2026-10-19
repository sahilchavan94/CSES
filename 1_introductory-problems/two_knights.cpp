#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n; cin >> n;
    for(long long i = 1;i <= n;i++){
        long long t = (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)); 
        cout << t << endl;
    }
    return 0;
}