#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    string s; cin >> s;
    unordered_map<char, int> mpp;
    for(char c : s) mpp[c]++;

    int od = 0;
    
    for(auto [ch,cnt] : mpp){
        if(cnt % 2) {
            od++;
        }
        if(od > 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
   
    int i = 0, j = s.length() - 1;
    string ans(s.length(),' ');

    for(auto [ch, cnt] : mpp){
        if(!(cnt % 2)){
            while(cnt){
                ans[i++] = ans[j--] = ch;
                cnt -= 2;
            }
        }
    }

    char oc; 
    for(auto [ch, cnt] : mpp){
        if(cnt % 2) {
            oc = ch;
            break;
        }
    }

    if(oc){
        for(int k = i;k <= j;k++){
            ans[k] = oc;
        }
    }
    
    cout << ans << endl;
    return 0;
}