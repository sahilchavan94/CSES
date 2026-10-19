#include<bits/stdc++.h>
using namespace std;

bool safe(vector<string>& board, int i, int j){
    int row = i - 1, col = j - 1; 
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--; col--; 
    }
    col = j - 1; 
    while(col >= 0){
        if(board[i][col] == 'Q') return false;
        col--;
    }
    row = i + 1;
    col = j - 1;
    while(row < 8 && col >= 0){
        if(board[row][col] == 'Q') return false; 
        row++; col--;
    }

    return true;
}

void helper(vector<string>& board, int c, int &ans){
    if(c == 8) {
        ans = ans + 1; 
        return;
    }
    for(int i = 0;i < 8;i++){
        if(board[i][c] == '*') continue; 
        if(safe(board, i, c)){
            board[i][c] = 'Q';
            helper(board, c + 1, ans); 
            board[i][c] = '.';
        } 
    }
    return;
}

int main()
{
    cin.tie(NULL);
    int ans = 0;
    vector<string> board(8,string('.',8)); 
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            cin >> board[i][j];
        }
    }
    helper(board, 0, ans);
    cout << ans << endl;
    return 0;
}