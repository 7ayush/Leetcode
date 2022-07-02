class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>rows(9,vector<int>(9,0));
        vector<vector<int>>cols(9,vector<int>(9,0));
        vector<vector<int>>box(9,vector<int>(9,0));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')continue;
                int x=board[i][j]-'1';
                rows[i][x]++;
                cols[j][x]++;
                int z=(i/3)*3+j/3;
                box[z][x]++;
            }    
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(rows[i][j]>1)return false;
                if(cols[i][j]>1)return false;
                if(box[i][j]>1)return false;
            }    
        }
        return true;
    }
};
