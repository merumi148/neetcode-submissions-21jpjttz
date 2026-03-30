class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        
        
        for(int i = 0; i < n; i++){
            set<char> seen;
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.') continue;
                if(seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        for(int j = 0; j < n; j++){
            set<char> seen;
            for(int i = 0; i < n; i++){
                if(board[i][j] == '.') continue;
                if(seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);   
            }
        }
        for(int s = 0; s < 9 ;s++){
            set<char> seen;
            for(int i = 0; i < 3; i++){
                for(int j = 0 ; j< 3; j++){
                  int row = (s / 3) * 3 + i;
                  int col = (s % 3) * 3 + j;
                  if(board[row][col] == '.') continue;
                  if(seen.count(board[row][col])) return false;
                  seen.insert(board[row][col]);   
                }
            }
        }
        return true;
    }
};
