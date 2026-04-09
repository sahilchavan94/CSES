#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    int n; cin >> n; 
    vector<vector<long long>> board(n, vector<long long>(n, LLONG_MAX));
    board[0][0] = 0;
    queue<tuple<int,int,int>> q; 
    q.push({0, 0, 0}); 

    vector<int> x = {-1, -2, -2, -1, 1, 2, 2, 1}; 
    vector<int> y = {-2, -1, 1, 2, 2, 1, -1, -2};
    while(!q.empty()){
        auto [row, col, cost] = q.front(); q.pop();
        for(int i = 0;i < 8;i++){
            int nx = row + x[i], ny = col + y[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(board[nx][ny] > cost + 1){
                    board[nx][ny] = cost + 1;
                    q.push({nx, ny, cost + 1});
                }
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}