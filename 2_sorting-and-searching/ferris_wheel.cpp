#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    long long x; long long n;
    cin >> n >> x; 
    vector<long long> p(n);
    for(int i = 0;i < n;i++) cin >> p[i];

    sort(p.begin(), p.end());

    int i = 0, j = n - 1; 
    int ans = 0;

    while(i <= j){
        if(p[i] + p[j] <= x){
            i++; j--;
        }else{
            j--;
        }
        ans += 1;
    }

    cout << ans << endl;
    return 0;
}