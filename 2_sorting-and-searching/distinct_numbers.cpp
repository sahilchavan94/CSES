#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    int n; cin >> n;
    vector<long long> x(n);
    for(int i = 0;i < n;i++) {
        cin >> x[i];
    } 
    sort(x.begin(), x.end());

    int ans = 1;
    for(int i = 0; i < n - 1;i++){
        if(x[i] != x[i + 1]) ans++;
    }

    cout << ans << endl;
    return 0;
}