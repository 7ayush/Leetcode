// A - 1 Z-26 
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0)
        {
            int x=columnNumber%26-1;
            if(x==-1){
                x=25;
                columnNumber--;
            }
            char c='A'+x;
            ans+=c;
            columnNumber=columnNumber/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
