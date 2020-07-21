class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.size()==0 || board[0].size()==0) return false;
        m = board.size(); //rows
        n = board[0].size();//columns
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dfs(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
private:
    int m,n;
    bool dfs(vector<vector<char>>& board, string& word,int k,int i,int j){
        if( i<0 || i>=m || j<0 || j>=n || word[k]!=board[i][j]) return false;
        if(k == word.length()-1) return true;
        char c = board[i][j]; //current letter on board
        board[i][j] = '*';
        bool next = dfs(board,word,k+1,i+1,j) || dfs(board,word,k+1,i-1,j) || dfs(board,word,k+1,i,j+1) ||                                             dfs(board,word,k+1,i,j-1);
        board[i][j] = c;
        return next;
    }
};