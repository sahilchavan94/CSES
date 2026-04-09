#include<bits/stdc++.h>
using namespace std;

void helper(){

}

int main()
{
    cin.tie(NULL);
    string s; cin >> s; 
    sort(s.begin(), s.end());
    vector<string> ans;

    ans.push_back(s);
    while(next_permutation(s.begin(), s.end())){
        ans.push_back(s);
    }
        
    cout << ans.size() << endl;
    for(string a : ans) cout << a << endl;
    return 0;
}