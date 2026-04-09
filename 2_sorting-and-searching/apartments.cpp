#include<bits/stdc++.h>
using namespace std;

// int bs(vector<long long>& apts, long long apl, long long k){

//     int l = 0, r = apts.size() - 1; 
//     long long lr = apl - k, rr = apl + k;
//     int idx = -1;

//     while(l <= r){
//         int m = (l + r) / 2; 
//         if(apts[m] < lr) l = m + 1; 
//         else if(apts[m] > rr) r = m - 1; 
//         else { 
//             idx = m; 
//             r = m - 1;
//         }
//     }

//     return idx;
// }

int main()
{
    cin.tie(NULL);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> apls(n), apts(m);
    for(int i = 0;i < n;i++) cin >> apls[i]; 
    for(int i = 0;i < m;i++) cin >> apts[i];

    sort(apls.begin(), apls.end()); 
    sort(apts.begin(), apts.end());

    int ans = 0;
    // for(int i = 0;i < n;i++){
    //     int idx = bs(apts, apls[i], k);
    //     if(idx != -1) {
    //         apts.erase(apts.begin() + idx);
    //         ans++;
    //     }
    // }

    int i = 0, j = 0; 
    while(i < n && j < m){
        long long diff = abs(apls[i] - apts[j]);
        if(diff <= k){
            ans += 1; 
            i++; j++;
        }else if(apls[i] < apts[j]){
            i++;
        }else{
            j++;
        }
    }
    
    cout << ans << endl;
    return 0;
}