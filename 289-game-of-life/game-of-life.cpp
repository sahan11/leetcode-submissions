class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> board2 = board;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                vector<int> drow{-1, -1, -1, 0, 1, 1, 1, 0};
                vector<int> dcol{-1, 0, 1, 1, 1, 0, -1, -1};
                int cnt = 0;
                for(int k = 0;k<8;k++){
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                        if(board[nrow][ncol] == 1) cnt++;
                    }
                }
                cout<<i<<" "<<j<<" "<<cnt<<endl;
                if(board[i][j] == 1){
                    if(cnt < 2){
                        cout<<i<<" "<<j<<" "<<cnt<<" "<<"First "<<endl;
                        board2[i][j] = 0;
                    }
                    else if(cnt > 3){
                        cout<<i<<" "<<j<<" "<<cnt<<" "<<"Second "<<endl;
                        board2[i][j] = 0;
                    }
                }
                else{
                    if(cnt == 3){
                        cout<<i<<" "<<j<<" "<<cnt<<" "<<"Third "<<endl;
                        board2[i][j] = 1;
                    }
                }
            }
        }
        board = board2;
    }
};