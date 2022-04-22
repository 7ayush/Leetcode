// Brute Force solution TLE
class Solution {
public:
    bool finder(vector<vector<char>>board,int i,int j,string word,vector<vector<int>>visited)
    {
        if(word=="")return true;
        if(visited[i][j]==true)return false;        
        if(word[0]==board[i][j])
        {
            visited[i][j]=true;
            bool p=false;
            if(i>0)
            {
                p=finder(board,i-1,j,word.substr(1),visited); 
                if(p==true)return p;
            }            
            if(j>0)
            {
                p=finder(board,i,j-1,word.substr(1),visited);    
                if(p==true)return p;
            }           
            if(i<board.size()-1)
            {
                p=finder(board,i+1,j,word.substr(1),visited);
                if(p==true)return p;
            }        
            if(j<board[0].size()-1)
            {
                p=finder(board,i,j+1,word.substr(1),visited);                
                if(p==true)return p;
            }
            if(word.substr(1)=="")return true;   
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(board[0].size(),0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(finder(board,i,j,word,visited))return true;
            }   
        }
        return false;
    }
};

//It Runs
class Solution {
public:
    //pass board by reference
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {
		//check if all the alphabets in the word is checked
        if(n == word.size()) return true; 
        
		//check if i and j are out of bound or if the characters aren't equal
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        
		//mark as visited 
        board[i][j] = '0';
        
		//branch out in all 4 directions
        bool status = DFS(board, word, i + 1, j, n + 1) ||  //down
                        DFS(board, word, i, j + 1, n + 1) ||  //right
                        DFS(board, word, i - 1, j, n + 1) ||  //up
                        DFS(board, word, i, j - 1, n + 1);  //left
        
		//change the character back for other searches
        board[i][j] = word[n];
		
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
				//check if the characters are equal then call DFS
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
        
        return false;
    }
};
