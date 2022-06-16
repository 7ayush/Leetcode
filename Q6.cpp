class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows==1)return s;
        vector<vector<char>>vec(numRows,vector<char>(s.size(),'\0'));        
        int i=0,j=0;
        bool up=false;
        for(char c:s)
        {
            vec[i][j++]=c;            
            if(i==numRows-1)up=true;
            if(i==0)up=false;
            
            if(up)i--;
            else i++;            
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(vec[i][j]!='\0')ans+=vec[i][j];
            }    
        }
        return ans;
    }
};

